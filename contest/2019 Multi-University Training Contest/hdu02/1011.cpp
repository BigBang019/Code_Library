#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int T[N];
int sum[N * 24], lc[N * 24], rc[N * 24], tot;
vector<int> b;
int top = 0, sta[N];
int a[N];
void init(){
    tot = 0;
    memset(sum, 0, sizeof(sum));
    memset(lc, 0, sizeof(lc));
    memset(rc, 0, sizeof(rc));
    b.clear();
}
void Init_Hash(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int has(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
void build(int &rt,int l,int r){
    rt = ++tot;
    if (l==r)
        return;
    int mid = l + r >> 1;
    build(lc[rt], l, mid);
    build(rc[rt], mid + 1, r);
}
void update(int &rt,int last,int l,int r,int p,int v){
    rt = ++tot;
    int now = tot;
    sum[now] = sum[last] + v;
    if (l==r){
        return;
    }
    lc[now] = lc[last];
    rc[now] = rc[last];
    int mid = l + r >> 1;
    if (p<=mid)
        update(lc[now], lc[last], l, mid, p, v);
    else
        update(rc[now], rc[last], mid + 1, r, p, v);
}
void query(int now,int last,int l,int r,int k){
    if (l==r){
        for (int i = 1; i <= sum[now] - sum[last];i++)
        {
            sta[++top] = l;
        }
        return;
    }
    int mid = l + r >> 1;
    int sl = sum[lc[now]] - sum[lc[last]];
    int sr = sum[rc[now]] - sum[rc[last]];
    if (sr)
        query(rc[now], rc[last], mid + 1, r, min(k, sr));
    if (k>sr)
        query(lc[now], lc[last], l, mid, k - sr);
}
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    int n, m;
    while (~scanf("%d%d", &n, &m)){
        init();
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &a[i]);
            b.push_back(a[i]);
        }
        Init_Hash();
        int len = b.size();
        build(T[0], 1, len);
        for (int i = 1; i <= n;i++)
            update(T[i], T[i - 1], 1, len, has(a[i]), 1);
        while (m--){
            int l, r;
            scanf("%d%d", &l, &r);
            top = 0;
            query(T[r], T[l - 1], 1, len, 44);
            ll ans = -1;
            for (int i = 3; i <= top;i++)
            {
                ll x1 = b[sta[i] - 1];
                ll x2 = b[sta[i - 1] - 1];
                ll x3 = b[sta[i - 2] - 1];
                if (x3 < x1 + x2)
                {
                    ans = max(ans, x1 + x2 + x3);
                    break;
                }
            }
            printf("%lld\n", ans);
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
