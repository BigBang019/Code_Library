#include <cmath>
#include <cstdio>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1700010;
int T, tot, prime[maxn], mu[maxn];
map<int, ll> ans_mu;

void sieve()
{
    fill(prime, prime + maxn, 1);
    mu[1] = 1, tot = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i])
        {
            prime[++tot] = i, mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * prime[j] < maxn; j++)
        {
            prime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 2; i < maxn; i++)
        mu[i] += mu[i - 1];
}

ll calc_mu(int x)
{
    if (x < maxn)
        return mu[x];
    if (ans_mu.count(x))
        return ans_mu[x];
    ll ans = 1;
    for (ll i = 2, j; i <= x; i = j + 1)
    {
        j = x / (x / i), ans -= (j - i + 1) * calc_mu(x / i);
    }
    return ans_mu[x] = ans;
}
int main()
{
    int cas = 0;
    int t;
    scanf("%d", &t);
    sieve();
    int a, b, c, d, k;
    while (t--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k==0){
            printf("Case %d: %lld\n", ++cas, 0);
            continue;
        }
        b /= k;
        d /= k;
        if (b>d)
            swap(b, d);
        ll ans1 = 0;
        ll ans2 = 0;
        for (int i = 1; i <= b;i++)
        {
            ans1 += 1ll * (calc_mu(i)-calc_mu(i-1)) * (b / i) * (d / i);
        }
        for (int i = 1; i <= b;i++)
        {
            ans2 += 1ll * (calc_mu(i)-calc_mu(i-1)) * (b / i) * (b / i);
        }
        ans2 >>= 1;
        printf("Case %d: %lld\n", ++cas, ans1 - ans2);
    }
    return 0;
}
