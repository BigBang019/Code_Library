// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((ll)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (ll I = 0; I < (N); ++I)
#define FORD(I, N) for (ll I = N; ~I; --I)
#define REP(I, A, B) for (ll I = A; I <= (B); ++I)
#define REPD(I, B, A) for (ll I = B; I >= A; --I)
#define FORS(I, S) for (ll I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef pair<ll, ll> pl;
const ll N = 5e6 + 5;

ll R = 0;
struct NODE{
    ll x[10];
    ll cnt;
    ll &operator [] (ull i){
        return x[i];
    }
    bool operator < (const NODE & b) const {
        return cnt < b.cnt;
    }
    bool operator > (const NODE & b) const {
        return b < (*this);
    }
} X[N], Y[N];
ll tot;
ll x[N], y[N];
map<ll, ll> fn;
  
ll n, r;
int main(){
    scanf("%lld%lld", &n, &r);
    for (ll i = 1; i <= n;++i){
        ll x0, y0;
        scanf("%lld%lld", &x0, &y0);
        R = max(R, max(x0, y0));
        x[x0]++;
        y[y0]++;
        fn[x0 * ll(1e9) + y0]++;
    }
    for (ll i = 0; i <= R;++i)
    {
        ++tot;
        X[tot][0] = i, X[tot][1] = i + r, X[tot][2] = i + 2 * r, X[tot].cnt = x[i] + x[i + r] + x[i + 2 * r];
        Y[tot][0] = i, Y[tot][1] = i + r, Y[tot][2] = i + 2 * r, Y[tot].cnt = y[i] + y[i + r] + y[i + 2 * r];
    }
    sort(X + 1, X + 1 + tot, [](NODE a, NODE b) {
        return a > b;
    });
    sort(Y + 1, Y + 1 + tot, [](NODE a, NODE b) {
        return a > b;
    });
    ll ans = 0;
    for (ll i = 1; i <= tot; ++i)
    {
        ll now = 0;
        ll dif = -1;
        for (ll j = 1; j <= tot; ++j)
        {
            if (j>1){
                if (X[i].cnt+Y[i].cnt<=ans){
                    break;
                }
                // ll nd = Y[1].cnt - Y[j].cnt;
                // if (~dif && nd>=dif)
                //     break;
            }
  
            now = X[i].cnt + Y[j].cnt;
  
            ll nd = 0;
            FOR(k,3) FOR(l,3){
                auto it = fn.find(X[i][k] * ll(1e9) + Y[j][l]);
                // cout << X[i][k] << " " << Y[j][l] << " ";
                if (it!=fn.end()){
                    // cout << it->sc << endl;
                    nd += it->sc;
                }
                // cout << endl;
            }
            if (now-nd>=ans){
                dif = ~dif ? min(nd, dif) : nd;
                ans = now - nd;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
