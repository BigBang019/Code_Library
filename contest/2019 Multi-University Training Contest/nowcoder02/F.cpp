/*
  Author: XiaoMing-zhm
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
int maze[N][N];
  
ll ans = 1E18;
int cl[N], n;
void dfs(int x,int la,ll sum0, ll sum1){
    if (x>n/2){
        ans = min(ans, sum0+sum1);
        return ;
    }
    for (int i = la+1; i <= n/2+x;i++) {
        long long tmp0=0;
        long long tmp1=0;
        for (int j=1;j<=n;j++) {
            if (cl[j]==1) {
                tmp1+=maze[i][j];
            } else {
                tmp0+=maze[i][j];
            }
        }
        cl[i] = 1;
        dfs(x + 1, i, sum0-tmp0, sum1+tmp1);
        cl[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    n *= 2;
    long long sum=0;
    memset(maze,0,sizeof(maze));
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            scanf("%d", &maze[i][j]);
            if (i<j) {
                sum+=maze[i][j];
            }
        }
    }
    dfs(1, 0, sum,0);
    printf("%lld", sum-ans);
    return 0;
}
