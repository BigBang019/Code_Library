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
const ll N = 1e6 + 5;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    int tot = 0, tot0 = 0;
    ll ans = 0;
    cin >> n;
    FOR(i,n){
        int x;
        cin >> x;
        if (x<0){
            ans += abs(x + 1);
            tot++;
        }else if (x>0){
            ans += abs(x - 1);
        }else {
            tot0++;
            ans += 1;
        }
    }
    if (tot&1 && !tot0){
        ans += 2;
    }
    printf("%lld\n", ans);
    return 0;
}
