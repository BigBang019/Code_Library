#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5050;
const int maxm=2050;
struct wood{
    long long w;
    long long h;
    bool operator < (const wood &x) {
        if (h==x.h) {
            return w>x.w;
        }
        return h>x.h;
    }
}a[maxn];
int n,k;
 
long long dp[maxm][maxn];
long long sum[maxn];
long long len[maxn];
 
int q[maxn];
 
/*
x<y
f[x]-f[y] = dp[i-1][x]-dp[i-1][y]-(sum[x]-sum[y])+height[j](len[x]-len[y])
 
<0 f[x]<f[y]
(dp[i-1][x]-dp[i-1][y]-(sum[x]-sum[y]))/(len[y]-len[x])<height[j]
=0 f[x]=f[y]
(dp[i-1][x]-dp[i-1][y]-(sum[x]-sum[y]))/(len[y]-len[x])=height[j]
>0 f[x]>f[y]
(dp[i-1][x]-dp[i-1][y]-(sum[x]-sum[y]))/(len[y]-len[x])>height[j]
 
*/
inline void init() {
    sum[0]=0;
    len[0]=0;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i].w*a[i].h;
        len[i]=len[i-1]+a[i].w;
        dp[1][i]=sum[i]-a[i].h*len[i];
    }
}
 
double cal(int i,int x,int y) {
    double up=dp[i-1][x]-dp[i-1][y]-(sum[x]-sum[y]);
    double down = len[y]-len[x];
    return up/down;
}
 
int main() {
    scanf("%d%d", &n,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d%d", &a[i].w, &a[i].h);
    }
    sort(a+1,a+n+1);
    init();
    for (int i=2;i<=k;i++) {
        int l=0;
        int r=0;
        q[r]=0;
        r++;
        for (int j=1;j<=n;j++) {
            while (l+1<r && (cal(i,q[l],q[l+1])>a[j].h)) {l++;}
            dp[i][j]=dp[i-1][q[l]]+sum[j]-sum[q[l]]-a[j].h*(len[j]-len[q[l]]);
            while (l+1<r && (cal(i,q[r-1],j)>cal(i,q[r-2],q[r-1]))) {r--;}
            q[r]=j;
            r++;
        }
    }
    printf("%lld\n", dp[k][n]);
}
