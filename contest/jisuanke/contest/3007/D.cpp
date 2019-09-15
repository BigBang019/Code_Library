#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000;
const long long mod=1E9+7;
int n;

struct Edge {
	int from;
	int to;
	long long w;
	int next;
} edge[maxn];
int head[maxn];
int tot;

long long ans[3];
long long f[maxn][3][2]; // %3==i || 0: length || 1: size

inline void init() {
	for (int i=0;i<=n;i++) {
		head[i]=0;
	}
	for (int i=0;i<=2;i++) {
		ans[i]=0;
	}
	tot=0;
}

inline void addedge(int x,int y,long long w) {
//	printf("now :%d %d\n", x,y);
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	edge[tot].w=w;
	head[x]=tot;
}

long long tmp[3][2];

void dfs(int u, int fa) {
	for (int i=0;i<=2;i++) {
		f[u][i][0]=0;
		f[u][i][1]=0;
	}
	
	for (int p=head[u];p!=0;p=edge[p].next) {
		int v=edge[p].to;
		long long w = edge[p].w;
		
		if (v==fa) {
			continue;
		}
//		printf(":: %d %d\n", v,u);
		dfs(v,u);
		
		for (int i=0;i<=2;i++) {
			tmp[i][0]=0;
			tmp[i][1]=0;
		}
		for (int i=0;i<=2;i++) {
			tmp[(i+w%3)%3][0]=f[v][i][0]+w*f[v][i][1];
			tmp[(i+w%3)%3][1]=f[v][i][1];
		}
		
		for (int i=0;i<=2;i++) {
			for (int j=0;j<=2;j++) {
				ans[(i+j)%3] += f[u][i][0]*tmp[j][1]+f[u][i][1]*tmp[j][0];
				ans[(i+j)%3] %= mod;
			}
		}
		
		for (int i=0;i<=2;i++) {
			f[u][i][0]+=tmp[i][0];
			f[u][i][1]+=tmp[i][1];
		}
	}
	for (int i=0;i<=2;i++) {
		ans[i]+=f[u][i][0];
		ans[i]=ans[i]%mod;
	}
	f[u][0][1]+=1;
//	printf("?? %d\n", u);
	return ;
}

int main() {
	while (~scanf("%d", &n)) {
		init();
		for (int i=1;i<n;i++) {
			int x,y;
			long long w;
			scanf("%d%d%lld", &x,&y,&w);
//			printf("why!! %d %d", x,y);
			x++;
			y++;
			addedge(x,y,w);
			addedge(y,x,w);
		}
		dfs(1,0);
		
//		for (int i=1;i<=n;i++) {
//			for (int j=0;j<=2;j++) {
//				printf("(%lld,%lld) ", f[i][j][0], f[i][j][1]);
//			}printf("\n");
//		}
		
		for (int i=0;i<=2;i++) {
			printf("%lld", (ans[i]*2)%mod);
			if (i<=1) {
				printf(" ");
			}
		} printf("\n");
	}
	return 0;
}
