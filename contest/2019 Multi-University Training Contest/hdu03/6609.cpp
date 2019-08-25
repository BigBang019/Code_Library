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
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
vector<ll> b;
ll sum[N << 2];
int cnt[N << 2];

int has(int x){
	return lower_bound(ALL(b), x) - b.begin() + 1;
}
void update(int x,int l,int r,int p){
	sum[x] += b[p - 1];
	++cnt[x];
	if (l==r) return;
	int mid = l + r >> 1;
	if (p<=mid)
		update(x << 1, l, mid, p);
	else
		update(x << 1 | 1, mid + 1, r, p);
}
int query(int x,int l,int r,int k){
	if (l==r){
		return min(1ll*cnt[x], k / b[l - 1]);
	}
	int mid = l + r >> 1;
	if (sum[x<<1]<=k)
		return cnt[x << 1] + query(x << 1 | 1, mid + 1, r, k - sum[x << 1]);
	else
		return query(x << 1, l, mid, k);
}
int main(){
	int _;
	for (scanf("%d", &_); _;_--)
	{
		int n, m;
		memset(cnt, 0, sizeof(cnt));
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &n, &m);
		REP(i,1,n){
			scanf("%lld", a + i);
			b.pb(a[i]);
		}
		sort(ALL(b));
		b.erase(unique(ALL(b)), b.end());
		int len = b.size();
		REP(i,1,n){
			int p = has(a[i]);
			printf("%d ", i - 1 - query(1, 1, len, m - a[i]));
			update(1, 1, len, p);
		}
		puts("");
	}
	return 0;
}
