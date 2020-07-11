#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=500010;
const long long INF=1E17+10;


struct Edge{
	int from;
	int to;
	int next;
} edge[maxn];

int head[maxn];
int tot;
int n,m;

double f[maxn];
double g[maxn];

int inde[maxn];
int outde[maxn];
int st[maxn];
int top;

void init() {
	tot=0;
	top=0;
	for (int i=0;i<=n;i++) {
		head[i]=0;
		inde[i]=0;
		outde[i]=0;
		f[i]=0;
		g[i]=0;
	}
}

inline void addedge(int x,int y) {
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	head[x]=tot;
	inde[y]++;
	outde[x]++;
}

queue<int> q;


void bfs(int s) {
	while (!q.empty()) {
		q.pop();
	}
	q.push(s);
	while (!q.empty()) {
		int u=q.front();
		top++;
		st[top]=u;
		q.pop();
		for (int p=head[u];p!=0;p=edge[p].next){
			int v=edge[p].to;
			inde[v]--;
			if (inde[v]==0) {
				q.push(v);
			}
		}
	}
	top--;
	while (top!=0) {
		int u=st[top];
		top--;
		double d=outde[u];
		
		double sum1=0;
		double sum2=0;
		
		for (int p=head[u];p!=0;p=edge[p].next){
			int v=edge[p].to;
			sum1+=f[v];
			sum2+=f[v]+g[v];
		}
		f[u]=(sum1+d+1)/d;
		g[u]=(sum2+f[u]+d+1)/d;
	}
	
}




int main() {
	int rd;
	scanf("%d", &rd);
	while (rd--){
		scanf("%d%d", &n,&m);
		init();
		for (int i=1;i<=m;i++) {
			int x,y;
			scanf("%d%d", &x,&y);
			addedge(x,y);
		}
		bfs(1);
		printf("%.2f\n",g[1]);
	}
	return 0;
} 
