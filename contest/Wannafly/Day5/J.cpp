// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int C = 130;
double maze[C][C];
int a[N];
double sum[C][N];
double f[N];
int main(){
    int c;
    while (~scanf("%d", &c))
    {
        int n = c * (c - 1) * (c - 2) / 6;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                scanf("%lf", &maze[i][j]);
            }
        }
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m;i++)
        {
            scanf("%d", &a[i]);
            a[i]++;
        }
        for (int j = 1; j <= n;j++)
        {
            sum[j][0] = 1;
            for (int i = 1; i <= m;i++)
            {
                sum[j][i] = sum[j][i - 1] * maze[j][a[i]];
            }
        }
        for (int i = 1; i <= m;i++)//f表示捶死i的最大pro
        {
            f[i] = 0;
            for (int dui = 1; dui <= n;dui++)
            {
                f[i] = max(f[i], sum[dui][i]);//头铁用一队打到底
            }
            for (int j = 1; j < i;j++)//在捶死j的时候换成a[j]
            {
                f[i] = max(f[i], f[j] * (sum[a[j]][i] / sum[a[j]][j]));
            }
        }
        printf("%.6f\n", f[m]);
    }
    return 0;
}
