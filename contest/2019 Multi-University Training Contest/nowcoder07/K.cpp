#include <bits/stdc++.h>
typedef long long ll;
const int N = 50000 << 1 | 1;  // sqrt(n)*2
int n, m, Sqr, pnum, pri[N >> 2], w[N];
ll g[N][4], sp[N][4], G[N];
inline int ID(int x) { return x <= Sqr ? x : m - n / x + 1; }
int F(int p, int k) {
    if (p % 4 == 1) return 3 * k + 1;
    return 1;
}
bool notp[N];
void sieve() {
    memset(notp, 0, sizeof(notp));
    notp[0] = notp[1] = 1;
    pnum = 0;
    for (int i = 2; i < N; i++) {
        if (!notp[i]) {
            pri[++pnum] = i;
            for (int r = 0; r < 4; ++r)
                sp[pnum][r] = sp[pnum - 1][r] + (i % 4 == r);
        }
        for (int j = 1; j <= pnum && pri[j] * i < N; j++) {
            notp[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
void Init(int n) {
    Sqr = sqrt(n);
    m = 0;
    ll j;
    for (ll i = 1; i <= n; i = w[m] + 1ll) {
        w[++m] = n / (n / i);
        for (int r = 0; r < 4; r++) {
            if (r == 0)
                g[m][r] = w[m] / 4;
            else
                g[m][r] = w[m] / 4 + (w[m] % 4 >= r);
            if (r == 1) g[m][r]--;
        }
    }
    for (int i = 1; i <= pnum; ++i) {
        ll lim = 1ll * pri[i] * pri[i];
        for (int j = m; lim <= w[j]; --j) {
            int k = ID(w[j] / pri[i]);
            for (int r = 0; r < 4; ++r) {
                g[j][r * pri[i] % 4] -= g[k][r] - sp[i - 1][r];
            }
        }
    }
    for (int i = 1; i <= m; i++) G[i] = g[i][1] * 4 + g[i][3] + (i > 1);
}
ll S(ll x, int y) {
    if (x <= 1 || pri[y] > x) return 0;
    ll res = G[ID(x)] - G[pri[y - 1]];
    for (int i = y; i <= pnum && 1ll * pri[i] * pri[i] <= x; ++i) {
        for (ll p = pri[i], p1 = p, j = 1; p1 * p <= x; p1 *= p, ++j)
            res += S(x / p1, i + 1) * F(pri[i], j) + F(pri[i], j + 1);
    }
    return res;
}
int T;
int main() {
    sieve();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Init(n);
        printf("%lld\n", S(n, 1) + 1);
    }
    return 0;
}
