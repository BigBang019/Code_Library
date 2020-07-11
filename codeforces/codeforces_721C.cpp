#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5;
int f[N][N];
int pre[N][N];
ll t;
int indeg[N];
queue<int> q;
int cnt, he[N], ne[N * 2], w[N * 2], v[N * 2];
void add(int x,int y,ll z){
	cnt++;
	v[cnt] = y;
	w[cnt] = z;
	ne[cnt] = he[x];
	he[x] = cnt;
}
void print(int x,int tot){
	if (x==0)
		return;
	print(pre[x][tot], tot - 1);
	printf("%d ", x);
}
int main(){
	int n, m;
	scanf("%d%d%lld", &n, &m, &t);
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= m;i++)
	{
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		add(x, y, z);
		indeg[y]++;
	}
	for (int i = 1; i <= n;i++)
	{
		if (!indeg[i] && i!=1){
			q.push(i);
		}
	}
	while (!q.empty()){
		int j = q.front();
		q.pop();
		
		for (int i = he[j]; i;i=ne[i])
		{
			int p = v[i];
			indeg[p]--;
			if (!indeg[p] && p!=1){
				q.push(p);
			}
		}
	}
	q.push(1);
	f[1][1] = 0;
	while (!q.empty()){
		int j=q.front();
		q.pop();
		for (int i = he[j]; i; i = ne[i])
		{
			int p = v[i];
			for (int k = 1; k <= n;k++)
			{
				if (f[j][k]==-1)
					continue;
				if (1ll * f[j][k] + 1ll * w[i] > t)
					continue;
				if (f[p][k + 1] == -1 || 1ll*f[p][k + 1] > 1ll*f[j][k] + 1ll*w[i]){
					f[p][k + 1] = f[j][k] + w[i];
					pre[p][k + 1] = j;
				}
			}
			indeg[p]--;
			if (!indeg[p]){
				q.push(p);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n;i++)
	{
		if (~f[n][i] && f[n][i]<=t){
			ans = i;
		}
	}
	printf("%d\n", ans);
	print(n, ans);
	return 0;
}
