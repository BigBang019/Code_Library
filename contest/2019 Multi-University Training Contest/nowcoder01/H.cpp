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
const int MOD = 1e9 + 7;

struct LB{
	ll b[64];
	void init(){
		memset(b, 0, sizeof(b));
	}
	bool update(ll x){
		for (int i = 63; i >= 0;i--) if (x>>i&1)
		{
			if (!b[i]){
				b[i] = x;
				return 1;
			}
			x ^= b[i];
		}
		return 0;
	}
} t1, t2, t3;
ll ans = 0;
ll a[N], b[N], c[N];
ll po[N];
int main(){
	po[0] = 1;
	REP(i, 1, N - 5) po[i] = po[i - 1] * 2 % MOD;
	int n, r;
	while (~scanf("%d", &n))
	{
		r = ans = 0;
		t1.init(), t2.init(), t3.init();
		REP(i,1,n){
			scanf("%lld", a + i);
			if (t1.update(a[i])){
				c[++r] = a[i];
			}else{
				b[++ans] = a[i];
			}
		}
		if (r==n){
			puts("0");
			continue;
		}
		REP(i,1,ans){
			t2.update(b[i]);
		}
		REP(i,1,r){
			t3 = t2;
			REP(j, 1, r) if (i!=j) t3.update(c[j]);
			if (!t3.update(c[i])) ++ans;
		}
		printf("%lld\n", ans * po[n - r - 1] % MOD);
	}
	return 0;
}
