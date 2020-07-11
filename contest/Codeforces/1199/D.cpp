// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second;
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
int tree[N << 2], lazy[N << 2];
void build(int x,int l,int r){
    lazy[x] = 0;
    if (l==r){
        scanf("%d", &tree[x]);
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
}
void pushdown(int x,int l,int r){
    if (lazy[x]==0)
        return;
    int mid = l + r >> 1;
    lazy[2 * x] = max(lazy[2 * x], lazy[x]);
    lazy[2 * x + 1] = max(lazy[2 * x + 1], lazy[x]);
    if (mid+1==r){
        tree[2 * x + 1] = max(tree[2 * x + 1], lazy[x]);
        lazy[2 * x + 1] = 0;
    }
    if (l==mid){
        tree[2 * x] = max(tree[2 * x], lazy[x]);
        lazy[2 * x] = 0;
    }
    lazy[x] = 0;
}
void update(int x,int l,int r,int p,int v){
    if (l==r){
        tree[x] = v;
        return;
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    if (p<=mid)
        update(2 * x, l, mid, p, v);
    else
        update(2 * x + 1, mid + 1, r, p, v);
}
int query(int x,int l,int r,int p){
    if (l==r){
        if (lazy[x])
            tree[x] = max(tree[x], lazy[x]);
        return tree[x];
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    if (p<=mid)
        return query(2 * x, l, mid, p);
    else
        return query(2 * x + 1, mid + 1, r, p);
}
int main(){
    int n;
    scanf("%d", &n);
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--){
        int op, p, x;
        scanf("%d%d", &op, &p);
        if (op==1){
            scanf("%d", &x);
            update(1, 1, n, p, x);
        }else{
            lazy[1] = max(lazy[1], p);
        }
    }
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", query(1, 1, n, i));
    }
    return 0;
}
