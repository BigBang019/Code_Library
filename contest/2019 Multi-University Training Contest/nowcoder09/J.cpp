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
const int N = 4e5 + 5;
const int MOD = 1e9 + 7;
const int R = 100000;

using pdd = pair<double, double>;
vector<double> b;
pdd a[N];
ll sum = 0;
int d[N];
int has(double x){
    return lower_bound(ALL(b), x) - b.begin() + 1;
}
int main(){
    int n;
    scanf("%d", &n);
    FOR(i,n){
        int l, r;
        scanf("%d%d", &l, &r);
        sum += r - l;
        a[i] = mp(l, r);
        b.pb(l);
        b.pb((l + r) * 1.0 / 2);
        b.pb(r);
    }
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    FOR(i,n){
        double l = a[i].fi, r = a[i].sc;
        double mid = (l + r) / 2;
        d[has(l)] += -2;
        d[has(mid)] += 4;
        d[has(r)] += -2;
    }
    ll ans = sum;
    ll mul = 0;
    ll now = sum;
    FOR(i,SZ(b)){
        now += mul * (i == 0 ? 0 : b[i] - b[i - 1]);
        ans = min(now, ans);
        mul += d[i + 1];
    }
    printf("%lld\n", sum - ans);
    return 0;
}
