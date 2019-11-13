#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

int belong[N];
int mx[N << 2];
int lazy[N << 2];
int a[N];
int in2[N], in1[N], in3[N];
int k1, k2, k3, n;
void up(int x){
    mx[x] = min(mx[x << 1], mx[x << 1 | 1]);
}
void pushdown(int x,int l,int r){
    if (!lazy[x])
        return;
    int mid = l + r >> 1;
    mx[x << 1] += lazy[x];
    mx[x << 1 | 1] += lazy[x];
    lazy[x<<1] += lazy[x];
    lazy[x << 1 | 1] += lazy[x];
    lazy[x] = 0;
}
void build(int x, int l, int r)
{
    if (l==r){
        mx[x] = k1 + in3[l] + in2[n] - in2[l];
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    up(x);
}

void update(int x,int l,int r,int ql,int qr,int v){
    if (ql>r || qr<l || ql>qr)
        return;
    if (ql<=l && qr>=r){
        lazy[x] += v;
        mx[x] += v;
        return;
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    update(x << 1, l, mid, ql, qr, v);
    update(x << 1 | 1, mid + 1, r, ql, qr, v);
    up(x);
}
int query(int x,int l,int r,int ql,int qr){
    if (ql>r || qr<l || ql>qr)
        return n + 1;
    if (ql<=l && qr>=r){
        return mx[x];
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    return min(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for (int i = 1; i <= k1; ++i)
    {
        int x;
        cin >> x;
        belong[x] = 1;
    }
    for (int i = 1; i <= k2;++i)
    {
        int x;
        cin >> x;
        belong[x] = 2;
    }
    for (int i = 1; i <= k3; ++i)
    {
        int x;
        cin >> x;
        belong[x] = 3;
    }
    for (int i = 1; i <= n;++i)
    {
        in2[i] = in2[i - 1] + (belong[i] == 2);
        in1[i] = in1[i - 1] + (belong[i] == 1);
        in3[i] = in3[i - 1] + (belong[i] == 3);
    }
    build(1, 0, n);
    int ans = mx[1];
    for (int i = 1; i <= n;++i)
    {
        if (belong[i]==1){
            update(1, 0, n, i - 1, n, -1);   
        }
        else if (belong[i] == 2)
        {
            update(1, 0, n, i, n, 1);
        }
        else
        {
            update(1, 0, n, i - 1, i - 1, 1);
        }
        ans = min(ans, query(1, 0, n, i - 1, n));
    }
    printf("%d\n", ans);
    return 0;
}
