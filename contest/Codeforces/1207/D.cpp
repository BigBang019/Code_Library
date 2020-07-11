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
const int N = 3e5 + 5;
const int MOD = 998244353;
int n;
pi a[N];
ll A[N];
map<int, int> f1, f2;
map<pi, int> fn;
int main(){
    scanf("%d", &n);
    A[1] = 1;
    for (int i = 2; i <= n;i++)
    {
        A[i] = A[i - 1] * i % MOD;
    }
    ll ans = A[n];
    for (int i = 1; i <= n;i++)
    {
        scanf("%d%d", &a[i].fi, &a[i].sc);
        f1[a[i].fi]++;
        f2[a[i].sc]++;
        fn[mp(a[i].fi, a[i].sc)]++;
    }
    ll dec = 1;
    for (auto it = f1.begin(); it != f1.end();it++)
    {
        dec = dec * A[it->sc] % MOD;
    }
    ans = (ans - dec + MOD) % MOD;
    dec = 1;
    for (auto it = f2.begin(); it != f2.end(); it++)
    {
        dec = dec * A[it->sc] % MOD;
    }
    ans = (ans - dec + MOD) % MOD;
 
    bool fl = 1;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++)
    {
        if (a[i].sc<a[i-1].sc){
            fl = 0;
            break;
        }
    }
    if (fl){
        ll dec = 1;
        for (auto it = fn.begin(); it != fn.end();it++)
        {
            dec = dec * A[it->sc] % MOD;
        }
        ans = (ans + dec) % MOD;
    }
    printf("%lld\n", ans);
 
    return 0;
}
