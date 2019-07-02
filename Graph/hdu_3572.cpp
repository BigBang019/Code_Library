#include<bits/stdc++.h>
using namespace std;
namespace DINIC{
    using namespace std;
    typedef long long ll;
    const int N = 1e6 + 5;

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
        cnt = -1;
        memset(he, -1, sizeof(he));
        memset(ne, -1, sizeof(ne));
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
}
using namespace DINIC;

void work(int cas){
    scanf("%d%d", &n, &m);
    init();
    s = n + 501;
    e = n + 502;
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        int p, s, en;
        scanf("%d%d%d", &p, &s, &en);
        sum += p;
        add(i, e, p);
        add(e, i, 0);
        for (int j = s; j <= en;j++)
        {
            add(n + j, i, 1);
            add(i, n + j, 0);
        }
    }
    for (int i = 1; i <= 500;i++)
    {
        add(s, i + n, m);
        add(i + n, s, 0);
    }
    printf("Case %d: %s\n\n", cas, Dinic() == sum ? "Yes" : "No");
}
int main(){
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t;i++)
    {
        work(i);
    }
    return 0;
}
