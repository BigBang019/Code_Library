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
ll a, b;
int n;
char s[N];
ll f[N][2];
int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d%lld%lld", &n, &a, &b);
        scanf(" %s", s + 1);
        s[0] = '0';
        memset(f, -1, sizeof(f));
        ll ans = 1ll * n * a;
        f[0][0] = b;
        f[0][1] = -1;
        for (int i = 1; i <= n;i++)
        {
            if (s[i]=='1'){
                f[i][0] = -1;
 
                if (~f[i - 1][1])
                    f[i][1] = (f[i][1] == -1 ? f[i - 1][1] + 2 * b : min(f[i][1], f[i - 1][1] + 2 * b));
 
                // if (s[i - 1] == '0' && ~f[i - 1][0])
                //     f[i][1] = (f[i][1] == -1 ? f[i - 1][0] + a + 2 * b : min(f[i][1], f[i - 1][0] + a + 2 * b));
            }else{
                if (~f[i - 1][0] && s[i - 1] == '0')
                    f[i][1] = (f[i][1] == -1 ? f[i - 1][0] + a + 2 * b : min(f[i][1], f[i - 1][0] + a + 2 * b));
 
                if (~f[i - 1][1])
                    f[i][1] = (f[i][1] == -1 ? f[i - 1][1] + 2 * b : min(f[i][1], f[i - 1][1] + 2 * b));
 
                if (~f[i - 1][0] && s[i - 1] == '0')
                    f[i][0] = (f[i][0] == -1 ? f[i - 1][0] + b : min(f[i][0], f[i - 1][0] + b));
 
                if (~f[i - 1][1])
                    f[i][0] = (f[i][0] == -1 ? f[i - 1][1] + a + b : min(f[i][0], f[i - 1][1] + a + b));
            }
        }
        printf("%lld\n", n * a + f[n][0]);
    }
    return 0;
}
