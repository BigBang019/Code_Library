// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORD(I, N) for (int I = N; ~I; --I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, B, A) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 1e5 + 10;

struct Q{
    int p, x, l, r, f;
    Q(){}
    Q(int p,int x,int l,int r,int f):p(p),x(x),l(l),r(r),f(f){}
    bool operator < (const Q &b) const{
        return x < b.x;
    }
} q[N << 1];

int n, m;
int pos[N];
ll ans[N];
vector<int> X[N];
ll tree[N << 2];
void update(int x,int l,int r,int p){
    if (l==r){
        tree[x]++;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(x << 1, l, mid, p);
    else
        update(x << 1 | 1, mid + 1, r, p);
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
ll query(int x,int l,int r,int ql,int qr){
    if (l>qr || r<ql || ql>qr)
        return 0;
    if (ql<=l && qr>=r){
        return tree[x];
    }
    int mid = l + r >> 1;
    return query(x << 1, l, mid, ql, qr) + query(x << 1 | 1, mid + 1, r, ql, qr);
}

int main(){
    // clock_t st = clock();
    scanf("%d%d", &n, &m);
    REP(i,1,n){
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }
    for (int i = 1; i <= n;++i)
    {
        int l = pos[i];
        for (int j = 2 * i; j <= n; j += i)
        {
            int r = pos[j];
            X[l].pb(r);
        }
    }
    int cnt = 0;
    REP(i, 1, m)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        q[++cnt] = Q(i, l - 1, l, r, -1);
        q[++cnt] = Q(i, r, l, r, 1);
    }
    sort(q + 1, q + 1 + cnt);
    int ind = 0;
    for (int i = 0; i <= n;++i)
    {
        for (auto y: X[i]){
            update(1, 1, n, y);
        }
        while (ind<=cnt && q[ind].x==i){
            ans[q[ind].p] += query(1, 1, n, q[ind].l, q[ind].r) * q[ind].f;
            ++ind;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
