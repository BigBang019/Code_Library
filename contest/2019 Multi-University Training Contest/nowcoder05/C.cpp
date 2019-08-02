/***********************************************
  BSGS
  Author: IceRuler
***********************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
using namespace std;
using ll = long long;
const ll maxn = 1e6;
ll mod;
  
ll bin(ll x, ll n, ll MOD)
{
    ll ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1)
            ret = ret * x % MOD;
    return ret;
}
inline ll get_inv(ll x, ll p) { return bin(x, p - 2, p); }
  
unordered_map<ll, ll> mp;
ll m, ma;
ll init(ll a, ll p)
{
    mp.clear();
    ll v = 1;
    // m = pow(p + 1.5, 2.0 / 3.0);
    // ma = pow(p + 1.5, 1.0 / 3.0);
    FOR(i, 1, m + 1)
    {
        v = v * a % p;
        mp[v] = i;
    }
    return v;
}
  
ll BSGS(ll a, ll b, ll p, ll init_d)
{ // a^x = b (mod p)
    // a %= p;
    // if (!a && !b)
    //     return 1;
    // if (!a)
    //     return -1;
    // ll m = p / maxn + 3;
    ll v = init_d;
    ll vv = init_d;
    ll inv_b = get_inv(b, p);
  
    FOR(i, 1, ma + 1)
    {
        auto it = mp.find(vv * inv_b % p);
        if (it != mp.end())
            return i * m - it->second;
        vv = vv * v % p;
    }
    return -1;
}
  
int main()
{
    ios::sync_with_stdio(false);
    int round;
    cin >> round;
    while (round--)
    {
        ll n, x0, a, b, p;
        int Q;
        cin >> n >> x0 >> a >> b >> p;
        cin >> Q;
        if (a == 0)
        {
            while (Q--)
            {
                ll v;
                cin >> v;
                if (v == x0)
                {
                    cout << 0 << endl;
                }
                else if (v == b)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
        else if (a == 1)
        {
            ll invb = get_inv(b, p);
            while (Q--)
            {
                ll v;
                cin >> v;
                ll ans = (((v - x0 + p) % p) * invb) % p;
                if (ans >= n)
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
        }
        else
        {
            ll bais = b * get_inv(a - 1, p) % p;
            ll y0 = (x0 + bais) % p;
            ll inv_y0 = get_inv(y0, p);
            m = min(maxn, n);
            ma = p / maxn + 3;
            ll init_d = init(a, p);
            while (Q--)
            {
                ll v;
                cin >> v;
                v = (v + bais) % p;
                v = (v * inv_y0) % p;
                ll res = BSGS(a, v, p, init_d);
                if (res >= n)
                    res = -1;
                cout << res << endl;
            }
        }
    }
}
