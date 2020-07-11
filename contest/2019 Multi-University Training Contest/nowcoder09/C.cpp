//高斯二项式系数 规律 结论 OEIS/WIKI
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1000000007;
inline ll pw(ll x, ll y) {
    ll re = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) {
            re = re * x % p;
        }
        x = x * x % p;
    }
    return re;
}
int main() {
    int n, b, x;
    map<int, int> g;
    cin >> n >> b;
    ll z = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        g[x]++;
        if (b == 1) {
            z = z * i % p * pw(g[x], p - 2) % p;
        } else {
            z = z * (1 - pw(b, i)) % p * pw(1 - pw(b, g[x]), p - 2) % p;
        }
    }
    if (z < 0) {
        z += p;
    }
    cout << z << endl;
    return 0;
}
