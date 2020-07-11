#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define LL __int128
const ll mod=1e9+7;
ll ans[100000];
int main() {
    ll T; scanf("%lld",&T);
    while(T--){
        ll k; scanf("%lld",&k);
        ll n; scanf("%lld",&n);
        ans[0]=0; ll tmp;
        for(ll i=1;i<=2*k;i++){
            scanf("%lld",&tmp);
            ans[i]=(tmp+ans[i-1])%mod;
        }
        LL res=ans[2*k];
        if(n<=2*k) printf("%lld\n",ans[n]);
        
        else{
            res=(res+(LL)tmp*(LL)(n-2*k)%mod)%mod;
            ll res1=res;
            printf("%lld\n",res);
        }
    }
    return 0;
}
