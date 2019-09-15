#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000000;

int n,m,k;

struct Edge {
	int from;
	int to;
	int next;
} edge[maxn];
int head[maxn];
int col[maxn];
int coln;
double cnt[maxn];
double deg[maxn];

int tot;

inline void init() {
	for (int i=0;i<=n;i++) {
		head[i]=0;
		col[i]=0;
		deg[i]=0;
		cnt[i]=0;
	}
	coln=0;
	tot=0;
}

inline void addedge(int x,int y) {
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	head[x]=tot;
}

void dfs(int u,int color) {
	col[u]=color;
	for (int p=head[u];p!=0;p=edge[p].next) {
		int v=edge[p].to;
		if (col[v]<0) {
			if (color==1) {
				col[v]=-2;
			}
			continue;
		}
		if (col[v]>0) {continue;}
		dfs(v,color);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n,&m,&k);
		init();
		for (int i=1;i<=m;i++) {
			int x,y;
			scanf("%d%d", &x,&y);
			addedge(x,y);
			addedge(y,x);
			deg[x]++;
			deg[y]++;
		}
		for (int i=1;i<=k;i++) {
			int x;
			scanf("%d", &x);
			col[x]=-1;
		}
		for (int i=1;i<=n;i++) {
			if (col[i]==0) {
				coln++;
				dfs(i,coln);
			}
		}
		for (int i=1;i<=n;i++) {
			if (col[i]>0) {
				cnt[col[i]]++;
			}
		}
		
//		for (int i=1;i<=n;i++) {
//			printf("%d ", col[i]);
//		}printf("\n");
		
		double ans=0;
		for (int u=1;u<=n;u++) {
			if (col[u]!=-2) {
				continue;
			}
			double res = 0;
			for (int p=head[u];p!=0;p=edge[p].next) {
				int v=edge[p].to;
				if (col[v]<=1) {
					continue;
				}
				res=res+cnt[col[v]]/deg[u];
			}
			if (res>ans) {
				ans=res;
			}
		}
		ans=ans+cnt[1];
		printf("%.7lf\n", ans);
	}
	return 0;
}
