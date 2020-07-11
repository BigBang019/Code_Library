#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 99971;
ll tree[N << 2][50], up[N << 2];
ll a[N][50];
int n, q;
void pushup(int x,int l,int r){
    if (l==r)
        return;
    for (int i = 0; i < 48;i++)
    {
        tree[x][i] = tree[2 * x][(i + up[2 * x]) % 48] + tree[2 * x + 1][(i + up[2 * x + 1]) % 48];
        tree[x][i] %= MOD;
    }
}
void build(int x,int l,int r){
    if (l==r){
        for (int i = 0; i < 48;i++)
        {
            tree[x][i] = a[l][i];
        }
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x, l, r);
}
void insert(int x,int l,int r,int ql,int qr){
    if (ql>r || qr<l)
        return;
    if (ql<=l && qr>=r){
        up[x]++;
        up[x] %= 48;
        return;
    }
    int mid = l + r >> 1;
    insert(2 * x, l, mid, ql, qr);
    insert(2 * x + 1, mid + 1, r, ql, qr);
    pushup(x, l, r);
}
ll query(int x,int l,int r,int ql,int qr,int cnt){
    if (ql>r || qr<l)
        return 0;
    cnt += up[x];
    if (ql<=l && qr>=r){
        return tree[x][cnt % 48];
    }
    int mid = l + r >> 1;
    return (query(2 * x, l, mid, ql, qr, cnt) + query(2 * x + 1, mid + 1, r, ql, qr, cnt))%MOD;
}
void work(){
    memset(up, 0, sizeof(up));
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld",&a[i][0]);
        a[i][0] %= MOD;
        for (int j = 1; j < 48;j++)
        {
            a[i][j] = a[i][j - 1] * a[i][j - 1] * a[i][j - 1] % MOD;
        }
    }
    build(1, 1, n);
    int fl, l, r;
    while(q--){
        scanf("%d%d%d", &fl, &l, &r);
        if (fl==1)
            insert(1, 1, n, l, r);
        else
            printf("%lld\n", query(1, 1, n, l, r, 0));
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        work();
    }
    return 0;
}
