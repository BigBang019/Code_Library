#include<bits/stdc++.h>
namespace ST_2D{
    using namespace std;
    const int N = 3e2 + 5;
    int n, m;
    int maze[N][N];
    int dp[N][N][9][9];
    void ST(int n,int m){
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                dp[i][j][0][0] = maze[i][j];
            }
        }
        for (int k = 0; (1 << k) <= n;k++)
        {
            for (int l = 0; (1 << l) <= m;l++)
            {
                if (l==0 && k==0)
                    continue;
                for (int i = 1; i + (1 << k) - 1 <= n;i++)
                {
                    for (int j = 1; j + (1 << l) - 1 <= m;j++)
                    {
                        if (k==0)
                            dp[i][j][k][l] = max(dp[i][j][k][l - 1], dp[i][j + (1 << (l - 1))][k][l - 1]);
                        else
                            dp[i][j][k][l] = max(dp[i][j][k - 1][l], dp[i + (1 << (k - 1))][j][k - 1][l]);
                    }
                }
            }
        }
    }
    int query(int x1,int x2,int y1,int y2){
        int k = 0, l = 0;
        while((1<<(k+1))<=x2-x1+1)
            k++;
        while((1<<(l+1))<=y2-y1+1)
            l++;
        int ans = dp[x1][y1][k][l];
        ans = max(ans, dp[x1][y2 - (1 << l) + 1][k][l]);
        ans = max(ans, dp[x2 - (1 << k) + 1][y1][k][l]);
        ans = max(ans, dp[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]);
        return ans;
    }
}
using namespace ST_2D;
int main(){
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                scanf("%d", &maze[i][j]);
            }
        }
        int q;
        ST(n, m);
        scanf("%d",&q);
        while(q--){
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int ans = query(x1, x2, y1, y2);
            printf("%d ",ans);
            if (maze[x1][y1]==ans || maze[x2][y1]==ans|| maze[x1][y2]==ans || maze[x2][y2]==ans)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
