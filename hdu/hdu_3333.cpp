#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, S;
int a[N], b[N], c[N];
struct Q{
    int l, r, p;
    Q(){}
    Q(int l, int r, int p) : l(l), r(r), p(p){}
    bool operator < (const Q &b){
        if (l / S == b.l / S)
            return r < b.r;
        else
            return l / S < b.l / S;
    }
} qu[N];
ll ans[N], now;
int vis[N];
void init(){
    S = sqrt(n);
    now = 0;
    memset(vis, 0, sizeof(vis));
}
void move(int pos,int v){
    int x = b[pos];
    if (~v){//1
        if (!vis[x]){
            now += a[pos];
        }
        vis[x]++;
    }else{
        if (vis[x]==1){
            now -= a[pos];
        }
        vis[x]--;
    }
}
void work(){
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    sort(c + 1, c + 1 + n);
    int m = unique(c + 1, c + 1 + n) - c - 1;
    for (int i = 1; i <= n;i++)
    {
        b[i] = lower_bound(c + 1, c + 1 + m, a[i]) - c;
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        qu[i] = Q(l, r, i);
    }
    sort(qu + 1, qu + 1 + q);
    int l = 1, r = 0;
    for (int i = 1; i <= q;i++)
    {
        while (l < qu[i].l)
            move(l++, -1);
        while (l>qu[i].l)
            move(--l, 1);
        while (r<qu[i].r)
            move(++r, 1);
        while (r>qu[i].r)
            move(r--, -1);
        ans[qu[i].p] = now;
    }
    for (int i = 1; i <= q;i++)
    {
        printf("%lld\n", ans[i]);
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
