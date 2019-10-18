/*
  http://codeforces.com/contest/1119
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300005;
typedef long long ll;
ll s[N],d[N],a[N];
int n,q;
int getIndex(ll len){
    int l=1,r=n-1,mid,ans=0;
    while (l<=r){
        mid=(l+r)/2;
        if (d[mid]<len){
            l=mid+1;
            ans=max(ans,mid);
        }else {
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    sort(d+1,d+n);
    for (int i=1;i<n;i++){
        s[i]=s[i-1]+d[i];
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        int pos=getIndex(r-l+1);
        ll ans=s[pos]+(n-pos)*(r-l+1);
        printf("%I64d ",ans);
    }
    return 0;
}
