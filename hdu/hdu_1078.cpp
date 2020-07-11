#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int maze[N][N];
int f[N][N];
int n, m;
int d1[4] = {0, 1, -1, 0};
int d2[4] = {-1, 0, 0, 1};
int dfs(int x,int y){
    if (f[x][y]){
        return f[x][y];
    }
    int ma = 0;
    for (int i = 0; i < 4;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            int dx = d1[i] * j;
            int dy = d2[i] * j;
            int xx = x + dx, yy = y + dy;
            if (xx<1 || xx>n || yy<1 || yy>n || maze[xx][yy]<=maze[x][y])
                continue;
            ma = max(ma, dfs(xx, yy));
        }
    }
    f[x][y] = ma + maze[x][y];
    return f[x][y];
}
int main(){
    while (scanf("%d%d",&n,&m) && n>0 && m>0)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                scanf("%d", &maze[i][j]);
            }
        }
        dfs(1, 1);
        printf("%d\n", f[1][1]);
    }
    return 0;
}
