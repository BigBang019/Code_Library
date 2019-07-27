/*
  Author: IceRuler-wyb
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll n,m;
    int T;
    cin>>T;
    int ans=1;
    while(T--){
        cin>>n>>m;
        if(m==0){
            if(n==1){
                cout<<ans<<'\n';
            }
            else {
                cout<<"0\n";
                ans=0;
            }
        }
        else {
            ans=ans*qpow(n-1,mod-2)%mod;
            cout<<ans<<'\n';
        }
    }
}
