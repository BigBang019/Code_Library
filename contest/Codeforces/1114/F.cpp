#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;
const ll MOD = 1e9 + 7;
ll tree[N << 2];
ll pr[N << 2];
ll lazy[N << 2];
ll lazyV[N << 2];
ll a[N];
int n, q;
int prime[305], tot, inv[70];
ll qp(ll a,int k){
    ll ans = 1;
    while(k){
        if (k&1){
            ans =a*ans%MOD;
        }
        k /= 2;
        a = a * a % MOD;
    }
    return ans;
}
ll JVM(int x){
    ll rt = 0;
    for (int i = 1; i <= tot;i++)
    {
        if (x%prime[i]==0)
            rt += pow(2, i - 1);
        while(x%prime[i]==0)
            x /= prime[i];
        if (x==1)
            break;
    }
    return rt;
}
void get_prime(){
    tot = 0;
    for (int i = 1; i <= 300;i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i <= 300;i++)
    {
        if (prime[i]){
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && prime[j] * i <= 300; j++)
        {
            prime[i * prime[j]] = 0;
            if (i%prime[j]==0)
                break;
        }
    }
    for (int i = 1; i <= tot;i++)
    {
        inv[i] = qp(prime[i], MOD - 2);
    }
}
void pushup(int x){
    tree[x] = tree[x * 2 + 1] * tree[2 * x] % MOD;
    pr[x] = pr[2 * x] | pr[2 * x + 1];
}
void pushdown(int x,int l,int r){
    int mid = l + r >> 1;
    tree[2 * x] = tree[2 * x] * qp(lazyV[x], mid - l + 1) % MOD;
    tree[2 * x + 1] = tree[2 * x + 1] * qp(lazyV[x], r - mid) % MOD;
    lazyV[2 * x] = lazyV[2 * x] * lazyV[x] % MOD;
    lazyV[2 * x + 1] = lazyV[2 * x + 1] * lazyV[x] % MOD;
    lazyV[x] = 1;

    pr[2 * x] = pr[2 * x] | lazy[x];
    pr[2 * x + 1] = pr[2 * x + 1] | lazy[x];
    lazy[2 * x] |= lazy[x];
    lazy[2 * x + 1] |= lazy[x];
}
void build(int x,int l,int r){
    int mid = l + r >> 1;
    lazyV[x] = 1;
    lazy[x] = 0;
    if (l==r){
        tree[x] = a[l];
        pr[x] = JVM(a[l]);
        return;
    }
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
}
void insert(int x,int l,int r,int ql,int qr,ll v,ll p){
    if (qr<l || ql>r)
        return;
    if (ql<=l && qr>=r){
        tree[x] = tree[x] * qp(v, r - l + 1) % MOD;
        lazyV[x] = lazyV[x] * v % MOD;
        pr[x] |= p;
        lazy[x] |= p;
        return;
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    insert(2 * x, l, mid, ql, qr, v, p);
    insert(2 * x + 1, mid + 1, r, ql, qr, v, p);
    pushup(x);
}
ll query(int x,int l,int r,int ql,int qr){
    if (qr<l || ql>r)
        return 0;
    if (ql<=l && qr>=r){
        return pr[x];
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    return query(2 * x, l, mid, ql, qr) | query(2 * x + 1, mid + 1, r, ql, qr);
}
ll queryV(int x,int l,int r,int ql,int qr){
    if (qr<l||ql>r)
        return 1;
    if (ql<=l && qr>=r){
        return tree[x];
    }
    pushdown(x, l, r);
    int mid = l + r >> 1;
    return queryV(2 * x, l, mid, ql, qr) * queryV(2 * x + 1, mid + 1, r, ql, qr) % MOD;
}
int main(){
    get_prime();
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    build(1, 1, n);
    while(q--){
        char ch;
        while((ch=getchar())==' '|| ch=='\n' || ch=='\r')
            ;
        char tt;
        while((tt=getchar())<='Z' && tt>='A')
            ;
        int l, r;
        ll v, p;
        if (ch=='T'){
            scanf("%d%d", &l, &r);
            ll tmp = queryV(1, 1, n, l, r);
            p = query(1, 1, n, l, r);
            for (int i = 1; i <= tot && p;i++)
            {
                if (p&1) {
                    tmp = tmp * (prime[i] - 1) % MOD;
                    tmp = tmp * inv[i] % MOD;
                }
                p /= 2;
            }
            printf("%I64d\n", tmp);
        }else{
            scanf("%d%d%I64d", &l, &r, &v);
            p = JVM(v);
            insert(1, 1, n, l, r, v, p);
        }
    }
    return 0;
}
