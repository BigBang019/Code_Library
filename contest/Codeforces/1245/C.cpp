#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;
char s[N];
ll ans = 0;
ll A[N], inv[N];
ll qp(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        k >>= 1;
    }
    return res;
}
int main()
{
    A[0] = 1;
    inv[0] = qp(A[0], MOD - 2);
    for (int i = 1; i <= 1e5; i++)
    {
        A[i] = A[i - 1] * i % MOD;
        inv[i] = qp(A[i], MOD - 2);
    }
    scanf("%s", s);
    int len = strlen(s);
    ans = 1;
    int u = 0, n = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i]=='w' || s[i]=='m'){
            ans = 0;
            u = n = 0;
            break;
        }
        if (s[i]=='u') {
            u++;
            if (n>1){
                ll res = 0;
                for (int i = 0; i <= n / 2; ++i)
                {
                    res = (res + A[n - i] * inv[i] % MOD * inv[n - 2 * i] % MOD) % MOD;
                }
                ans = ans * res % MOD;
            }
            n = 0;
        }else if (s[i]=='n'){
            n++;
            if (u>1){
                ll res = 0;
                for (int i = 0; i <= u / 2; ++i)
                {
                    res = (res + A[u - i] * inv[i] % MOD * inv[u - 2 * i] % MOD) % MOD;
                }
                ans = ans * res % MOD;
            }
            u = 0;
        }else{
            if (n>1){
                ll res = 0;
                for (int i = 0; i <= n / 2; ++i)
                {
                    res = (res + A[n - i] * inv[i] % MOD * inv[n - 2 * i] % MOD) % MOD;
                }
                ans = ans * res % MOD;
            }
            if (u>1){
                ll res = 0;
                for (int i = 0; i <= u / 2; ++i)
                {
                    res = (res + A[u - i] * inv[i] % MOD * inv[u - 2 * i] % MOD) % MOD;
                }
                ans = ans * res % MOD;
            }
            u = n = 0;
        }
    }
    if (n>1){
        ll res = 0;
        for (int i = 0; i <= n / 2; ++i)
        {
            res = (res + A[n - i] * inv[i] % MOD * inv[n - 2 * i] % MOD) % MOD;
        }
        ans = ans * res % MOD;
    }
    if (u>1){
        ll res = 0;
        for (int i = 0; i <= u / 2; ++i)
        {
            res = (res + A[u - i] * inv[i] % MOD * inv[u - 2 * i] % MOD) % MOD;
        }
        ans = ans * res % MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
