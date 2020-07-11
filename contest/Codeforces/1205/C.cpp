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
const int N = 1e6 + 5;
int a[N];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if ((n&1)==0){
        cout << "NO" << endl;
        return 0;
    }
    int h = 1, t = 2 * n;
    for (int i = 1; i <= n;i++)
    {
        if (i&1){
            // if (i%4==1){
                a[i] = h++;
                a[i + n] = h++;
            // }else{
            //     a[i + n] = h++;
            //     a[i] = h++;
            // }
        }else{
            // if (i%4==2){
                a[i] = t--;
                a[i + n] = t--;
            // }else{
            //     a[i + n] = t--;
            //     a[i] = t--;
            // }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
