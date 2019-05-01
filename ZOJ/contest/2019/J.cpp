#include<cstdio>
#include<queue>

using namespace std;
const int maxn=1000005;
struct node{
	int to;
	int next;
} a[maxn<<2];
int head[maxn];
int vis[maxn];

int tot;
int n,m;
int pre[maxn];

int ans[maxn];
int ansn;
int anss;




int find(int p) {
	while (pre[p]!=p) {
		pre[p]=pre[pre[p]];
		p=pre[p];
	}
	return p;
}

inline void addedge(int x,int y) {
	tot++;
	a[tot].next=head[x];
	a[tot].to=y;
	head[x]=tot;
	tot++;
	a[tot].next=head[y];
	a[tot].to=x;
	head[y]=tot;
	
	int xx=find(x);
	int yy=find(y);
	if (xx<yy) {
		pre[yy]=pre[xx];
	} else {
		pre[xx]=pre[yy];
	}
}

priority_queue<int, vector<int>, greater<int> > q;


inline void bfs() {
	while (!q.empty()) {
		int u=q.top();
		
//		printf("fuck: %d\n", u);
		
		q.pop();
		ansn++;
		ans[ansn]=u;
		for (int p=head[u];p!=0;p=a[p].next) {
			int v=a[p].to;
			if (vis[v]) {
				continue;
			}
			vis[v]=true;
			q.push(v);
		}
	}
}

inline void init() {
	for (int i=1;i<=n;i++) {
		vis[i]=false;
		head[i]=0;
		pre[i]=i;
	} tot=0;
	while (!q.empty()){
		q.pop();
	}
	anss=0;
	ansn=0;
}

int main() {
	int  T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n,&m);
		init();
		for (int i=1;i<=m;i++) {
			int x,y;
			scanf("%d%d", &x,&y);
			addedge(x,y);
		}
		
//		for (int i=1;i<=n;i++) {
//			printf("%d ", pre[i]);
//		}printf("\n");
		
		for (int i=1;i<=n;i++) {
			if (pre[i]!=i) {
				continue;
			}
			if (!vis[pre[i]]) {
				vis[pre[i]]=true;
				q.push(pre[i]);
				anss++;
			}
		}
		bfs();
		printf("%d\n", anss);
		for (int i=1;i<=ansn;i++) {
			printf("%d%s",ans[i], i==ansn? "\n":" ");
		}
	}
	
	return 0;
}
