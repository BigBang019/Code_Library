#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define N 1000005
#define M 3000005
#define MOD 1000000007
using namespace std;
queue<int> q;
int n,m;
int d[N],a[N],b[N];
bool vis[N];
int cnt,he[N],v[M],ne[M];
void spfa(){
	for (int i=1;i<=n;i++){
		d[i]=-N;
	}
	d[1]=b[1];
	q.push(1);
	vis[1]=1;
	while (!q.empty()){
		int j=q.front();
		q.pop();
		
		for (int i=he[j];i;i=ne[i]){
			int p=v[i];
			if (d[p]<d[j]+b[p]){
				d[p]=d[j]+b[p];
				if (!vis[p]){
					vis[p]=1;
					q.push(p);
				}
			}
		}
		vis[j]=0;
	}
}
void add(int x,int y){
	for (int i=he[x];i;i=ne[i]){
		if (v[i]==y){
			return;
		}
	}
	cnt++;
	ne[cnt]=he[x];
	he[x]=cnt;
	v[cnt]=y;
}
int check(int x){
	for (int i=1;i<=n;i++){
		if (a[i]>=x) b[i]=1;
		else if (a[i]<x) b[i]=-1;
	}
	spfa();
	return d[n];
}

int main(){
	int l=0,r=0,mid;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r=max(r,a[i]);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	spfa();
	if (d[n]==-N) {
		printf("-1\n");
		return 0;
	}
	int ans=0;
	while (l<=r){
		mid=l+r>>1;
		int tmp=check(mid);
		if (tmp>=0) {
			l=mid+1;
			ans=max(ans,mid);
		}else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
