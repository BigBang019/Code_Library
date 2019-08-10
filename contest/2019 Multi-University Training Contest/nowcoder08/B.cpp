// #pragma GCC optimize(2)
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
#define FORD(I, N) for (int I = N; I; ++I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, A, B) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
int n;
ll f[N];
int a[N];
int last[N];
ll ans;
int main(){
    scanf("%d", &n);
    REP(i,1,n){
        scanf("%d", &a[i]);
    }
    f[1] = 1;
    last[a[1]] = 1;
    REP(i,2,n){
        f[i] = f[i - 1] + (i - last[a[i]]);
        last[a[i]] = i;
    }
    REP(i,1,n){
        ans += f[i];
    }
    printf("%lld\n", ans);
    return 0;
}
