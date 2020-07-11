//组合数学
//Author: IceRuler
//C(2k-1,T+2k-1)-C(2k-1,T+k-1)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int P=998244353;
  
int T,n,m;
ll ans;
ll jc[6010],rev[6010];
inline ll MP(ll a,int r){
    ll res=1;
    while(r){
        if(r&1)res=res*a%P;
        r>>=1;
        a=a*a%P;
    }
    return res;
}
inline ll C(int a,int b){
    if(b>a)return 0;
    return jc[a]*rev[b]%P*rev[a-b]%P;
}
inline void calc(int n,int k){ 
    for(int i=0;i<=n;i++){
        ans+=C(i+2*k-1,2*k-1)-C(i+k-1,2*k-1);
        ans%=P;
    }
}
  
int main(){
    scanf("%d",&T);
    jc[0]=1;
    for(int i=1;i<=6005;i++)jc[i]=jc[i-1]*i%P;
    rev[6005]=MP(jc[6005],P-2);
    for(int i=6005;i;i--)rev[i-1]=rev[i]*i%P;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        for(int i=1;i*m<=n;i++){
            calc(n-i*m,i);
        }
        cout<<ans<<endl;
    }
      
}
