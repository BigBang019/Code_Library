/*********************************************************************************
  f[i][j]表示以i位置开头的s后缀中选长度为j的subsequence有多少选法大于t中长度j的后缀
  每次考虑当前位置选还是不选，选的话还要考虑s[i]与t[m-j]的关系是大于还是等于
*********************************************************************************/
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
const int N = 3e3 + 5;
const int MOD = 998244353;
char s[N], t[N];
int sum[N][11];
int C[N][N], f[N][N], Cs[N][N];
int main(){
    int _, n, m;
    for (int i = 0; i <= 3000;i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i;j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        for (int j = i; j >= 0;j--)
        {
            Cs[i][j] = (Cs[i][j + 1] + C[i][j]) % MOD;
        }
    }
    for (scanf("%d", &_); _;_--)
    {
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n;i++)
            for (int j = 0; j <= n;j++)
                f[i][j] = 0;
        scanf(" %s %s", s, t);
        for (int i = n - 1; i >= 0;i--)
            sum[i][s[i] - '0']++;
        for (int i = n - 1; i >= 0;i--)
            for (int j = 9; j >= 0;j--)
                sum[i][j] = sum[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
        for (int i = n - 1; i >= 0;i--){
            f[i][1] = sum[i][t[m - 1] - '0' + 1];
        }
        for (int i = n - 2; i >= 0;i--)
        {
            for (int j = 2; j <= n - i && j <= m; j++)
            {
                f[i][j] = (f[i + 1][j] + (s[i] > t[m - j] ? C[n - i - 1][j - 1] : (s[i] == t[m - j] ? f[i + 1][j - 1] : 0))) % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            if (n-i<=m)
                break;
            if (s[i]=='0')
                continue;
            ans = (ans + Cs[n - i - 1][m]) % MOD;
        }
        printf("%d\n", (ans + f[0][m]) % MOD);
    }
    return 0;
}
