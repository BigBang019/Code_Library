#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
typedef long long ll;
ll a[N];
ll sum[N][5];
int n,q,l,r;
bool check(int x){
    return (((x-l)/2+1)&1) && (((r-x)/2+1)&1);
}
void work(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    memset(sum,0,sizeof(sum));
    for (int j=1;j<=4;j++){
        for (int i=j;i<=n;i+=4){
            sum[i][j%4]=(i-4>=0?(sum[i-4][j%4]^a[i]):a[i]);
        }
    }
    scanf("%d",&q);
    ll ans=0;
    for (int i=1;i<=q;i++){
        scanf("%d%d",&l,&r);
        ans=0;
        for (int j=0;j<4;j++){
            int p=l+j;
            if (p>r) break;
            if (check(p)){
                int k=(r-p)/4;
                int pp=p+4*k;
                ans^=sum[pp][pp%4];
                if (p-4>0) ans^=sum[p-4][pp%4];
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        work();
    }
    return 0;
}
