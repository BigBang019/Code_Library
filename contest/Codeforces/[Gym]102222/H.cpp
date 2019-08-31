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
 
struct NODE{
    ll h, t;
    double cm;
    bool operator > (const NODE &b) const {
        return cm > b.cm;
    }
} a[N];
int n;
main()
{
    int _, cas = 0;
    for (scanf("%d", &_); _; --_)
    {
        scanf("%d", &n);
        REP(i,1,n){
            scanf("%lld%lld", &a[i].h, &a[i].t);
            ll l = 1, r = ll(1e3), mid, res;
            while (l<=r){
                mid = l + r >> 1;
                if (mid * (mid + 1) / 2 >= a[i].h)
                    r = (res = mid) - 1;
                else
                    l = mid + 1;
            }
            a[i].h = res;
            a[i].cm = a[i].t * 1.0 / a[i].h;
        }
        sort(a + 1, a + 1 + n, [](NODE a, NODE b) {
            return a > b;
        });
        ll now = 0;
        ll ans = 0;
        REP(i,1,n){
            now += a[i].h;
            ans += now * a[i].t;
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
