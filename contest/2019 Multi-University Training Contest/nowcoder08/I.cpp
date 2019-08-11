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
#define FORD(I, N) for (int I = N; I; ++I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, B, A) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 3e5 + 5;

struct Q{
    int p, l, r;
    Q(int p, int l, int r) : p(p), l(l), r(r){};
    Q(){}
};
vector<Q> qu[N];

pi V[N];

int cnt, he[N], ne[N], v[N];

int id[N], dfn, sz[N], dfs_in[N], dfs_out[N], son[N];

ll ans[N];

int n;

ll c1[N], c2[N];
int lb(int x) { return x & -x; }
void update(int x,int v){
    for (int i = x; i <= n; i += lb(i))
    {
        c1[i] += v;
        c2[i] += v * x;
    }
}
ll query(int x){
    ll sum = 0;
    for (int i = x; i > 0; i -= lb(i)){
        sum += 1ll * (x + 1) * c1[i] - c2[i];
    }
    return sum;
}

void add(int x,int y){
    cnt++;
    ne[cnt] = he[x];
    v[cnt] = y;
    he[x] = cnt;
}
void dfs1(int x){
    id[dfs_in[x] = ++dfn] = x;
    sz[x] = 1;
    int mx = 0;
    for (int i = he[x]; i;i=ne[i]){
        int p = v[i];
        dfs1(p);
        if (sz[p]>mx){ mx = sz[p], son[x] = p; }
        sz[x] += sz[p];
    }
    dfs_out[x] = dfn;
}

void dfs2(int x){
    for (int i = he[x]; i;i=ne[i]){
        int p = v[i];
        if (p==son[x]) continue;
        dfs2(p);
        for (int j = dfs_in[p]; j <= dfs_out[p];j++)
        {
            int t = id[j];
            update(V[t].fi, -1), update(V[t].sc + 1, 1);
        }
    }
    if (son[x]) dfs2(son[x]);
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==son[x]) continue;
        for (int j = dfs_in[p]; j <= dfs_out[p];j++)
        {
            int t = id[j];
            update(V[t].fi, 1), update(V[t].sc + 1, -1);
        }
    }
    update(V[x].fi, 1), update(V[x].sc + 1, -1);
    for (auto q : qu[x]){
        ans[q.p] = query(q.r) - query(q.l - 1);
    }
}

int main(){
    int m;
    scanf("%d%d", &n, &m);
    V[1] = mp(1, n);
    FOR (i,m){
        int x, y, l, r;
        scanf("%d%d%d%d", &x, &y, &l, &r);
        add(x, y);
        V[y] = mp(l, r);
    }
    dfs1(1);
    int q;
    scanf("%d", &q);
    FOR(i,q){
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        qu[x].pb(Q(i, l, r));
    }
    dfs2(1);
    FOR(i, q) printf("%lld\n", ans[i]);
    return 0;
}
