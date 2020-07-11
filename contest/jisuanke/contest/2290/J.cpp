#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N * 2];
int len;
pair<pair<int,int>,int> qu[N];

int cnt, he[N], w[N*2], v[N*2], ne[N*2];

int dp[N * 4][26], seq[N * 4], first[N], dfsn, dep[N];

int tree[N], sum[N * 40], lc[N * 40], rc[N * 40], tot;

void add(int x,int y,int z){
    cnt++;
    v[cnt] = y;
    w[cnt] = z;
    ne[cnt] = he[x];
    he[x] = cnt;
}
void build(int &rt,int l,int r){
    rt = ++tot;
    sum[rt] = 0;
    lc[rt] = rc[rt] = -1;
    int mid = l + r >> 1;
    if (l==r){
        return;
    }
    build(lc[rt], l, mid);
    build(rc[rt], mid + 1, r);
}
void insert(int last,int l,int r,int v,int &rt){
    rt = ++tot;
    lc[rt] = lc[last];
    rc[rt] = rc[last];
    sum[rt] = sum[last] + 1;
    int mid = l + r >> 1;
    if (l==r)
        return;
    if (v<=mid)
        insert(lc[last], l, mid, v, lc[rt]);
    else
        insert(rc[last], mid + 1, r, v, rc[rt]);
}
int query(int last,int l,int r,int k,int now){
    int mid = l + r >> 1;
    if (l>k)
        return 0;
    if (r<=k)
        return sum[now] - sum[last];
    return query(lc[last], l, mid, k, lc[now]) + query(rc[last], mid + 1, r, k, rc[now]);
}
void dfs(int x,int fat,int d){
    dep[x] = d;
    seq[++dfsn] = x;
    first[x] = dfsn;
    for (int i = he[x]; i; i = ne[i])
    {
        int p = v[i];
        if (p==fat)
            continue;
        int k = lower_bound(a + 1, a + 1 + len, w[i]) - a;
        insert(tree[x], 1, len, k, tree[p]);
        dfs(p, x, d + 1);
        seq[++dfsn] = x;
    }
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
            dp[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
}
int lca(int x,int y){
    int ix = first[x], iy = first[y];
    if (ix>iy)
        swap(ix, iy);
    int k = 0;
    while((1<<(k+1))<=iy-ix+1)
        k++;
    int a = dp[ix][k];
    int b = dp[iy - (1 << k) + 1][k];
    return dep[a] < dep[b] ? a : b;
}
int main(){
    len = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n;i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        add(x, y, v);
        add(y, x, v);
        a[++len] = v;
    }
    for (int i = 1; i <= m;i++)
    {
        scanf("%d%d%d", &qu[i].first.first, &qu[i].first.second, &qu[i].second);
        a[++len] = qu[i].second;
    }
    sort(a + 1, a + 1 + len);
    len = unique(a + 1, a + 1 + len) - a - 1;
    tot = 0;
    build(tree[1], 1, len);
    dfs(1, 0, 0);
    ST();
    for (int i = 1; i <= m;i++)
    {
        int x, y, k;
        x = qu[i].first.first;
        y = qu[i].first.second;
        k = qu[i].second;
        k = lower_bound(a + 1, a + len + 1, k) - a;
        int ac = lca(x, y);
        int tmp1 = query(tree[ac], 1, len, k, tree[x]);
        int tmp2 = query(tree[ac], 1, len, k, tree[y]);
        printf("%d\n", tmp1 + tmp2);
    }

    return 0;
}
