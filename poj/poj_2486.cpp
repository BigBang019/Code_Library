#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e2 + 5;
int n, m;
int a[N], f[N][2][N];
bool vis[N];
int cnt, he[N], ne[N * 2], v[N * 2];
void add(int x,int y){
	cnt++;
	ne[cnt] = he[x];
	v[cnt] = y;
	he[x] = cnt;
}
void dfs(int x){
	for (int i = 0; i <= m;i++)
	{
		f[x][0][i] = f[x][1][i] = a[x];
	}
	vis[x] = 1;
	for (int i = he[x]; i;i=ne[i])
	{
		int p = v[i];
		if (vis[p])
			continue;
		dfs(p);
		for (int j = m; j >= 0;j--)
		{
			for (int t = 0; t <= j;t++)
			{
				f[x][1][j + 2] = max(f[x][1][j + 2], f[x][1][j - t] + f[p][1][t]);
				f[x][0][j + 2] = max(f[x][0][j + 2], f[x][0][j - t] + f[p][1][t]);
				f[x][0][j + 1] = max(f[x][0][j + 1], f[x][1][j - t] + f[p][0][t]);
			}
		}
	}
}
void init(){
	cnt = 0;
	memset(he, 0, sizeof(he));
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i = 1; i <= n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i = 1; i < n;i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		dfs(1);
		printf("%d\n", max(f[1][1][m], f[1][0][m]));
	}
	return 0;
}
