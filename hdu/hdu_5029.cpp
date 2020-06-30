#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int L = 1e5;
int tree[N * 4], mx[N * 4];
int n, m;
int id[N], tot, topf[N], fa[N], rnk[N], son[N], dep[N], sz[N];
int cnt, he[N], ne[N * 2], v[N * 2];
int ans[N];
void add(int x,int y){
    cnt++;
    ne[cnt] = he[x];
    v[cnt] = y;
    he[x] = cnt;
}
void init(){
    cnt = 0;
    memset(he, 0, sizeof(he));
    memset(son, 0, sizeof(son));
}
void dfs1(int x,int fat,int dp){
    fa[x] = fat;
    dep[x] = dp;
    sz[x] = 1;
    int mi = 0;
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fat)
            continue;
        dfs1(p, x, dp + 1);
        if (mi<sz[p]){
            son[x] = p;
            mi = sz[p];
        }
        sz[x] += sz[p];
    }
}
void dfs2(int x,int fa,int top){
    id[x] = ++tot;
    rnk[tot] = x;
    topf[x] = top;
    if (!son[x])
        return;
    dfs2(son[x], x, top);
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fa || p==son[x])
            continue;
        dfs2(p, x, p);
    }
}
void build(int x,int l,int r){
    tree[x] = 0;
    if (l==r){
        mx[x] = l;
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
}
void up(int x){
    if (tree[2*x]>=tree[2*x+1]) {
        tree[x] = tree[2 * x];
        mx[x] = mx[2 * x];
    }else{
        tree[x] = tree[2 * x + 1];
        mx[x] = mx[2 * x + 1];
    }
}
void update(int x,int l,int r,int p,int v){
    if (l==r){
        tree[x] += v;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(2 * x, l, mid, p, v);
    else
        update(2 * x + 1, mid + 1, r, p, v);
    up(x);
}
void build(){
    tot = 0;
    dfs1(1, 0, 1);
    dfs2(1, 0, 1);
    build(1, 1, L);
}
vector<int> a[N], d[N];
void aRange(int x,int y,int z){
    while (topf[x]!=topf[y]){
        if (dep[topf[x]]<dep[topf[y]])
            swap(x, y);
        int top = topf[x];
        a[id[top]].push_back(z);
        d[id[x] + 1].push_back(z);
        x = fa[top];
    }
    if (dep[x]>dep[y])
        swap(x, y);
    a[id[x]].push_back(z);
    d[id[y] + 1].push_back(z);
}
int main(){
    while (scanf("%d%d",&n,&m) && (n || m)){
        init();
        for (int i = 1; i <= n;i++)
        {
            a[i].clear();
            d[i].clear();
        }
        for (int i = 1; i < n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        build();
        for (int i = 1; i <= m;i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            aRange(x, y, z);
        }
        
        for (int i = 1; i <= n;i++)
        {
            for (int j = 0; j < a[i].size();j++)
            {
                update(1, 1, L, a[i][j], 1);
            }
            for (int j = 0; j < d[i].size();j++)
            {
                update(1, 1, L, d[i][j], -1);
            }
            if (tree[1])
                ans[rnk[i]] = mx[1];
            else
                ans[rnk[i]] = 0;
        }
        for (int i = 1; i <= n;i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
