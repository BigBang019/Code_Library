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
const int N = 3e2 + 5;
 
ll a[N];
 
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    int t;
    cin >> t;
    while (t--){
        int n;
        ll m, k;
        cin >> n >> m >> k;
        REP(i,1,n){
            cin >> a[i];
        }
        bool fl = 1;
        REP(i,1,n-1){
            ll tmp = a[i] - max(0ll, a[i + 1] - k);
            m += tmp;
            if (m<0) {
                fl = 0;
                break;
            }
        }
        cout << (fl ? "YES" : "NO") << endl;
    }
 
    return 0;
}
