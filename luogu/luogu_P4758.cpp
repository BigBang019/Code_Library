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
const int N = 1e5 + 5;
const ll R = 1e17;

struct Point{
	ll x, y;
	Point(){}
	Point(ll x, ll y) : x(x), y(y){}
	Point operator + (const Point& b) const {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point& b) const {
		return Point(x - b.x, y - b.y);
	}
	ll operator * (const Point& b) const {
		return x * b.y - b.x * y;
	}
};
struct Convex{
	vector<Point> st;
	Convex() { st.clear(); }
	static ll cross_product(const Point& p2,const Point& p0,const Point& p1){
		return (p2 - p0) * (p1 - p0);
	}
	void insert(const Point& a){
		int sz = st.size();
		while (sz > 1 && cross_product(a, st[sz - 2], st[sz - 1]) <= 0)
		{
			st.pop_back();
			--sz;
		}
		st.push_back(a);
	}
	bool query(const Point& a,const Point& b){
		int l = 0, r = int(st.size()) - 2;
		while (l<r){
			int mid = l + r >> 1;
			if (cross_product(st[mid], a, b) < cross_product(st[mid+1], a, b)){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		return cross_product(st[l], a, b) < 0 || cross_product(st[l + 1], a, b) < 0;
	}
};
Convex tree[N << 2];
Point p[N];
void build(int x,int l,int r){
	tree[x] = Convex();
	REP(i, l, r + 1) tree[x].insert(p[i]);
	if (l==r) return;
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
}
int query(int x,int l,int r,int ql,int qr,const Point& a,const Point& b){
	if (l>qr || r<ql ||l>r)
		return 0;
	if (ql<=l && qr>=r){
		if (!tree[x].query(a,b))
			return 0;
		if (l==r)
			return l;
	}
	int mid = l + r >> 1;
	int res = query(x << 1, l, mid, ql, qr, a, b);
	return res ? res : query(x << 1 | 1, mid + 1, r, ql, qr, a, b);
}
int main(){
	int _;
	for (scanf("%d", &_); _;_--)
	{
		int n;
		scanf("%d", &n);
		REP(i,1,n) scanf("%lld%lld", &p[i].x, &p[i].y);
		build(1, 1, n - 1);
		REP(i, 1, n - 2){
			printf("%d ", query(1, 1, n - 1, i + 1, n - 1, p[i], p[i + 1]));
		}
		puts("0");
	}
	return 0;
}
