#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=100010;
const long long INF=1E17+10;


struct Edge{
	int from;
	int to;
	long long w;
	int next;
} edge[maxn];

int head[maxn];
int tot;
int n,m;

long long d[maxn];
long long cd[maxn];
int vis[maxn];

void init() {
	tot=-1;
	for (int i=0;i<n;i++) {
		head[i]=-1;
	}
}

inline void addedge(int x,int y, long long w) {
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	edge[tot].w=w;
	head[x]=tot;
//	tot++;
//	edge[tot].next=head[y];
//	edge[tot].from=y;
//	edge[tot].to=x;
//	edge[tot].w=w;
//	head[y]=tot;
}



void spfa(int s){
    for (int i = 0; i <n;i++) {
        d[i] = INF;
        vis[i] = 0;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int j = q.front();
        q.pop();
        for (int i = head[j]; i!=-1; i = edge[i].next) {
//        	if (i%2!=0) {
//        		continue;
//			}
            int p = edge[i].to;
            if (d[p]>d[j]+edge[i].w){
                d[p] = d[j] + edge[i].w;
                if (!vis[p]){
                    q.push(p);
                    vis[p] = 1;
                }
            }
        }
        vis[j] = 0;
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
			long long w;
			scanf("%d%d%lld", &x,&y, &w);
			addedge(x,y,w);
		}
		for (int i=1;i<=6;i++) {
			int S,T;
			scanf("%d%d", &S,&T);
			spfa(T);
			long long ans=-d[S];
			printf("%lld\n", ans);
			addedge(S,T,ans);
		}
	}
	return 0;
} 
