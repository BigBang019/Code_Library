#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;
const int N = 1e2 + 5;
char s[N];
char ans[N];
int f[N][N][N];
int pre[N][N][N];
void print(int x,int y,int z){
    if (pre[x][y][z]==1) {
        print(x-1,y,z);
        putchar('R');
    }else if (pre[x][y][z]==2){
        print(x, y - 1, z);
        putchar('P');
    }else if (pre[x][y][z]==3){
        print(x, y, z - 1);
        putchar('S');
    }
}
int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int n, a, b, c;
        memset(f, 0, sizeof(f));
        memset(pre, 0, sizeof(pre));
        cin >> n >> a >> b >> c;
        scanf(" %s", s + 1);
        for (int i = 0; i <= a;++i)//R
        {
            for (int j = 0; j <= b;++j)//P
            {
                for (int k = 0; k <= c;++k)//S
                {
                    if (!i && !j && !k)
                        continue;
                    if (k>0){
                        if (s[i+j+k]=='P'){
                            if (f[i][j][k]<f[i][j][k-1]+1){
                                f[i][j][k] = f[i][j][k - 1] + 1;
                                pre[i][j][k] = 3;//S
                            }
                        }else{
                            if (f[i][j][k]<=f[i][j][k - 1]){
                                f[i][j][k] = f[i][j][k - 1];
                                pre[i][j][k] = 3;
                            }
                        }
                    }
                    if (j>0){
                        if (s[i + j + k] == 'R'){
                            if (f[i][j][k]<f[i][j-1][k]+1){
                                f[i][j][k] = f[i][j - 1][k] + 1;
                                pre[i][j][k] = 2;
                            }
                        }else{
                            if (f[i][j][k]<=f[i][j-1][k]){
                                f[i][j][k] = f[i][j - 1][k];
                                pre[i][j][k] = 2;
                            }
                        }
                    }
                    
                    if (i>0){
                        if (s[i + j + k] == 'S'){
                            if (f[i][j][k]<f[i-1][j][k]+1){
                                f[i][j][k] = f[i - 1][j][k] + 1;
                                pre[i][j][k] = 1;
                            }
                        }else {
                            if (f[i][j][k]<=f[i-1][j][k]){
                                f[i][j][k] = f[i - 1][j][k];
                                pre[i][j][k] = 1;
                            }
                        }
                    }
                }
            }
        }
        if (f[a][b][c]>=n/2+(n%2)){
            printf("YES\n");
            print(a, b, c);
            puts("");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
