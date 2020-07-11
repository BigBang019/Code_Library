#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int R = 1e6;
struct D{
    ll c, p;
    int v;
    D(){}
    D(ll c, ll p, int v) : c(c), p(p), v(v){}
};
vector<D> d[N];
ll tree[N * 4], sum[N * 4];
int n, m, k;
ll ans = 0;
void up(int x){
    tree[x] = tree[2 * x] + tree[2 * x + 1];
    sum[x] = sum[2 * x] + sum[2 * x + 1];
}
void build(int x,int l,int r){
    if (l==r){
        tree[x] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    up(x);
}
void update(int x,int l,int r,ll p,ll v){
    if (l==r){
        tree[x] += v;
        sum[x] = tree[x] * l;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(2 * x, l, mid, p, v);
    else
        update(2 * x + 1, mid + 1, r, p, v);
    up(x);
}
ll query(int x,int l,int r,int k){
    int mid = l + r >> 1;
    if (l==r){
        return min(sum[x], (1ll * k) * l);
    }
    if (tree[2*x]>=k)
        return query(2 * x, l, mid, k);
    else
        return query(2 * x + 1, mid + 1, r, k - tree[2 * x]) + sum[2 * x];
}
int main(){
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= m;i++)
    {
        int l, r;
        ll c, p;
        scanf("%d%d%lld%lld", &l, &r, &c, &p);
        d[l].push_back(D(c, p, 1));
        d[r + 1].push_back(D(c, p, -1));
    }
    build(1, 1, R);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < d[i].size();j++)
        {
            ll c = d[i][j].c, p = d[i][j].p;
            int v = d[i][j].v;
            update(1, 1, R, p, c * v);
        }
        ans += query(1, 1, R, k);
    }
    printf("%lld\n", ans);
    return 0;
}
