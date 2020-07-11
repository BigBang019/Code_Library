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
int main(){
    int hi = 0;
    int lo = 0;
    printf("? ");
    int now = 0;
    for (int i = 1; i <= 100;i++)
    {
        printf("%d%c", now++, i == 100 ? '\n' : ' ');
    }
    fflush(stdout);
    scanf("%d", &hi);
    hi >>= 7;
    now = 128;
    printf("? ");
    for (int i = 1; i <= 100;i++)
    {
        printf("%d%c", now, i == 100 ? '\n' : ' ');
        now += 128;
    }
    fflush(stdout);
    scanf("%d", &lo);
    lo %= 128;
    printf("! %d\n", (hi << 7) + lo);
 
    return 0;
}
