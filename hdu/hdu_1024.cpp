#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<climits>
#include<queue>
#define N 1000005
#define ll long long
using namespace std;
ll f[N];
ll pre[N];
int n,m;
ll a[N];
int main(){
	while (scanf("%d",&m)!=EOF){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		ll mm;
		for (int j=1;j<=m;j++){
			mm=-0x7fffffff;
			for (int i=j;i<=n;i++){
				f[i]=max(f[i-1]+a[i],pre[i-1]+a[i]);
				pre[i-1]=mm;
				mm=max(mm,f[i]);
			}
		}
		ll ans=-0x7fffffff;
		for (int i=m;i<=n;i++){
			ans=max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
