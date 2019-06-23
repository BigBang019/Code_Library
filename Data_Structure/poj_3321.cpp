#include<cstdio>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int id[N], sz[N], c[N], dfn;
int cnt, he[N], ne[N * 2], v[N * 2];
void add(int x,int y){
	cnt++;
	ne[cnt] = he[x];
	v[cnt] = y;
	he[x] = cnt;
}
void dfs(int x,int fa){
	id[x] = ++dfn;
	sz[x] = 1;
	for (int i = he[x]; i;i=ne[i])
	{
		int p = v[i];
		if (p==fa)
			continue;
		dfs(p, x);
		sz[x] += sz[p];
	}
}
int lowbit(int x){
	return x & (-x);
}
void update(int x,int v){
	for (int i = x; i <= n;i+=lowbit(i))
	{
		c[i] += v;
	}
}
int query(int x){
	int sum = 0;
	for (int i = x; i > 0;i-=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i < n;i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n;i++)
	{
		update(id[i], 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m;i++)
	{
		char ch;
		int x;
		scanf(" %c%d", &ch, &x);
		if (ch=='C'){
			int tmp = query(id[x]) - query(id[x] - 1);
			update(id[x], tmp ? -1 : 1);
		}else{
			printf("%d\n", query(id[x] + sz[x] - 1) - query(id[x] - 1));
		}
	}
	return 0;
}
