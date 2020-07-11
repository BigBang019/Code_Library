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

unordered_map<int, int> fn1, fn2;
unordered_map<int, char> bel;
pi a[N];
int tot;
ull k1, k2, MOD;
ull rng() {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        fn1.clear();
        fn2.clear();
        bel.clear();
        tot = 0;
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        int ans[2] = {0, 0};
        if (p==1){
            FOR(i,n) {
                int x;
                scanf("%d",&x);
                ++fn1[x];
            }
            FOR(i,m){
                int x;
                scanf("%d", &x);
                ++fn2[x];
            }
        }else{
            scanf("%llu%llu%d", &k1, &k2, &MOD);
            FOR(i,n){
                ull x = rng()%MOD;
                ++fn1[x];
            }
            scanf("%llu%llu%d", &k1, &k2, &MOD);
            FOR(i,m){
                ull x = rng() % MOD;
                ++fn2[x];
            }
        }
        for (auto it = fn1.begin(); it != fn1.end();it++){
            auto it2 = fn2.find(it->first);
            if (it2==fn2.end()) continue;
            a[tot++] = mp(it->sc + it2->sc, it->fi);
        }
        sort(a, a + tot, [](pi a, pi b) {
            return a > b;
        });
        FOR(i,tot){
            bel[a[i].sc] = (i & 1) + '0';
        }
        for (auto it = fn1.begin();it!=fn1.end();it++){
            auto it2 = bel.find(it->first);
            if (it2!=bel.end() && it2->second=='1') continue;
            ans[0] += it->second;
        }
        for (auto it = fn2.begin();it!=fn2.end();it++){
            auto it2 = bel.find(it->first);
            if (it2!=bel.end() && it2->second=='0') continue;
            ans[1] += it->second;
        }
        printf("%s\n", ans[0] > ans[1] ? "Cuber QQ" : "Quber CC");
    }
    return 0;
}
