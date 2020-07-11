//杜教筛
//套路式： g(1)S(n)=∑i=1-n h(i) —∑d=2-n g(d)S(n/d) 
//首先先线筛出数据范围根号左右的积性函数的前缀和。再递归的实现杜教筛。
//用stl中的unordered_map，而不是map
//尽量减少取模和longlong  如unordered_map 

#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define N 5001000
// #define int long long
#define mod 1000000007
#define ll long long
using namespace std;

//快读 
template<typename T>inline void read(T &x)
{
    x=0;
    static int p;p=1;
    static char c;c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
    x*=p;
}


//杜教筛题目的关键是寻找配凑h和g 使得h=f*g   1.消去  2.试凑 
int f[N];
int n;

//快速幂 求逆元 
int inv2=500000004,inv6= 166666668;


//莫比乌斯函数
const int p_max = 1E6;
int mu[p_max];
void get_mu() {
    mu[1] = 1;
    static bool vis[p_max];
    static int prime[p_max], p_sz, d;
    mu[1] = 1;
    for (int i = 2; i < p_max; i++) {
        if (!vis[i]) {
            prime[p_sz++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < p_sz && (d = i * prime[j]) < p_max; ++j) {
            vis[d] = 1;
            if (i % prime[j] == 0) {
                mu[d] = 0;
                break;
            }
            else mu[d] = -mu[i];
        }
    }
} 


//暴力求解前根号n待求积性函数的前缀和 ，get内的代码不具有普适性 
void get(int maxn){
    f[0]=0;
    for(int i=1;i<=maxn;++i){
       f[i]=(f[i-1]+1ll*mu[i]*i+1ll*i*mod)%mod;
    }
}


//杜教筛 
tr1::unordered_map<int,int> mp;
int djsf(int n)
{
    if(n<=1e6) return f[n];
    if(mp[n]) return mp[n];
    int ans=1;//h的前缀和 
    for(int l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ans=(ans-1ll*(r-l+1)*(r+l)%mod*inv2%mod*djsf(n/l)%mod+mod)%mod;  //递归减去Σg(d)S(n/d) 
        
    }
    
    return mp[n]=ans;

}

int main(){
    int t;int a;int b;
    scanf("%d",&t);
    get_mu();
    get(1e6);

    // 验证f
    // for(int i=1;i<=10;i++){
    //     printf("%lld ",f[i]);
    // }puts("");

    // //验证杜教筛
    // for(int i=1;i<=10;i++){
    //     printf("%lld ",djsf(i));
    // }puts("");
    
    while(t--)    {
        scanf("%d%d%d",&n,&a,&b);
        int ans=0;
        for(ll l=1,r,v;l<=n;l=r+1){   //为什么这里必须要有ll l=1，而int就会错呢？
            r=n/(n/l);
            v=n/l;
            ans+=1ll*(djsf(r)-djsf(l-1)+mod)%mod * v%mod*((v*v%mod-1+mod)%mod)%mod*inv6%mod;   //由于*v忘记取模导致错误
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
