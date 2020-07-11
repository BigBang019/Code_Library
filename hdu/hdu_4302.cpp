#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N = 1e5 + 5;
int flag = 0;
int len, n;

struct NODE{
	int l, r, v, le, re;
	NODE(){}
	NODE(int l, int r, int v, int le, int re) : l(l), r(r), v(v), le(le), re(re){}
} tree[N * 4];

void up(int x){
	tree[x].v = tree[2 * x].v + tree[2 * x + 1].v;
	tree[x].le = tree[2 * x].v ? tree[2 * x].le : tree[2 * x + 1].le;
	tree[x].re = tree[2 * x + 1].v ? tree[2 * x + 1].re : tree[2 * x].re;
}

void build(int x,int l,int r){
	tree[x] = NODE(l, r, 0, 0, 0);
	if (l==r){
		return;
	}
	int mid = l + r >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
}
int query(int x,int p){
	if (tree[x].l==tree[x].r){
		return tree[x].l;
	}
	int d1 = abs(tree[2*x].re - p);
	int d2 = abs(tree[2 * x + 1].le - p);
	if (tree[2*x].v){
		if (tree[2*x+1].v==0)
			return query(2 * x, p);
		if (d2>d1)
			return query(2 * x, p);
		else if (d2==d1)
			return ~flag ? query(2 * x + 1, p) : query(2 * x, p);
		else
			return query(2 * x + 1, p);
	}else if (tree[2*x+1].v)
		return query(2 * x + 1, p);
	else
		return -1;
}
void update(int x,int p,int v){
	if (tree[x].l==tree[x].r){
		tree[x].v += v;
		tree[x].le = tree[x].re = tree[x].l;
		return;
	}
	if (p<=tree[2*x].r)
		update(2 * x, p, v);
	else
		update(2 * x + 1, p, v);
	up(x);
}
void work(int cas){
	scanf("%d%d", &len, &n);
	build(1, 0, len);
	int pos = 0, last = 0;
	ll ans = 0;
	for (int i = 1; i <= n;i++)
	{
		int x;
		scanf("%d", &x);
		if (x){
			int pos = query(1, last);
			if (pos==-1)
				continue;
			ans += (ll)abs(pos - last);
			update(1, pos, -1);
			flag = pos == last ? flag : (pos > last ? 1 : -1);
			last = pos;
		}else{
			scanf("%d", &x);
			update(1, x, 1);
		}
	}
	printf("Case %d: %lld\n", cas, ans);
}
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t;i++)
	{
		work(i);
	}
	return 0;
}
