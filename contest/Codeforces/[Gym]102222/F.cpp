#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=205;
const int maxw=100010;

int f[maxn][maxn][maxn];
int w[maxn];
int to[maxn];

bool cmp(int x,int y) {
	return w[x]<w[y];
}


int main() {
	int T;
	scanf("%d", &T);
	for (int rd=1;rd<=T;rd++) {
		int n,m;
		scanf("%d%d", &n,&m);
		for (int i=1;i<=n;i++) {
			to[i]=i;
			scanf("%d", &w[i]);
		}
		sort(to+1,to+n+1, cmp);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				scanf("%d", &f[0][i][j]);
			}
		}
		
		
		for (int k=1;k<=n;k++) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) {
					if (f[k-1][i][j]>f[k-1][i][to[k]]+f[k-1][to[k]][j]) {
						f[k][i][j]=f[k-1][i][to[k]]+f[k-1][to[k]][j];
					} else {
						f[k][i][j]=f[k-1][i][j];
					}
				}
			}
		}
		printf("Case #%d:\n", rd);
		for (int i=1;i<=m;i++) {
			int u,v,k;
			scanf("%d%d%d", &u,&v,&k);
			int l=1;
			int r=n+1;
			while (l!=r) {
				int mid=(l+r)/2;
				if (w[to[mid]]>k) {
					r=mid;
				} else {
					l=mid+1;
				}
			}
//			printf("%d\n",l-1);
			printf("%d\n", f[l-1][u][v]);
		}
	}
	return 0;
}

/*
2
3 6
2 6 9
0 1 3
1 0 1
3 1 0
1 1 2
1 2 4
1 3 5
1 1 6
1 2 7
1 3 8
3 6
1 2 3
0 1 3
1 0 1
3 1 0
1 1 1
1 2 1
1 3 1
1 1 2
1 2 2
1 3 2
*/
