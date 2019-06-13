#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m;
int a[N], b[N];
pair<int, int> c[N];
ll tree[N * 4];
ll lazy[N * 4];
ll maxi[N * 4];
void up(int x){
	tree[x] = tree[2 * x] + tree[2 * x + 1];
	maxi[x] = max(maxi[2 * x], maxi[2 * x + 1]);
}
void pushdown(int x,int l,int r){
	if (lazy[x]==-1)
		return;
	int mid = l + r >> 1;
	tree[2 * x] = lazy[x] * (mid - l + 1);
	tree[2 * x + 1] = lazy[x] * (r - mid);
	maxi[2 * x] = lazy[x];
	maxi[2 * x + 1] = lazy[x];
	lazy[2 * x] = lazy[x];
	lazy[2 * x + 1] = lazy[x];
	lazy[x] = -1;
}
void update(int x,int l,int r,int ql,int qr,ll v){
	if (ql>r || qr<l)
		return;
	int mid = l + r >> 1;
	if (ql<=l && qr>=r){
		tree[x] = v * (r - l + 1);
		maxi[x] = v;
		lazy[x] = v;
		return;
	}
	pushdown(x, l, r);
	update(2 * x, l, mid, ql, qr, v);
	update(2 * x + 1, mid + 1, r, ql, qr, v);
	up(x);
}
ll query(int x,int l,int r,int ql,int qr){
	if (ql > r || qr < l)
		return 0;
	int mid = l + r >> 1;
	if (ql<=l && qr>=r){
		return tree[x];
	}
	pushdown(x, l, r);
	return query(2 * x, l, mid, ql, qr) + query(2 * x + 1, mid + 1, r, ql, qr);
}
int queryMax(int x,int l,int r,int ql,int qr,int v){
	if (l==r){
		return l;
	}
	int mid = l + r >> 1;
	pushdown(x, l, r);
	if (ql<=mid && maxi[2*x]>=v){
		int tmp=queryMax(2 * x, l, mid, ql, qr, v);
		if (tmp!=n+1)
			return tmp;
		else if (maxi[2*x+1]>=v)
			return queryMax(2 * x + 1, mid + 1, r, ql, qr, v);
		else
			return n + 1;
	}
	else if (maxi[2*x+1]>=v)
		return queryMax(2 * x + 1, mid + 1, r, ql, qr, v);
	else
		return n + 1;
}
void build(int x,int l,int r){
	lazy[x] = -1;
	if (l==r){
		maxi[x] = tree[x] = b[l];
		return;
	}
	int mid = l + r >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	up(x);
}
int main(){
	while (~scanf("%d",&n) && n)
	{
		map<int, int> m;
		for (int i = 1; i <= n;i++)
		{
			scanf("%d",&a[i]);
			m[a[i]]++;
			c[i] = make_pair(a[i], i);
		}
		sort(c + 1, c + 1 + n);
		int low = -1;
		for (int i = 0; low==-1;i++)
			if (m.count(i)==0)
				low = i;
		for (int i = n; i;i--)
		{
			b[i] = low;
			m[a[i]]--;
			// cout << a[i] << " " << m[a[i]] << endl;
			if (a[i]<low && m[a[i]]==0)
				low = a[i];
		}
		build(1, 1, n);
		ll ans = query(1, 1, n, 1, n);
		for (int i = 1; i < n;i++)
		{	//当前要消除a[i]的影响
			int l = queryMax(1, 1, n, i + 1, n, a[i]);
			int id = lower_bound(c + 1, c + 1 + n, make_pair(a[i], i + 1)) - c;
			int r = c[id].first != a[i] || id > n ? n : c[id].second - 1;
			if (l<=r){
				update(1, 1, n, l, r, a[i]);
			}
			ans += query(1, 1, n, i + 1, n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
