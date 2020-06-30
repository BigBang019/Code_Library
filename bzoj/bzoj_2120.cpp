#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;

struct Q{
	int l, r, t, p;
	Q(){}
	Q(int l,int r,int t,int p):l(l),r(r),t(t),p(p){}
} query[N];
struct C{
	int p, v, last;
	C(){}
	C(int p,int v,int last):p(p),v(v),last(last){}
} change[N];
int cntc, cntq;
int ans[N], now[N], vis[N * 100], S, n, m;
int l, r, cur, ti;
int a[N];
bool cmp(Q a, Q b){
	if (a.l/S==b.l/S)
		if (a.r/S==b.r/S)
			return a.t < b.t;
		else
			return a.r / S < b.r / S;
	else
		return a.l / S < b.l / S;
}
void moveTime(int id,int v){
	int pos = change[id].p;
	if (~v){//v=1
		if (l<=pos && pos<=r){
			if (vis[a[pos]]==1)
				cur--;
			if (!vis[change[id].v])
				cur++;
			vis[a[pos]]--;
			vis[change[id].v]++;
		}
			
		a[pos] = change[id].v;
	}else{
		if (l<=pos && pos<=r){
			if (vis[a[pos]]==1)
				cur--;
			if (!vis[change[id].last])
				cur++;
			vis[a[pos]]--;
			vis[change[id].last]++;
		}
		a[pos] = change[id].last;
	}
}
void move(int pos,int v){
	if (~v && !vis[a[pos]]){
		cur++;
	}
	if (v==-1 && vis[a[pos]]==1){
		cur--;
	}
	vis[a[pos]] += v;
}
int main(){
	scanf("%d%d", &n, &m);
	S = sqrt(n);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d", &a[i]);
		now[i] = a[i];
	}
	for (int i = 0; i < m;i++)
	{
		char ch;
		int x, y;
		scanf(" %c%d%d", &ch, &x, &y);
		if (ch=='Q'){
			query[cntq++] = Q(x, y, cntc, cntq);
		}else{
			change[++cntc] = C(x, y, now[x]);
			now[x] = y;
		}
	}
	sort(query, query + cntq, cmp);
	l = 1, r = 0;
	cur = 0;
	ti = 0;
	for (int i = 0; i < cntq;i++)
	{
		while(ti<query[i].t)
			moveTime(++ti, 1);
		while (ti>query[i].t)
			moveTime(ti--, -1);
		while (l<query[i].l)
			move(l++, -1);
		while (l>query[i].l)
			move(--l, 1);
		while (r<query[i].r)
			move(++r, 1);
		while (r>query[i].r)
			move(r--, -1);
		ans[query[i].p] = cur;
	}
	for (int i = 0; i < cntq;i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
