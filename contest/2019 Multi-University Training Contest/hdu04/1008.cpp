// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int tot, len, a[N];
int T[N], lc[N * 32], rc[N * 32], sum[N * 32];
void build(int &rt,int l,int r){
    rt = ++tot;
    int now = tot;
    sum[now] = 0;
    if (l==r)
        return;
    int mid = l + r >> 1;
    build(lc[now], l, mid);
    build(rc[now], mid + 1, r);
}
void update(int &rt,int last,int l,int r,int p){
    rt = ++tot;
    int now = tot;
    sum[now] = sum[last] + 1;
    if (l==r)
        return;
    int mid = l + r >> 1;
    lc[now] = lc[last];
    rc[now] = rc[last];
    if (p<=mid)
        update(lc[now], lc[last], l, mid, p);
    else
        update(rc[now], rc[last], mid + 1, r, p);
}
int query(int now,int last,int l,int r,int ql,int qr){
    if (ql>r || qr<l)
        return 0;
    if (ql<=l && qr>=r){
        return sum[now] - sum[last];
    }
    int mid = l + r >> 1;
    return query(lc[now], lc[last], l, mid, ql, qr) + query(rc[now], rc[last], mid + 1, r, ql, qr);
}
vector<int> b;
bool check(int ql,int qr,int p,int k,int x){
    int lr = lower_bound(b.begin(), b.end(), p - x) - b.begin() + 1;
    int rr = lower_bound(b.begin(), b.end(), p + x) - b.begin() + 1;
    if (rr!=b.size()+1){
        if (p+x!=b[rr-1])
            rr--;
    }
    int num = query(T[qr], T[ql - 1], 1, len, lr, rr);
    return (num >= k);
}

int main(){
    int _;
    len = 1e5;
    build(T[0], 1, len);
    int cur = tot;
    for (scanf("%d", &_); _;_--)
    {
        tot = cur;
        b.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &a[i]);
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        for (int i = 1; i <= n;i++)
        {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            update(T[i], T[i - 1], 1, len, a[i]);
        }
        int ans = 0;
        while (m--){
            int ql, qr, k, p;
            scanf("%d%d%d%d", &ql, &qr, &p, &k);
            ql ^= ans;
            qr ^= ans;
            p ^= ans;
            k ^= ans;
            int l = 0, r = 1e6, mid;
            while (l<=r){
                mid = l + r >> 1;
                if (check(ql, qr, p, k, mid))
                {
                    ans = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
