#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

int n, q;
int a[N];
vector<int> b;
ll tree[N * 20];
int lc[N * 20], rc[N * 20], tot, cnt[N * 20];
int T[N];
ll sum[N];

void init_hash(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int has(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
void update(int &rt,int last,int l,int r,int p){
    rt = ++tot;
    lc[rt] = lc[last];
    rc[rt] = rc[last];
    tree[rt] = tree[last] + b[p - 1];
    cnt[rt] = cnt[last] + 1;
    if (l == r)
    {
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(lc[rt], lc[last], l, mid, p);
    else
        update(rc[rt], rc[last], mid + 1, r, p);
}

double query(int now,int last, int l,int r,double amount,int nowcnt){
    if (l==r){
        return amount / nowcnt;
    }
    int mid = l + r >> 1;

    int leftcnt = cnt[lc[now]] - cnt[lc[last]];
    ll leftamount = tree[lc[now]] - tree[lc[last]];

    if (1ll * (nowcnt - leftcnt) * b[mid - 1] + leftamount <= amount)
    { //go right
        return query(rc[now], rc[last], mid + 1, r, amount - leftamount, nowcnt - leftcnt);
    }
    else{//go left
        return query(lc[now], lc[last], l, mid, amount, nowcnt);
    }
}

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b.push_back(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    init_hash();
    for (int i = 1; i <= n; ++i)
    {
        update(T[i], T[i - 1], 1, b.size(), has(a[i]));
    }
    while (q--){
        int l, r, x, y;
        scanf("%d%d%d%d", &l, &r, &x, &y);
        double amount = sum[r] - sum[l - 1] - x * 1.0 * (sum[r] - sum[l - 1]) / y;
        printf("%.12f\n", query(T[r], T[l - 1], 1, b.size(), amount, r - l + 1));
    }
    return 0;
}
