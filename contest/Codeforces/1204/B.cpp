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
const int MOD = 1e9 + 7;
int n, l, r;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    ll mx = 0, mn = 0;
    for (int i = 0; i < r;i++)
    {
        mx += (1ll << i);
    }
    mx += 1ll * (n - r) * (1ll << (r - 1));
    for (int i = 0; i < l;i++)
    {
        mn += (1ll << i);
    }
    mn += (n - l);
    cout << mn << " " << mx << endl;
    return 0;
}
