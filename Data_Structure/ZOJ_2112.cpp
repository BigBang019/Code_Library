#include<bits/stdc++.h>
using namespace std;
const int N = 6e4 + 5;
const int M = 1e4 + 5;
typedef long long ll;
struct Q{
	int l, r, k;
	Q(){}
	Q(int l, int r, int k) : l(l), r(r), k(k){}
} qu[M];
int a[N], b[N];

int tr[N], lc[N * 80], rc[N * 80], sum[N * 80];
int lt[N], rt[N], cnt1, cnt2;
int cnt, tot;
int n, m;
void init(){
	cnt = 0;
	tot = 0;
	memset(tr, 0, sizeof(tr));
	memset(sum, 0, sizeof(sum));
	memset(rc, 0, sizeof(rc));
	memset(lc, 0, sizeof(lc));
}
int lowbit(int x) { return x & (-x); }
void build(int &rt,int l,int r){
	rt = ++tot;
	sum[rt] = 0;
	if (l==r)
		return;
	int mid = l + r >> 1;
	build(lc[rt], l, mid);
	build(rc[rt], mid + 1, r);
}
void update(int &rt,int l,int r,int p,int v){
	if (!rt)
		rt = ++tot;
	sum[rt] += v;
	if (l==r)
		return;
	int mid = l + r >> 1;
	if (p<=mid)
		update(lc[rt], l, mid, p, v);
	else
		update(rc[rt], mid + 1, r, p, v);
}
void add(int p,int x,int v){
	for (int i = p; i <= n;i+=lowbit(i))
	{
		update(tr[i], 1, cnt, x, v);
	}
}
int query(int l,int r,int k){
	if (l==r)
		return l;
	int x = 0, mid = l + r >> 1;
	for (int i = 1; i <= cnt1;i++)
		x -= sum[lc[lt[i]]];
	for (int i = 1; i <= cnt2;i++)
		x += sum[lc[rt[i]]];
	if (x>=k){
		for (int i = 1; i <= cnt1;i++)
			lt[i] = lc[lt[i]];
		for (int i = 1; i <= cnt2;i++)
			rt[i] = lc[rt[i]];
		return query(l, mid, k);
	}else{
		for (int i = 1; i <= cnt1;i++)
			lt[i] = rc[lt[i]];
		for (int i = 1; i <= cnt2;i++)
			rt[i] = rc[rt[i]];
		return query(mid + 1, r, k - x);
	}
}
void work(){
	init();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d", &a[i]);
		b[++cnt] = a[i];
	}
	for (int i = 1; i <= m;i++)
	{
		char ch;
		int l, r, k;
		scanf(" %c%d%d", &ch, &l, &r);
		if (ch=='Q'){
			scanf("%d", &k);
			qu[i] = Q(l, r, k);
		}else{
			b[++cnt] = r;
			qu[i] = Q(l, r, -1);
		}
	}
	sort(b + 1, b + 1 + cnt);
	cnt = unique(b + 1, b + 1 + cnt) - b - 1;
	build(tr[0], 1, cnt);
	for (int i = 1; i <= n;i++)
	{
		int p = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
		a[i] = p;
		add(i, p, 1);
	}
	for (int i = 1; i <= m;i++)
	{
		if (~qu[i].k){//Q
			cnt1 = cnt2 = 0;
			for (int j = qu[i].l - 1; j > 0;j-=lowbit(j))
			{
				lt[++cnt1] = tr[j];
			}
			for (int j = qu[i].r; j > 0;j-=lowbit(j))
			{
				rt[++cnt2] = tr[j];
			}
			printf("%d\n", b[query(1, cnt, qu[i].k)]);
		}else{
			int p = lower_bound(b + 1, b + 1 + cnt, qu[i].r) - b;
			add(qu[i].l, a[qu[i].l], -1);
			add(qu[i].l, p, 1);
			a[qu[i].l] = p;
		}
	}
	cout << endl
		 << tot << endl;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		work();
	}
	return 0;
}
