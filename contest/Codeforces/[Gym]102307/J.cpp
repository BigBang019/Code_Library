#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m;
ll tree[N << 2];
ll mn[N << 2];
ll lazy[N << 2];
ll num_of_not0[N << 2];

void up(int x)
{
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
    num_of_not0[x] = num_of_not0[x << 1] + num_of_not0[x << 1 | 1];
}
void pushdown(int x,int l,int r){
    if (lazy[x]==0)
        return;
    int mid = l + r >> 1;
    mn[x << 1] -= lazy[x];
    mn[x << 1 | 1] -= lazy[x];

    tree[x << 1] -= lazy[x] * num_of_not0[x << 1];
    tree[x << 1 | 1] -= lazy[x] * num_of_not0[x << 1 | 1];

    lazy[x << 1] += lazy[x];
    lazy[x << 1 | 1] += lazy[x];
    lazy[x] = 0;
}
void update(int x,int l,int r,int ql,int qr,ll v){
    if (l>qr || r<ql || ql>qr)
        return;
    if (num_of_not0[x]==0) return;
    if (l==r){
        tree[x] -= v;
        mn[x] = tree[x] = max(0ll, tree[x]);
        if (tree[x]==0){
            num_of_not0[x] = 0;
            mn[x] = 0x7fffffff;
        }
        return;
    }
    if (ql<=l && qr>=r && mn[x]>v){
        mn[x] -= v;
        tree[x] -= v * num_of_not0[x];
        lazy[x] += v;
        return;
    }
    int mid = l + r >> 1;
    pushdown(x, l, r);
    update(x << 1, l, mid, ql, qr, v);
    update(x << 1 | 1, mid + 1, r, ql, qr, v);
    up(x);
}
ll query(int x,int l,int r,int ql,int qr){
    if (l>qr ||r<ql || qr<ql) return 0;
    if (ql <= l && qr >= r){
        return tree[x];
    }
    int mid = l + r >> 1;
    pushdown(x, l, r);
    return query(x << 1, l, mid, ql, qr) + query(x << 1 | 1, mid + 1, r, ql, qr);
}
void build(int x, int l, int r)
{
    if (l==r){
        scanf("%lld", &tree[x]);
        mn[x] = tree[x];
        num_of_not0[x] = (tree[x] != 0);
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    up(x);
}
int main()
{
    // clock_t st = clock();
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--){
        int op, l, r;
        ll s;
        scanf("%d%d%d", &op, &l, &r);
        if (op==1){
            if (l<=r)
                printf("%lld\n", query(1, 1, n, l, r));
            else
                printf("%lld\n", query(1, 1, n, l, n) + query(1, 1, n, 1, r));
        }
        else
        {
            scanf("%lld", &s);
            if (l<=r)
                update(1, 1, n, l, r, s);
            else
                update(1, 1, n, 1, r, s), update(1, 1, n, l, n, s);
        }
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC;
    return 0;
}
