#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int R = 1e6 + 5;
int n;
int a[N];
int ma = 0;
ll f[N];
vector<int> vc[R];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        ma = max(a[i], ma);
    }
    for (int i = 2; i <= ma;i++)
    {
        for (int j = 1; j * i <= ma;j++)
        {
            vc[j * i].push_back(i);
        }
    }
    for (int i = 1; i <= n;i++)
    {
        int x = a[i];
        for (int j = vc[x].size() - 1; j >= 0;j--)
        {
            int p = vc[x][j];
            if (p>i)
                continue;
            f[p] = (f[p] + f[p - 1]) % MOD;
        }
        f[1] = (f[1] + 1) % MOD;
    }
    ll ans = 0;
    for (int j = 1; j <= n;j++)
    {
        ans = (ans + f[j]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
