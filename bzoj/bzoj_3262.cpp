#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct TREAP{
	int v, cnt, sz, ch[2], rnd;
} tr[N * 40];
int root[N], tot;
struct NODE{
	int x, y, z;
	bool operator < (const NODE & b) const {
		return (x == b.x ? (y == b.y ? (z < b.z) : (y < b.y)) : (x < b.x));
	}
	bool operator == (const NODE & b) const {
		return (x == b.x && y == b.y && z == b.z);
	}
} a[N];
int n, m;
int sum[N], ans[N];
void init(){
	tot = 0;
}
void up(int x){
	tr[x].sz = tr[tr[x].ch[0]].sz + tr[tr[x].ch[1]].sz + tr[x].cnt;
}
void rot(int & x,bool f){
	int t = tr[x].ch[f];
	tr[x].ch[f] = tr[t].ch[!f];
	tr[t].ch[!f] = x;
	up(x);
	up(t);
	x = t;
}
void insert(int &x,int v){
	if (!x){
		x = ++tot;
		tr[x].rnd = rand();
		tr[x].v = v;
		tr[x].cnt = tr[x].sz = 1;
		return;
	}
	tr[x].sz++;
	if (tr[x].v==v){
		tr[x].cnt++;
		return;
	}
	bool f = v > tr[x].v;
	insert(tr[x].ch[f], v);
	if (tr[tr[x].ch[f]].rnd<tr[x].rnd)
		rot(x, f);
}
int getRank(int x,int v){
	if (!x)
		return 0;
	if (tr[x].v==v)
		return tr[tr[x].ch[0]].sz + tr[x].cnt;
	if (tr[x].v>v)
		return getRank(tr[x].ch[0], v);
	else
		return getRank(tr[x].ch[1], v) + tr[x].cnt + tr[tr[x].ch[0]].sz;
}
int lowbit(int x){
	return x & (-x);
}
void update(int x,int p){
	for (int i = x; i <= m; i += lowbit(i))
		insert(root[i], p);
}
int query(int x,int p){
	int sum = 0;
	for (int i = x; i; i -= lowbit(i))
		sum += getRank(root[i], p);
	return sum;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n;i++)
	{
		if (a[i]==a[i+1])
			sum[i + 1] = sum[i] + 1;
		else{
			int tmp = query(a[i].y, a[i].z);
			ans[tmp] += sum[i] + 1;
		}
		update(a[i].y, a[i].z);
	}
	for (int i = 0; i < n;i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
