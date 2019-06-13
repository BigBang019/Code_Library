#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
int tree[N * 4], lazy[N * 4];
int n, m;

void up(int x){
	tree[x] = tree[2 * x] + tree[2 * x + 1];
}
void pushdown(int x,int l,int r){
	if (lazy[x]==-1)
		return;
	int mid = l + r >> 1;
	tree[2 * x] = lazy[x] * (mid - l + 1);
	tree[2 * x + 1] = lazy[x] * (r - mid);
	lazy[2 * x] = lazy[x];
	lazy[2 * x + 1] = lazy[x];
	lazy[x] = -1;
}
void build(int x,int l,int r){
	lazy[x] = -1;
	if (l==r){
		tree[x] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	up(x);
}
void update(int x,int l,int r,int ql,int qr,int v){
	if (ql>r || qr<l)
		return;
	int mid = l + r >> 1;
	if (ql<=l && qr>=r){
		tree[x] = (r - l + 1) * v;
		lazy[x] = v;
		return;
	}
	pushdown(x, l, r);
	update(2 * x, l, mid, ql, qr, v);
	update(2 * x + 1, mid + 1, r, ql, qr, v);
	up(x);
}
int query(int x,int l,int r,int ql,int qr){
	if (ql>r || qr<l || ql>qr)
		return 0;
	int mid = l + r >> 1;
	if (ql<=l && qr>=r){
		return tree[x];
	}
	pushdown(x, l, r);
	return query(2 * x, l, mid, ql, qr) + query(2 * x + 1, mid + 1, r, ql, qr);
}
int queryS(int x,int l,int r,int ql,int qr){
	if (l==r){
		return l;
	}
	int mid = l + r >> 1;
	pushdown(x, l, r);
	int tmp = -1;
	if (ql <= mid && tree[2 * x] < (mid - l + 1))
	{
		tmp = queryS(2 * x, l, mid, ql, qr);
		if (tmp!=-1)
			return tmp;
		else if (tree[2*x+1]<(r-mid))
			return queryS(2 * x + 1, mid + 1, r, ql, qr);
		else
			return -1;
	}else if (tree[2*x+1]<(r-mid))
		return queryS(2 * x + 1, mid + 1, r, ql, qr);
	else
		return -1;
}
int queryE(int x,int l,int r,int ql,int qr,int k){
	if (l==r){
		return l;
	}
	int mid = l + r >> 1;
	pushdown(x, l, r);
	int l0 = ql <= mid ? mid - ql + 1 - query(2 * x, l, mid, ql, qr) : 0;
	int r0 = qr > mid ? qr - mid - query(2 * x + 1, mid + 1, r, ql, qr) : 0;
	if (k>l0){
		if (r0==0)
			return queryE(2 * x, l, mid, ql, min(qr, mid), k);
		else
			return queryE(2 * x + 1, mid + 1, r, max(mid + 1, ql), qr, k - l0);
	}else
		return queryE(2 * x, l, mid, ql, min(qr, mid), k);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		for (int i = 0; i < m;i++)
		{
			int k, x, y;
			scanf("%d%d%d", &k, &x, &y);
			x++;
			if (k==1){
				int tmp = query(1, 1, n, x, n);
				if (tmp==n-x+1)
					printf("Can not put any one.\n");
				else {
					int ed = queryE(1, 1, n, x, n, y);
					int st = queryS(1, 1, n, x, n);
					update(1, 1, n, st, ed, 1);
					printf("%d %d\n", st - 1, ed - 1);
				}
			}else{
				y++;
				int tmp = query(1, 1, n, x, y);
				printf("%d\n", tmp);
				update(1, 1, n, x, y, 0);
			}
		}
		printf("\n");
	}
	return 0;
}
