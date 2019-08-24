#include <bits/stdc++.h>
namespace DINIC{
    using namespace std;
    typedef long long ll;
    const int N = 1e5 + 5;

    int s, e, n, m;
    queue<int> q;
    int dep[N], cur[N];

    int cnt, he[N], v[N*2], ne[N*2];
    ll w[N*2];
    void add(int x,int y,ll z){
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
    ll dfs(int u,ll dist){
        if (u==e) return dist;
        else {
            for (int& i=cur[u];i>-1;i=ne[i]){
                int p=v[i];
                if (!w[i] || dep[p]<=dep[u]) continue;
                ll di = dfs(p, min(dist, w[i]));
                if (di){
                    w[i]-=di;
                    w[i^1]+=di;
                    return di;
                }
            }
        }
        return 0;
    }
    ll Dinic(){
        ll ans=0;
        while (bfs()){
            for (int i = 1; i <= e; i++)
            {
                cur[i]=he[i];
            }
            while (ll di=dfs(s,INT_MAX)){
                ans+=di;
            }
        }
        return ans;
    }
}
using namespace DINIC;

vector<pair<int, ll> > G[N];
ll d[N];
bool vis[N];
priority_queue < pair<ll, int>, vector < pair<ll, int> >, greater<pair<ll, int> > > pl;
void dij(int s){
    for (int i = 1; i <= n;i++)
    {
        d[i] = -1;
        vis[i] = 0;
    }
    d[s] = 0;
    pl.push(make_pair(0, s));
    while (!pl.empty()){
        int x = pl.top().second;
        pl.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size();i++)
        {
            int p = G[x][i].first;
            ll z = G[x][i].second;
            if (!vis[p] && (d[p]==-1 || d[p] > d[x] + z))
            {
                d[p] = d[x] + z;
                pl.push(make_pair(d[p], p));
            }
        }
    }
}
void work(){
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
    {
        G[i].clear();
    }
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        ll z;
        scanf("%d%d%lld", &x, &y, &z);
        G[x].push_back(make_pair(y, z));
    }
    dij(1);
    if (d[n]==-1){
        printf("0\n");
        return;
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < G[i].size();j++)
        {
            int p = G[i][j].first;
            ll z = G[i][j].second;
            if (~d[i] && ~d[p] && d[p]==d[i]+z){//p向i可以吗
                add(i, p, z);
                add(p, i, 0);
            }
        }
    }
    s = 1;
    e = n;
    printf("%lld\n", Dinic());
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
