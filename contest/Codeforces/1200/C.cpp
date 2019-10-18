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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll d = gcd(n, m);
    ll div1 = n / d;
    ll div2 = m / d;
    while (q--){
        ll x2, y2, x1, y1;
        cin >> x1 >> y1 >> x2 >> y2;
        ll id1, id2;
        bool fl = 0;
        if (x1==1 && x2==1){
            id1 = (y1 - 1) / div1;
            id2 = (y2 - 1) / div1;
        }else if (x1==1 && x2==2){
            id1 = (y1 - 1) / div1;
            id2 = (y2 - 1) / div2;
            
        }else if (x1==2 && x2==1){
            id1 = (y1 - 1) / div2;
            id2 = (y2 - 1) / div1;
        }else{
            id1 = (y1 - 1) / div2;
            id2 = (y2 - 1) / div2;
        }
        fl = (id1 == id2);
        cout << (fl ? "YES" : "NO") << endl;
    }
    return 0;
}
