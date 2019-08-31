#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=100010;
const long long INF=1E18+10;


struct Edge{
	int from;
	int to;
	long long w;
	int next;
} edge[2*maxn];
int head[maxn];
int tot;
int n,m;

long long f[maxn][110];
int deg[maxn];
int siz[maxn];

void init() {
	tot=0;
	for (int i=1;i<=n;i++) {
		head[i]=0;
		deg[i]=0;
		siz[i]=0;
		for (int j=1;j<=m;j++) {
			f[i][j]=INF;
		}
	}
}

inline void addedge(int x,int y, long long w) {
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	edge[tot].w=w;
	head[x]=tot;
	tot++;
	edge[tot].next=head[y];
	edge[tot].from=y;
	edge[tot].to=x;
	edge[tot].w=w;
	head[y]=tot;
	deg[x]++;
	deg[y]++;
}


void dfs(int u,int fa) {
	if (deg[u]==1) {
		siz[u]=1;
	}
	for (int p=head[u];p!=0;p=edge[p].next) {
		int v=edge[p].to;
		long long w=edge[p].w;
		if (v==fa) {
			continue;
		}
		dfs(v,u);
		siz[u]+=siz[v];
		siz[u]=min(siz[u],m);
		for (int i=siz[u];i>=0;i--) {
			for (int j=min(siz[v],i);j>=0;j--) {
				f[u][i]=min(f[u][i],f[u][i-j]+f[v][j]+w*j*(m-j));
			}
		}
	}
	if (deg[u]==1) {
		for (int k=siz[u];k>=1;k--) {
			f[u][k]=min(f[u][k],f[u][k-1]);
		}
	}
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int rd=1;rd<=T;rd++) {
		scanf("%d%d", &n,&m);
		init();
		for (int i=1;i<n;i++) {
			int x,y;
			long long w;
			scanf("%d%d%lld", &x,&y, &w);
			addedge(x,y,w);
		}
		dfs(1,0);
		
//		for (int i=1;i<=n;i++) {
//			for (int j=0;j<=m;j++) {
//				printf("%lld ", f[i][j]);
//			}printf("\n");
//		}
		
		printf("Case #%d: %lld\n",rd,f[1][m]);
	}
	return 0;
} 

/*
3
4 2
2 1 2
2 3 3
2 4 4
4 3
1 2 2
1 3 3
1 4 4
2 2
1 2 2
*/
