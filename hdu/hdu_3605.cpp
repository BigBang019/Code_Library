#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;


bool maze[N][15];
map<ll, int> mem;//code->tot
map<int, int> f;//tot->num
int tot;
bool vis[N];

int s, e, n, m;
queue<int> q;
int dep[N], cur[N];

int cnt, he[N], v[N], w[N], ne[N];
void add(int x,int y,int z){
    cnt++;
    ne[cnt] = he[x];
    v[cnt] = y;
    w[cnt] = z;
    he[x] = cnt;
}
void init(){
    tot = 0;
    cnt = -1;
    memset(he, -1, sizeof(he));
    memset(ne, -1, sizeof(ne));
    memset(vis, 0, sizeof(vis));
    f.clear();
    mem.clear();
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	while (!q.empty()) q.pop();
	dep[s]=1;
	q.push(s);
	while (!q.empty()){
		int j=q.front();
		q.pop();
		for (int i=he[j];i>-1;i=ne[i]){
			int p=v[i];
			if (w[i] && !dep[p]){
				dep[p]=dep[j]+1;
				q.push(p);
			}
		}
	}
	if (dep[e]==0) return 0;
	return 1;
}
int dfs(int u,int dist){
	if (u==e) return dist;
	else {
		for (int& i=cur[u];i>-1;i=ne[i]){
			int p=v[i];
			if (!w[i] || dep[p]<=dep[u]) continue;
			int di=dfs(p,min(dist,w[i]));
			if (di){
				w[i]-=di;
				w[i^1]+=di;
				return di;
			}
		}
	}
	return 0;
}
int Dinic(){
	int ans=0;
	while (bfs()){
        for (int i = 1; i <= e; i++)
        {
            cur[i]=he[i];
		}
		while (int di=dfs(s,INT_MAX)){
			ans+=di;
		}
	}
	return ans;
}


ll code(bool *a){
    ll ans = 0;
    for (int i = 1; i <= m;i++)
    {
        if (a[i])
            ans += (1 << (i - 1));
    }
    return ans;
}
int main(){
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                scanf("%d", &maze[i][j]);
            }
            ll tmp = code(maze[i]);
            if (mem.count(tmp)){//1
                int id = mem[tmp];
                f[id]++;
            }else{//0
                tot++;
                mem[tmp] = tot;
                f[tot] = 1;
            }
        }
        for (int i = 1; i <= n;i++)
        {
            ll tmp = code(maze[i]);
            int id = mem[tmp];
            if (vis[id])
                continue;
            for (int j = 1; j <= m;j++)
            {
                if (maze[i][j]){
                    add(id, tot + j, f[id]);
                    add(tot + j, id, 0);
                }
            }
            vis[id] = 1;
        }
        s = tot + m + 1;
        e = tot + m + 2;
        for (int i = 1; i <= m;i++)
        {
            int x;
            scanf("%d", &x);
            add(i + tot, e, x);
            add(e, i + tot, 0);
        }
        for (int i = 1; i <= tot;i++)
        {
            int wi = f[i];
            add(s, i, wi);
            add(i, s, 0);
        }
        printf("%s\n", Dinic() == n ? "YES" : "NO");
    }
    return 0;
}
