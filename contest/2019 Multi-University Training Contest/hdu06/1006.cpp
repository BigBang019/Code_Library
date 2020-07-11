#include<bits/stdc++.h>
#define ll long long
#define N 20
#define K 60
using namespace std;


ll n,m,x,y,i,j;
ll ca,cb;
ll a[N],b[N];

struct Edge{int x,y,k,t;}e[N];
int abs(int x){return x>0?x:-x;}

bool check(int x,int y){
  for(int i=0;i<n;i++)if((abs(x-e[i].x)+abs(y-e[i].y))%e[i].k!=e[i].t)return 0;
  return 1;
}
int cal(int l,int r){
  r-=l+1;
  if(r<0)return 0;
  return r/K+1;
}
int main() {
    int T; scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&n,&m);
        ca =1,cb = 1;
        a[ca]=b[cb] = m+1;
        for(i=0;i<n;i++){
            scanf("%lld%lld%lld%lld",&e[i].x,&e[i].y,&e[i].k,&e[i].t);
            a[++ca]=e[i].x;
            b[++cb]=e[i].y;
        }
        sort(a+1,a+ca+1);
        sort(b+1,b+cb+1);
        ll ans=0;
        for(i=0;i<ca;i++){
            if(a[i]<a[i+1]){
                for(j=0;j<cb;j++){
                    if(b[j]<b[j+1]){
                        for(x=0;x<K;x++)for(y=0;y<K;y++){
                            if(check(a[i]+x,b[j]+y)){
                                ans+=1ll*cal(a[i]+x,a[i+1])*cal(b[j]+y,b[j+1]);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
