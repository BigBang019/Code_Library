// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e5 + 5;
const int MOD = 998244353;
struct P{
    int x, y, v;
    P(){}
    P(int x, int y, int v) : x(x), y(y), v(v){}
};
int tree[N << 3], lazy[N << 3];
vector<P> a;
vector<int> b;
void Init_Hash(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int has(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
void build(int x,int l,int r){
    tree[x] = lazy[x] = 0;
    if (l==r){
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
}
void pushdown(int x){
    if (!lazy[x])
        return;
    tree[2*x] += lazy[x];
    tree[2 * x + 1] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}
void up(int x){
    tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
void update(int x,int l,int r,int ql,int qr,int v){
    if (ql>r || qr<l)
        return;
    if (ql<=l && qr>=r){
        tree[x] += v;
        lazy[x] += v;
        return;
    }
    pushdown(x);
    int mid = l + r >> 1;
    update(2 * x, l, mid, ql, qr, v);
    update(2 * x + 1, mid + 1, r, ql, qr, v);
    up(x);
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        b.pb(y);
        b.pb(y + k);
        a.pb(P(x, y, 1));
        a.pb(P(x + k + 1, y, -1));
    }
    Init_Hash();
    int len = b.size();
    build(1, 1, len);
    sort(a.begin(), a.end(), [](P a, P b) {
        return a.x < b.x;
    });
    int ans = 0;
    for (int i = 0; i < a.size();i++)
    {
        int x = a[i].x, y = a[i].y, v = a[i].v;
        int l = has(y), r = has(y + k);
        update(1, 1, len, l, r, v);
        ans = max(ans, tree[1]);
    }
    printf("%d\n", ans);
    return 0;
}
