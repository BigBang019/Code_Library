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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 1e3 + 5;
const ll INF = 1e9 + 7;
ll f[N][N];
ll d[N][N];
ll a[1000010];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n;i++)
    {
        ll x;
        cin >> x;
        if (x)
            a[++tot] = x;
    }
    if (tot>=500){
        cout << "3" << endl;
        return 0;
    }
    for (int i = 1; i <= tot;i++) for (int j = 1; j <= tot;j++){
        f[i][j] = d[i][j] = INF;
    }
    for (int i = 1; i <= tot;i++) for (int j = i + 1; j <= tot;j++) if (a[i]&a[j])
    {
        f[i][j] = f[j][i] = d[i][j] = d[j][i] = 1;
    }
    ll ans = INF;
    for (int k = 1; k <= tot;k++)
    {
        for (int i = 1; i < k;i++)
        {
            for (int j = i+1; j <= k;j++)
            {
                ll tmp = f[i][j] + d[j][k] + d[k][i];
                if (tmp<ans){
                    ans = tmp;
                }
            }
        }
        for (int i = 1; i <= tot;i++)
        {
            for (int j = 1; j <= tot;j++)
            {
                ll tmp = f[j][k] + f[k][i];
                if (tmp<f[i][j]){
                    f[i][j] = f[j][i] = tmp;
                }
            }
        }
    }
    printf("%lld\n", (ans == INF ? -1 : ans));
    return 0;
}
