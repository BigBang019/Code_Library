#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000000;
double p[maxn];
double f[maxn];
double g[maxn];


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%lf", &p[i]);
        }
        sort(p+1,p+n+1);
        double ans=p[n];
        double mul=1-p[1];
        f[1]=p[1];
        for (int i=2;i<=n;i++) {
            f[i]=mul*p[i]+f[i-1]*(1-p[i]);
            mul=mul*(1-p[i]);
            if (f[i]>ans) {
                ans=f[i];
            }
        }
        mul=1-p[n];
        g[n]=p[n];
        for (int i=n-1;i>=1;i--) {
            g[i]=mul*p[i]+g[i+1]*(1-p[i]);
            mul=mul*(1-p[i]);
            if (g[i]>ans) {
                ans=g[i];
            }
        }
        printf("%.12f\n", ans);
    }
    return 0;
}
