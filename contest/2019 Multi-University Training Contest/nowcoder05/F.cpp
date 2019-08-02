/********************************************
  最大团问题的补问题是最大独立集问题
  最大独立集=点数-最小点覆盖
  最大独立集的点集可以从残余图上寻找
********************************************/
// #pragma GCC optimize(2)
#include<bits/stdc++.h>
namespace DINIC{
    using namespace std;
    typedef long long ll;
    const int N = 1e5 + 5;

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
int a[N];
vector<int> ans;
bool is_source[N];
int main(){
    init();
    scanf("%d", &n);
    s = n + 1;
    e = n + 2;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        if (__builtin_popcount(a[i])&1)
            is_source[i] = 1;
        if (is_source[i]){
            add(s, i, 1);
            add(i, s, 0);
        }
        else{
            add(i, e, 1);
            add(e, i, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (__builtin_popcount(a[i]^a[j])==1){
                if (is_source[i]){
                    add(i, j, 1);
                    add(j, i, 0);
                }
            }
        }
    }
    printf("%d\n", n - Dinic());
    bfs();
    for (int i = 1; i <= n;i++)
    {
        if (dep[i]!=0){
            if (is_source[i])
                ans.push_back(a[i]);
        }else{
            if (!is_source[i])
                ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < ans.size();i++)
    {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
