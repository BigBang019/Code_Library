// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORD(I, N) for (int I = N; ~I; --I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, B, A) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 2e5 + 5;
const ll R = 1e17;

int n;
ll s[N];
int a[N];
ll tree[N << 2], lazy[N << 2];

void pushdown(int x){
	if (!lazy[x])
		return;
	tree[x << 1] += lazy[x];
	tree[x << 1 | 1] += lazy[x];
	lazy[x << 1] += lazy[x];
	lazy[x << 1 | 1] += lazy[x];
	lazy[x] = 0;
}
void build(int x,int l,int r){
	if (l==r){
		tree[x] = s[l];
		return;
	}
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	tree[x] = min(tree[x << 1], tree[x << 1 | 1]);
}
void update(int x,int l,int r,int ql,int qr,ll v){
	if (l>r || l>qr || r<ql)
		return;
	if (ql<=l && qr>=r){
		tree[x] += v;
		lazy[x] += v;
		return;
	}
	int mid = l + r >> 1;
	pushdown(x);
	update(x << 1, l, mid, ql, qr, v);
	update(x << 1 | 1, mid + 1, r, ql, qr, v);
	tree[x] = min(tree[x << 1], tree[x << 1 | 1]);
}
int query(int x,int l,int r){
	if (l==r){
		return l;
	}
	int mid = l + r >> 1;
	pushdown(x);
	if (tree[x << 1 | 1] == 0)
		return query(x << 1 | 1, mid + 1, r);
	else
		return query(x << 1, l, mid);
}

int main(){
	scanf("%d", &n);
	REP(i,1,n){
		scanf("%lld", s + i);
	}
	build(1, 1, n);
	REP(i,1,n){
		int pos = query(1, 1, n);
		a[pos] = i;
		update(1, 1, n, pos, pos, R);
		update(1, 1, n, pos + 1, n, -i);
	}
	REP(i,1,n){
		printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}
