#include<cstdio>
#include<algorithm>
 
using namespace std;
 
const long long mod=998244353;
const int maxn=1E7+5;
const int maxl=1E7+5;
const int maxm=3005;
 
int L,D,m;
long long dp[maxl], pre[maxl];
long long g[maxm][maxm];
long long fac[maxn+9],inv_fac[maxn+9];
 
struct Node{
    long long t;
    long long p;
    bool operator <(const Node &x) const {
        return t<x.t;
    }
} a[maxm];
 
long long quickpow(long long x,long long n) {
    long long res=1;
    x=x%mod;
    while(n)
    {
        if(n%2==1)res=(res*x)%mod;
        n=n/2;
        x=(x*x)%mod;
    }
    return res;
}
 
void print() {
    fac[0]=1;
    for(int i=1;i<=maxn;i++) {
        fac[i]=(fac[i-1]*i)%mod;//阶乘取余打表
    }
    //切记,求阶乘逆元时maxn最大值为mod-1，因为用这个公式时要保证待求逆元的数（此处为n!）要和mod互质。
    inv_fac[maxn]=quickpow(fac[maxn],mod-2);//最大阶乘逆元
    for(int i=maxn-1;i>=0;i--) {
        inv_fac[i]=(inv_fac[i+1]*(i+1))%mod;//递推阶乘逆元
    }
}
 
 
void init() {
    for (int i=0;i<D;i++) {
        dp[i]=0;
        pre[i]=1;
    }
    dp[0]=1;
    g[0][0]=1;
    a[0].t=0;
}
 
int main() {
    scanf("%d%d%d", &L,&D,&m);
    for (int i=1;i<=m;i++) {
        scanf("%lld%lld", &a[i].t, &a[i].p);
    }
    print();
    init();
    for (int i=D;i<=L;i++) {
        dp[i]=pre[i-D];
        pre[i]=(pre[i-1]+dp[i])%mod;
    }
    long long ans=dp[L]; //满足距离限制的走到L的方案数
    sort(a+1,a+m+1);
    for (int i=1;i<=m;i++) {
        for (int j=0;j<i;j++) {
            long long dt = a[i].t-a[j].t;
            if (dt<=0) {continue;}
            long long dl = a[i].p-a[j].p-dt*D;
            if (dl<0) {continue;}
            long long C = fac[dt+dl-1]*inv_fac[dt-1]%mod*inv_fac[dl]%mod;
            g[i][0]=(g[i][0]+g[j][1]*C)%mod;
            g[i][1]=(g[i][1]+g[j][0]*C)%mod;
        }
        ans=(ans+g[i][0]*dp[L-a[i].p]%mod-g[i][1]*dp[L-a[i].p]%mod+mod)%mod;
    }
    printf("%lld\n", ans);
    return 0;
}
