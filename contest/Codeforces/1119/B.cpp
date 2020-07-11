#include<bits/stdc++.h>
using namespace std;
const int N=300005;
typedef long long ll;
int n;
ll h;
ll a[N];
priority_queue<ll> q;
bool check(int x){
    ll sum=0;
    for (int i=1;i<=x;i++){
        q.push(a[i]);
    }
    bool count=1;
    while (!q.empty()){
        ll j=q.top();
        q.pop();
        if (count){
            sum+=j;
        }
        count^=1;
    }
    return (sum<=h);
}
int main(){
    scanf("%d%I64d",&n,&h);
    for (int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    int l=1,r=n,mid,ans=1;
    while (l<=r){
        mid=(l+r)/2;
        if (check(mid)) {
            l=mid+1;
            ans=max(ans,mid);
        }else {
            r=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
