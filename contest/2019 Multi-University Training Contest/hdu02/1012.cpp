#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int tree[N * 4];
int lazy[N * 4];
int n, c, k;
vector<int> vc[N];
void pushdown(int x,int l,int r){
    if (lazy[x]==0)
        return;
    int mid = l + r >> 1;
    tree[2 * x] += lazy[x];
    tree[2 * x + 1] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}
void up(int x){
    tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
void update(int x,int l,int r,int ql,int qr,int v){
    if (l>qr || r<ql || ql>qr)
        return;
    if (ql<=l && qr>=r){
        tree[x] += v;
        lazy[x] += v;
        return;
    }
    int mid = l + r >> 1;
    pushdown(x, l, r);
    update(2 * x, l, mid, ql, qr, v);
    update(2 * x + 1, mid + 1, r, ql, qr, v);
    up(x);
}
int query(int x,int l,int r){
    if (l==r){
        return l;
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    if (tree[2*x]>=c){
        return query(2 * x, l, mid);
    }else if (tree[2*x+1]>=c){
        return query(2 * x + 1, mid + 1, r);
    }else
        return -1;
}
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    while (~scanf("%d%d%d", &n, &c, &k))
    {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        for (int i = 1; i <= c;i++)
        {
            vc[i].clear();
            vc[i].push_back(0);
        }
        int ans = 0;
        for (int i = 1; i <= n;i++)
        {
            int x;
            scanf("%d", &x);
            int sz = vc[x].size();
            update(1, 1, n, i, i, c - 1);
            update(1, 1, n, vc[x].back() + 1, i - 1, -1);
            vc[x].push_back(i);
            int p = vc[x].size() - k - 1;
            if (p>=0){
                update(1, 1, n, vc[x][p] + 1, vc[x][p + 1], 1);
            }
            int pos = query(1, 1, n);
            if (~pos){
                ans = max(ans, i - pos + 1);
            }
        }
        printf("%d\n", ans);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
