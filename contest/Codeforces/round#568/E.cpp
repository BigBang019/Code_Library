#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
int n, m;
char maze[N][N];
int x1[30], x2[30], y1[30], y2[30];
bool vis[30];
void work(){
	memset(x1, -1, sizeof(x1));
	memset(x2, -1, sizeof(x2));
	memset(y1, -1, sizeof(y1));
	memset(y2, -1, sizeof(y2));
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n;i++)
	{
		scanf(" %s", maze[i]);
	}
	int top = 0;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			if (maze[i][j]=='.')
				continue;
			int t = maze[i][j] - 'a';
			top = max(t + 1, top);
			vis[t] = 1;
			x1[t] = ~x1[t] ? min(x1[t], i) : i;
			x2[t] = max(x2[t], i);
			y1[t] = ~y1[t] ? min(y1[t], j) : j;
			y2[t] = max(y2[t], j);
		}
	}
	for (int i = 0; i < min(26, top); i++)
	{
		int l1 = x1[i], r1 = x2[i], l2 = y1[i], r2 = y2[i];
		if ((r1-l1)*(r2-l2)){
			printf("NO\n");
			return;
		}
	}
	for (int i = 0; i < min(26, top);i++)
	{
		if (!vis[i])
			continue;
		int l1 = x1[i], r1 = x2[i], l2 = y1[i], r2 = y2[i];
		int x = l1, y = l2;
		if (l1==r1){
			for (; y <= r2;y++)
			{
				if (maze[x][y]-'a'<i){
					printf("NO\n");
					return;
				}
			}
		}else{
			for (; x <= r1;x++)
			{
				if (maze[x][y]-'a'<i){
					printf("NO\n");
					return;
				}
			}
		}
	}
	printf("YES\n%d\n", top);
	int tmp = 0;
	for (int i = 0; i < min(26, top);i++)
	{
		if (!vis[i]){
			tmp++;
			continue;
		}
		int l1 = x1[i], r1 = x2[i], l2 = y1[i], r2 = y2[i];
		for (int j = 0; j <= tmp;j++)
		{
			printf("%d %d %d %d\n", l1 + 1, l2 + 1, r1 + 1, r2 + 1);
		}
		tmp = 0;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		work();
	}
	return 0;
}
