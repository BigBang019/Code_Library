/*
	除了最后一块，每个块大小都保证在[m,2m]之间
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
int cnt, he[N], ne[N * 2], v[N * 2];
int st[N], top, tot, belong[N], root[N];
int n, m;
void add(int x,int y){
	cnt++;
	ne[cnt] = he[x];
	v[cnt] = y;
	he[x] = cnt;
}
void dfs(int x,int fa){	//每次节点遍历完毕入站
	int low = top;		//保留栈当前栈底，栈底为进入此节点前的栈顶，目的是防止贪心导致的不连通
	for (int i = he[x]; i;i=ne[i])
	{
		int p = v[i];
		if (p==fa)
			continue;
		dfs(p, x);
		if (top-low>=m){
			root[++tot] = x;
			while(top!=low)
				belong[st[top--]] = tot;
		}
	}
	st[++top] = x;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n;i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x,y);
		add(y,x);
	}
	dfs(1, 0);
	while (top)//最后的元素直接被加入最后的块
		belong[st[top--]] = tot;
	if (tot==0)
		printf("0\n");
	else {
		printf("%d\n",tot);
		for (int i = 1; i <= n;i++)
		{
			printf("%d ", belong[i]);
		}
		printf("\n");
		for (int i = 1; i <= tot;i++)
		{
			printf("%d ", root[i]);
		}
	}
	return 0;
}
