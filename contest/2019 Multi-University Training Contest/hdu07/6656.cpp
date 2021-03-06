/*
* Author: XiaoMing
*/
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1000000;
const long long mod=1E9+7;

typedef long long ll;

ll p[maxn];
ll rp[maxn];
ll pp[maxn];

int x[maxn];
ll a[maxn];
ll f[maxn];

inline int getnum(){
    char ch;int s=0;
    while ((ch=getchar())=='\n'||ch=='\r' || ch==' ')
        ;
    while (ch>='0' && ch<='9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s;
}

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

ll gcd(ll a,ll b) {
    return b == 0? a : gcd(b,a%b);
}

//F[i]=F[i-1]+F[xi]*(pi-1)/pi+ai/pi;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n,q;
        n=getnum();
        q=getnum();
        for (int i=1;i<=n;i++) {
            long long r,s;
            r=getnum();
            s=getnum();
            x[i]=getnum();
            a[i]=getnum();
            
            long long rr=s-r;
            long long ss=quickpow(s,mod-2);
            p[i]=r*ss%mod;
            rp[i]=rr*ss%mod;
            pp[i]=quickpow(p[i],mod-2);
        }
        f[0]=0;
        f[1]=0;
        for (int i=1;i<=n;i++) {
            f[i+1]=f[i]*pp[i]%mod-f[x[i]]*rp[i]%mod*pp[i]%mod+mod+a[i]*pp[i]%mod;
            f[i+1]=f[i+1]%mod;
        }
        for (int i=1;i<=q;i++) {
            int l,r;
            scanf("%d%d", &l,&r);
            ll ans=(mod+f[r]-f[l])%mod;
            printf("%lld\n", ans);
        }
        
//        for (int i=1;i<=n+1;i++) {
//            printf("%lld ", f[i]);
//        }printf("\n");
        
    }
    return 0;
}
