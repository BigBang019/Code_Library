// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
const int R = 400;
ll k;
int m;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%lld%d", &k, &m);
        ll ans = -1;
        for (ll n = max(k - R, 1ll); n <= k + R; n++)
        {
            ll x = (n ^ k) + n;
            if (gcd(x,n)!=1)
                continue;
            int tot = 0;
            for (ll j = n + 1; j <= x;j++)
            {
                tot += (gcd(j, n) == 1);
            }
            if (tot==m){
                ans = n;
                break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
