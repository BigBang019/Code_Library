#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1050;
int n, c[N][N],q;
int lowbit(int x){
	return x & (-x);
}
void add(int x,int y,int v){
	for (int i = x; i <= n;i+=lowbit(i))
	{
		for (int j = y; j <= n;j+=lowbit(j))
		{
			c[i][j] += v;
		}
	}
}
int query(int x,int y){
	int sum = 0;
	for (int i = x; i > 0;i-=lowbit(i))
	{
		for (int j = y; j > 0;j-=lowbit(j)){
			sum += c[i][j];
		}
	}
	return sum;
}
void add(int x1,int x2,int y1,int y2){
	add(x1, y1, 1);
	add(x1, y2 + 1, -1);
	add(x2 + 1, y1, -1);
	add(x2 + 1, y2 + 1, 1);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&q);
		memset(c,0,sizeof(c));
		while (q--){
			char ch;
			scanf(" %c",&ch);
			if (ch=='C'){
				int x1, y1, x2, y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				add(x1,x2,y1,y2);
			}else{
				int x, y;
				scanf("%d%d", &x, &y);
				int tmp = query(x, y);
				printf("%d\n", tmp & 1);
			}
		}
		printf("\n");
	}
	return 0;
}
