#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int lc[N * 20], rc[N * 20], tree[N], sum[N * 20];
int tot;
void build(int &rt,int l,int r){
    rt = ++tot;
    sum[rt] = 0;
    if (l==r)
        return;
    int mid = l + r >> 1;
    build(lc[rt], l, mid);
    build(rc[rt], mid + 1, r);
}
void insert(int last,int p,int l,int r,int &rt){
    rt = ++tot;
    lc[rt] = lc[last];
    rc[rt] = rc[last];
    sum[rt] = sum[last] + 1;
    if (l==r)
        return;
    int mid = l + r >> 1;
    if (p<=mid)
        insert(lc[last], p, l, mid, lc[rt]);
    else
        insert(rc[last], p, mid + 1, r, rc[rt]);
}
int query(int last,int now,int l,int r,int k){
    if (l==r)
        return l;
    int mid = l + r >> 1;
    int cnt = sum[lc[now]] - sum[lc[last]];
    if (k<=cnt)
        return query(lc[last], lc[now], l, mid, k);
    else
        return query(rc[last], rc[now], mid + 1, r, k - cnt);
}
void init(){
    tot = 0;
}
int a[N], id[N], n, m;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n;i++)
        {
            scanf("%d",&a[i]);
            id[i] = a[i];
        }
        init();
        sort(a + 1, a + n + 1);
        int cnt = unique(a + 1, a + 1 + n) - a - 1;
        build(tree[0], 1, cnt);
        for (int i = 1; i <= n;i++)
        {
            id[i] = lower_bound(a + 1, a + 1 + cnt, id[i]) - a;
        }
        for (int i = 1; i <= n;i++)
        {
            insert(tree[i - 1], id[i], 1, cnt, tree[i]);
        }
        while(m--){
            int last, now, k;
            scanf("%d%d%d", &last, &now, &k);
            int pos = query(tree[last - 1], tree[now], 1, cnt, k);
            printf("%d\n", a[pos]);
        }
    }
    return 0;
}
