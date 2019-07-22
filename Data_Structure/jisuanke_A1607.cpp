#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int B = 30;
struct NODE{
    int b[B + 3];
    void init(){
        memset(b, 0, sizeof(b));
    }
    bool insert(int x){
        for (int i = B; ~i && x;i--)
        {
            if (x&(1<<i)){
                if (!b[i]) {
                    b[i] = x;
                    break;
                }
                x ^= b[i];
            }
        }
        return x > 0;
    }
    int Max(int x){
        int res = x;
        for (int i = B; ~i;i--)
        {
            res = max(res, res ^ b[i]);
        }
        return res;
    }
} tree[N * 4], ans;
int n, m, a[N], k;
NODE merge(NODE a,NODE b){
    NODE res = a;
    for (int i = B; ~i;i--) if (b.b[i]) res.insert(b.b[i]);
    return res;
}
void build(int x,int l,int r){
    tree[x].init();
    if (l==r){
        tree[x].insert(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}
void query(int x,int l,int r,int ql,int qr){
    if (ql>r || qr<l)
        return;
    if (ql<=l && qr>=r){
        ans = merge(ans, tree[x]);
        return;
    }
    int mid = l + r >> 1;
    query(2 * x, l, mid, ql, qr);
    query(2 * x + 1, mid + 1, r, ql, qr);
}
void update(int x,int l,int r,int p,int v){
    if (l==r){
        tree[x].insert(v);
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(2 * x, l, mid, p, v);
    else
        update(2 * x + 1, mid + 1, r, p, v);
    tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}
void work(){
    scanf("%d%d%d", &n, &m, &k);
    int len = 2 * n;
    k = ~k;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", a + i);
        a[i] &= k;
    }
    k = ~k;
    build(1, 1, n);
    for (int i = 1; i <= m;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ans.init();
        query(1, 1, n, l, r);
        printf("%d\n", ans.Max(0) | k);
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
