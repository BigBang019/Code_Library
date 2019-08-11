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
int vis[10];
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    int n;
    cin >> n;
    FOR (cas,n){
        char x;
        cin >> x;
        if (isdigit(x))
            vis[x - '0'] = 0;
        else if (x=='L'){
            FOR(i,10) if (!vis[i]){
                vis[i] = 1;
                break;
            }
        }else {
            FORD(i,9) if (!vis[i]){
                vis[i] = 1;
                break;
            }
        }
    }
    FOR(i, 10)
    printf("%d", vis[i]);
    return 0;
}
