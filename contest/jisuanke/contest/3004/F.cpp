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
const int N = 1e5 + 5;

int n, k;
int tree[N << 2];
int a[N], pos[N], f[N];
void update(int x, int l, int r, int p, int v)
{
    if (l==r){
        tree[x] = v;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(x << 1, l, mid, p, v);
    else
        update(x << 1 | 1, mid + 1, r, p, v);
    tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}
int query(int x,int l,int r,int ql,int qr){
    if (ql>r || qr<l ||ql>qr)
        return 0;
    if (ql<=l && qr>=r){
        return tree[x];
    }
    int mid = l + r >> 1;
    return max(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
}
void build(int x,int l,int r){
    tree[x] = 0;
    if (l==r)
        return;
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
}
int main(){
    int _;
    for (scanf("%d",&_);_;--_){
        scanf("%d%d", &n, &k);
        build(1, 1, n);
        REP(i, 1, n)
        {
            scanf("%d", a + i);
            pos[a[i]] = i;
        }
        f[1] = 1;
        update(1, 1, n, pos[1], 1);
        REP(i, 2, n)
        {
            int ql = max(1, pos[i] - k);
            int qr = min(n, pos[i] + k);
            f[i] = f[query(1, 1, n, ql, qr)] + 1;
            update(1, 1, n, pos[i], i);
        }
        REP(i,1,n){
            printf("%d%c", f[i], " \n"[i == n]);
        }
    }
    return 0;
}
