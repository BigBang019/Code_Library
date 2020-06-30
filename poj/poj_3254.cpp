#include <cstdio>
using namespace std;
typedef long long ll;
const int MOD = 1e8;
const int N = 13;
int n, m;
int maze[N];
int po[N];
ll f[N][8192];
bool check(int x){
    int la = x & 1;
    for (int i = 1; i < m;i++)
    {
        if (x&po[i]){
            if (la)
                return false;
            la = 1;
        }else
            la = 0;
    }
    return true;
}
int main(){
    for (int i = 0, t = 1; i < 12; i++, t *= 2)
    {
        po[i] = t;
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
    {
        maze[i] = 0;
        for (int j = 0; j < m;j++)
        {
            bool fl;
            scanf("%d", &fl);
            maze[i] += fl ? po[j] : 0;
        }
    }
    for (int j = 0; j < po[m];j++)
    {
        f[1][j] = 0;
        if ((j&maze[1])<j)
            continue;
        if (!check(j))
            continue;
        f[1][j] = 1;
    }
    for (int i = 2; i <= n;i++)
    {
        for (int j = 0; j < po[m]; j++)
        {
            f[i][j] = 0;
            if ((j & maze[i]) < j)
                continue;
            if (!check(j))
                continue;
            for (int k = 0; k < po[m]; k++)
            {
                if (k&j)
                    continue;
                f[i][j] = (f[i - 1][k] + f[i][j]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < po[m];j++)
    {
        ans = (ans + f[n][j]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
