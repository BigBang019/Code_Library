#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define N 2005
#define M 3000005
#define MOD 1000000007
using namespace std;
int n,m;
bool fl;
stack<int> st;
int cmp,tot,inst[N],icp[N],dfn[N],low[N];

int cnt,he[N],w[M],v[M],ne[M];

int mp[N][N],indeg[N],val[N];

bool vis[N][N];
void add(int x,int y,int z){
	cnt++;
	ne[cnt]=he[x];
	he[x]=cnt;
	v[cnt]=y;
	w[cnt]=z;
}
void tanjan(int x){
	st.push(x);
	inst[x]=2;
	dfn[x]=low[x]=++tot;
	for (int i=he[x];i;i=ne[i]){
		int p=v[i];
		if (!dfn[p]){
			tanjan(p);
			low[x]=min(low[x],low[p]);
		}else if (inst[p]==2){
			low[x]=min(low[x],dfn[p]);
		}
	}
	if (dfn[x]==low[x]){
		cmp++;
		while (!st.empty()){
			int j=st.top();
			st.pop();
			icp[j]=cmp;
			inst[j]=1;
			if (j==x) break;
		}
	}
}
queue<int> q;
void work(){
	for (int i=1;i<=n+m;i++){
		for (int j=he[i];j;j=ne[j]){
			int p=v[j];
			int ii=icp[i],ip=icp[p];
			if (w[j]==0) continue;
			if (ii==ip){
				fl=1;
				return;
			}else{
				if (vis[ii][ip]) continue;
				indeg[ip]++;
				mp[ii][ip]=1;
				mp[ip][ii]=-1;
				vis[ii][ip]=1;
			}
		}
	}
	for (int i=1;i<=cmp;i++){
		if (!indeg[i]) {
			q.push(i);
			val[i]=1;
		}
	}
	while (!q.empty()){
		int j=q.front();
		q.pop();
		for (int i=1;i<=cmp;i++){
			if (mp[j][i]==-1){
				val[j]=max(val[j],val[i]+1);
			}
			if (mp[j][i]==1){
				indeg[i]--;
				if (indeg[i]==0) q.push(i);
			}
		}
	}
}
int main(){
	cnt=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char ch;
			scanf(" %c",&ch);
			if (ch=='>'){
				add(j+n,i,1);
			}else if (ch=='='){
				add(j+n,i,0);
				add(i,j+n,0);
			}else {
				add(i,j+n,1);
			}
		}
	}
	for (int i=1;i<=n+m;i++){
		if (!dfn[i]){
			tanjan(i);
		}
	}
	
	fl=0;
	work();
	printf("%s\n",fl?"No":"Yes");
	if (!fl){
		for (int i=1;i<=n;i++){
			printf("%d ",val[icp[i]]);
		}
		printf("\n");
		for (int i=1;i<=m;i++){
			printf("%d ",val[icp[i+n]]);
		}
		printf("\n");
	}
	return 0;
}
