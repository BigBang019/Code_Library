#pragma GCC optimize(2)
#include <bits/stdc++.h>
namespace ST_2D{
    using namespace std;
    typedef long long ll;
    const int N = 5e2 + 5;
    int maze[N][N];
    int LOG[N];
    int dp[N][N][10][10];
    int mp[N][N][10][10];
    inline int Max(int a,int b){
        return a > b ? a : b;
    }
    inline int Min(int a,int b){
        return a < b ? a : b;
    }
    void init(){
        for (register int i = 2; i <= N - 5; i++)
        {
            LOG[i] = LOG[i >> 1] + 1;
        }
    }
    inline void ST(int n,int m){
        for (register int i = 1; i <= n;i++)
        {
            for (register int j = 1; j <= m;j++)
            {
                dp[i][j][0][0] = maze[i][j];
                mp[i][j][0][0] = maze[i][j];
            }
        }
        for (register int k = 0; (1 << k) <= n;k++)
        {
            for (register int l = 0; (1 << l) <= m;l++)
            {
                if (l==0 && k==0)
                    continue;
                for (register int i = 1; i + (1 << k) - 1 <= n;i++)
                {
                    for (register int j = 1; j + (1 << l) - 1 <= m;j++)
                    {
                        if (k==0){
                            dp[i][j][k][l] = Max(dp[i][j][k][l - 1], dp[i][j + (1 << (l - 1))][k][l - 1]);
                            mp[i][j][k][l] = Min(mp[i][j][k][l - 1], mp[i][j + (1 << (l - 1))][k][l - 1]);
                        }
                        else{
                            dp[i][j][k][l] = Max(dp[i][j][k - 1][l], dp[i + (1 << (k - 1))][j][k - 1][l]);
                            mp[i][j][k][l] = Min(mp[i][j][k - 1][l], mp[i + (1 << (k - 1))][j][k - 1][l]);
                        }
                    }
                }
            }
        }
    }
    inline int query(int x1,int x2,int y1,int y2){
        int k = LOG[x2 - x1 + 1], l = LOG[y2 - y1 + 1];
        int ans = dp[x1][y1][k][l];
        ans = Max(ans, dp[x1][y2 - (1 << l) + 1][k][l]);
        ans = Max(ans, dp[x2 - (1 << k) + 1][y1][k][l]);
        ans = Max(ans, dp[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]);
        return ans;
    }
    inline int queryM(int x1,int x2,int y1,int y2){
        int k = LOG[x2 - x1 + 1], l = LOG[y2 - y1 + 1];
        int ans = mp[x1][y1][k][l];
        ans = Min(ans, mp[x1][y2 - (1 << l) + 1][k][l]);
        ans = Min(ans, mp[x2 - (1 << k) + 1][y1][k][l]);
        ans = Min(ans, mp[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]);
        return ans;
    }
}
using namespace ST_2D;
inline int getnum(){
    char ch;
    int s = 0;
    while ((ch=getchar())=='\n'||ch=='\r'||ch==' ')
        ;
    s = ch - '0';
    while (isdigit(ch=getchar()))
        s = s * 10 + ch - '0';
    return s;
}
int n, m;
// int mlen[N];
string s;
inline void work(){
    n = getnum();
    m = getnum();
    for (register int i = 1; i <= n;i++)
    {
        for (register int j = 1; j <= n;j++)
        {
            maze[i][j] = getnum();
        }
    }
    ST(n, n);
    int ans = 0;
    // for (register int i = 1; i <= n;i++)//cut6
    // {
    //     int h = 1;
    //     mlen[i] = 1;
    //     for (register int k = 1; k <= n;k++)
    //     {
    //         int mn = query(i, i, h, k);
    //         int mx = query(i, i, h, k);
    //         while (mx-mn>m){
    //             h++;
    //             if (h>k)
    //                 break;
    //             mn = query(i, i, h, k);
    //             mx = query(i, i, h, k);
    //         }
    //         mlen[i] = Max(mlen[i], k - h + 1);
    //     }
    //     // cout << i << " " << mlen[i] << endl;
    // }
    for (register int i = 1; i <= n;i++)
    {
        if ((n - i + 1) * n <= ans) //cut3
            break;
        // int mpy = n;
        for (register int j = i; j <= n;j++)
        {
            // mpy = Min(mpy, mlen[j]); //cut6
            int lenx = j - i + 1;
            if (lenx * n <= ans) //cut1+cut6
                continue;
            int tmp = 0;
            int h = 1;
            for (register int k = Max(1, ans / lenx); k <= n; k++) //cut5
            {
                if (lenx * (k - h + 1) <= ans) //cut2
                    continue;
                int mn = queryM(i, j, h, k);
                int mx = query(i, j, h, k);
                while (mx - mn > m)
                {
                    h++;
                    if ((n - h + 1) * lenx <= ans) //cut4-1
                        break;
                    if (h>k)
                        break;
                    mn = queryM(i, j, h, k);
                    mx = query(i, j, h, k);
                }
                if ((n - h + 1) * lenx <= ans) //cut4-2
                    break;
                tmp = lenx * (k - h + 1);
                if (tmp>ans)ans = Max(tmp, ans);
            }
        }
    }
    printf("%d\n", ans);
}
int main(){
    // clock_t st = clock();
    init();
    int t;
    t = getnum();
    while (t--){
        work();
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
