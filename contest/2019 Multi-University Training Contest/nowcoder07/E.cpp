// #pragma GCC optimize(2)
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
#define FORD(I, N) for (int I = N; I; ++I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, A, B) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e6 + 5;

int n;
ll tree[N << 2], lazy[N << 2];
int L[N], R[N];
int len;
vector<int> b;

void init_hash(){
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
}
int has(int x){
    return lower_bound(ALL(b), x) - b.begin() + 1;
}
void pushdown(int x,int l,int r){
    if (lazy[x]==0)
        return;
    int mid = l + r >> 1;
    tree[x << 1] += lazy[x] * (b[mid - 1] - b[l - 1] + 1);
    tree[x << 1 | 1] += lazy[x] * (b[r - 1] - b[mid] + 1);
    lazy[x << 1] += lazy[x];
    lazy[x << 1 | 1] += lazy[x];
    lazy[x] = 0;
}
void update(int x,int l,int r,int ql,int qr){
    if (ql>r || qr<l)
        return;
    if (ql<=l && qr>=r){
        lazy[x]++, tree[x] += (b[r - 1] - b[l - 1] + 1);
        return;
    }
    tree[x] += b[min(qr, r) - 1] - b[max(ql, l) - 1] + 1;
    int mid = l + r >> 1;
    pushdown(x, l, r);
    update(x << 1, l, mid, ql, qr);
    update(x << 1 | 1, mid + 1, r, ql, qr);
}
int query(int x,int l,int r,ll k){
    if (l==r) return b[l - 1];
    int mid = l + r >> 1;
    pushdown(x, l, r);
    ll inmid = tree[x] - tree[x << 1] - tree[x << 1 | 1];
    ll avg = inmid == 0 ? 0 : inmid / (b[mid] - b[mid - 1] - 1);
    if (k<=tree[x<<1])
        return query(x << 1, l, mid, k);
    else if (k <= tree[x << 1] + inmid)
        return b[mid - 1] + (k - tree[x << 1]) / avg + ((k - tree[x << 1]) % avg != 0);
    else
        return query(x << 1 | 1, mid + 1, r, k - tree[x << 1] - inmid);
}
int main(){
    scanf("%d", &n);
    ll x1, x2, y1, y2, a1, a2, b1, b2, c1, c2;
    int m1, m2;
    scanf("%lld%lld%lld%lld%lld%d", &x1, &x2, &a1, &b1, &c1, &m1);
    scanf("%lld%lld%lld%lld%lld%d", &y1, &y2, &a2, &b2, &c2, &m2);
    b.pb(L[1] = min(x1, y1) + 1);
    b.pb(L[2] = min(x2, y2) + 1);
    b.pb(R[1] = max(x1, y1) + 1);
    b.pb(R[2] = max(x2, y2) + 1);
    REP (i,3,n){
        ll x3 = (a1 * x2 % m1 + b1 * x1 % m1 + c1) % m1;
        ll y3 = (a2 * y2 % m2 + b2 * y1 % m2 + c2) % m2;
        b.pb(x3 + 1);
        b.pb(y3 + 1);
        L[i] = min(x3, y3) + 1;
        R[i] = max(x3, y3) + 1;
        x1 = x2, x2 = x3;
        y1 = y2, y2 = y3;
    }
    init_hash();
    len = b.size();
    ll tot = 0;
    REP (i,1,n){
        tot += R[i] - L[i] + 1;
        update(1, 1, len, has(L[i]), has(R[i]));
        printf("%d\n", query(1, 1, len, tot + 1 >> 1));
    }
    return 0;
}
