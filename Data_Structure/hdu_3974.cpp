#include<bits/stdc++.h>
namespace HLD{
    using namespace std;
    typedef long long ll;
    const int N = 5e4 + 5;

    int cnt, he[N], ne[N * 2], v[N * 2];

    int sz[N], id[N], tot;

    ll tree[N << 2], lazy[N << 2];

    int indeg[N];

    void init(){
        cnt = 0;
        memset(he, 0, sizeof(he));
        memset(indeg, 0, sizeof(indeg));
    }
    void add(int x,int y){
        cnt++;
        ne[cnt] = he[x];
        v[cnt] = y;
        he[x] = cnt;
    }
    void dfs1(int x,int fa){
        sz[x] = 1;
        for (int i = he[x]; i;i=ne[i])
        {
            int p = v[i];
            if (p==fa)
                continue;
            dfs1(p, x);
            sz[x] += sz[p];
        }
    }
    void dfs2(int x,int fa){
        tot++;
        id[x] = tot;
        for (int i = he[x]; i;i=ne[i])
        {
            int p = v[i];
            if (p==fa)
                continue;
            dfs2(p, x);
        }
    }
    void pushup(int x){
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }
    void pushdown(int x,int l,int r){
        if (!lazy[x])
            return;
        tree[2 * x] = lazy[x];
        tree[2 * x + 1] = lazy[x];
        lazy[2 * x] = lazy[x];
        lazy[2 * x + 1] = lazy[x];
        lazy[x] = 0;
    }
    void build(int x,int l,int r){
        lazy[x] = 0;
        if (l==r){
            tree[x] = -1;
            return;
        }
        int mid = l + r >> 1;
        build(2 * x, l, mid);
        build(2 * x + 1, mid + 1, r);
        pushup(x);
    }
    void insert(int x,int l,int r,int ql,int qr,ll v){
        if (qr<l||ql>r)
            return;
        if (ql<=l&&qr>=r){
            tree[x] = v * (r - l + 1);
            lazy[x] = v;
            return;
        }
        pushdown(x, l, r);
        int mid = l + r >> 1;
        insert(2 * x, l, mid, ql, qr, v);
        insert(2 * x + 1, mid + 1, r, ql, qr, v);
        pushup(x);
    }
    ll query(int x,int l,int r,int p){
        if (l==r){
            return tree[x];
        }
        int mid = l + r >> 1;
        pushdown(x, l, r);
        if (p<=mid)
            return query(2 * x, l, mid, p);
        else
            return query(2 * x + 1, mid + 1, r, p);
    }
    void build(int root){
        tot = 0;
        dfs1(root, 0);
        dfs2(root, 0);
        build(1, 1, tot);
    }
    void aSon(int x,ll v){
        int l = id[x], r = id[x] + sz[x] - 1;
        insert(1, 1, tot, l, r, v);
    }
    ll qSon(int x){
        return query(1, 1, tot, id[x]);
    }
}
using namespace HLD;
int n;
int main(){
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t;cas++)
    {
        init();
        printf("Case #%d:\n", cas);
        scanf("%d", &n);
        for (int i = 1; i < n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
            indeg[x]++;
        }
        for (int i = 1; i <= n;i++){
            if (indeg[i]==0){
                build(i);
                break;
            }
        }
        int q;
        scanf("%d",&q);
        while(q--){
            char ch;
            int x;
            ll y;
            scanf(" %c",&ch);
            if (ch=='C'){
                scanf("%d",&x);
                printf("%lld\n", qSon(x));
            }else{
                scanf("%d%lld",&x,&y);
                aSon(x, y);
            }
        }
    }
    return 0;
}
