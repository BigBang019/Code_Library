#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
int dp[4 * N][26];
int n, fa[N];
int dfsn, seq[N], first[N], dep[N];

int cnt, he[N], ne[N * 2], v[N * 2];
void add(int x,int y){
    cnt++;
    ne[cnt] = he[x];
    v[cnt] = y;
    he[x] = cnt;
}
void dfs(int x,int d){
    dep[x] = d;
    seq[++dfsn] = x;
    first[x] = dfsn;
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fa[x])
            continue;
        dfs(p, d + 1);
        seq[++dfsn] = x;
    }
}
void init(){
    cnt = 0;
    memset(he, 0, sizeof(he));
    memset(fa, 0, sizeof(fa));
}
void ST(){
    for (int i = 1; i <= dfsn;i++)
    {
        dp[i][0] = seq[i];
    }
    for (int j = 1; (1 << j) <= dfsn;j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= dfsn; i++)
        {
            int a = dp[i][j - 1];
            int b = dp[i + (1 << (j - 1))][j - 1];
            //cout << i << " " << j << " " << a << " " << b << endl;
            dp[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
}
int lca(int x,int y){
    int ix = first[x], iy = first[y];
    if (ix>iy)
        swap(ix, iy);
    int k = 0;
    while ((1 << (1 + k)) <= iy - ix + 1)
        k++;
    int a = dp[ix][k];
    int b = dp[iy - (1 << k) + 1][k];
    return dep[a] < dep[b] ? a : b;
}
void work(){
    scanf("%d", &n);
    init();
    for (int i = 1; i < n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        fa[y] = x;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n;i++)
    {
        if (fa[i]==0){
            dfs(i, 0);
            break;
        }
    }
    ST();
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", lca(x, y));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        work();
    }
    return 0;
}
