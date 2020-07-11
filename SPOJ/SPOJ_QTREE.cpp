#include <bits/stdc++.h>
namespace HLD{
    using namespace std;
    typedef long long ll;
    const int N = 1e4 + 5;

    int cnt, he[N], ne[N * 2], v[N * 2];
    ll w[N * 2];

    int son[N], sz[N], id[N], top[N], dep[N], fa[N], idn;

    ll wt[N], a[N], tree[N * 4];

    int n, root;
    void add(int x,int y,ll z){
        cnt++;
        ne[cnt] = he[x];
        w[cnt] = z;
        v[cnt] = y;
        he[x] = cnt;
    }
    void dfs1(int x,int fat,int d){
        dep[x] = d;
        fa[x] = fat;
        sz[x] = 1;
        int heavy = 0;
        for (int i = he[x]; i; i = ne[i])
        {
            int p = v[i];
            if (p==fat)
                continue;
            wt[p] = w[i];
            dfs1(p, x, d+1);
            if (heavy<sz[p]){
                heavy = sz[p];
                son[x] = p;
            }
            sz[x] += sz[p];
        }
    }
    void dfs2(int x,int fa,int topf){
        id[x] = ++idn;
        a[idn] = wt[x];
        top[x] = topf;
        if (!son[x])
            return;
        dfs2(son[x], x, topf);
        for (int i = he[x]; i; i = ne[i])
        {
            int p=v[i];
            if (p==fa || p==son[x])
                continue;
            dfs2(p, x, p);
        }
    }
    void init(){
        cnt = 0;
        memset(he, 0, sizeof(he));
        memset(dep, 0, sizeof(dep));
    }
    void build(int x,int l,int r){
        if (l==r){
            tree[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(2 * x, l, mid);
        build(2 * x + 1, mid + 1, r);
        tree[x] = max(tree[2 * x], tree[2 * x + 1]);
    }
    void insert(int x,int l,int r,int p,ll v){
        if (l==r){
            tree[x] = v;
            return;
        }
        int mid = l + r >> 1;
        if (p<=mid)
            insert(2 * x, l, mid, p, v);
        else
            insert(2 * x + 1, mid + 1, r, p, v);
        tree[x] = max(tree[2 * x] , tree[2 * x + 1]);
    }
    ll query(int x,int l,int r,int ql,int qr){
        if (qr<l || ql>r) return 0;
        int mid = l + r >> 1;
        if (ql<=l && qr>=r)
            return tree[x];
        return max(query(2 * x, l, mid, ql, qr), query(2 * x + 1, mid + 1, r, ql, qr));
    }
    void dec(){
        idn = 0;
        memset(son, 0, sizeof(son));
        dfs1(root, 0, 1);
        dfs2(root, 0, root);
        build(1, 1, n);
    }
    ll qRange(int x,int y){
        ll sum = 0;
        while (top[x]!=top[y]){
            if (dep[top[x]] < dep[top[y]])				//比较top dep
                swap(x, y);
            int topf = top[x];
            sum =max(sum, query(1, 1, n, id[topf], id[x]));
            x = fa[topf];
        }
        if (dep[x]>dep[y])
            swap(x, y);
        sum = max(sum, query(1, 1, n, id[x] + 1, id[y]));
        return sum;
    }
    void aRange(int x, ll v){
        insert(1, 1, n, id[x], v);
    }
}
using namespace HLD;

char s[100];
pair<int, int> edge[N];

void work(){
    init();
    scanf("%d", &n);
    for (int i = 1; i < n;i++)
    {
        int x, y;
        ll z;
        scanf("%d%d%lld", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        edge[i] = make_pair(x, y);
    }
    root = 1;
    dec();
    while (true){
        int x, y;
        ll z;
        scanf(" %s", &s);
        if (s[0]=='Q'){
            scanf("%d%d", &x, &y);
            printf("%lld\n", qRange(x, y));
        }else if (s[0]=='C'){
            scanf("%d%lld", &x, &z);
            int fi = edge[x].first, se = edge[x].second;
            if (dep[fi]>dep[se])
                x = fi;
            else
                x = se;
            aRange(x, z);
        }else{
            break;
        }
    }
}
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    while (t--){
        work();
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
