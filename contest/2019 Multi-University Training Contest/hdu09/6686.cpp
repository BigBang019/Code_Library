/***********************************************************************
  结论：互不相交的两条路径一定会覆盖直径上的两个端点，假设没有覆盖我们一定可以移动这条路径使得它覆盖未被覆盖端点的同时保证路径长度不变
  
  实际上对于每个x我们只需要求最大的y
  因为对于所有的x'<x, y'<y: (x',y')一定存在
  
  所以就只有两种情况：
      1. 两条路径各占一个端点
      2. 一条为直径，另一条为直径外的
***********************************************************************/


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
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
int he[N], ne[N << 1], v[N << 1], cnt;

int fa[N], dep[N], f[N], g[N], ans[N], len[N];

vector<int> D;

bool onD[N];

void add(int x,int y){
    v[++cnt] = y;
    ne[cnt] = he[x];
    he[x] = cnt;
}
void dfs1(int x,int fx){
    dep[x] = dep[fx] + 1; int p;
    fa[x] = fx;
    for (int i = he[x]; i;i=ne[i])
    {
        if ((p = v[i]) == fa[x]) continue;
        dfs1(p, x);
    }
}
void dfs2(int x){
    f[x] = g[x] = 1;
    for (int i = he[x]; i; i = ne[i]){
        int p = v[i];
        if (p==fa[x] || onD[p]) continue;
        dfs2(p);
        g[x] = max(g[x], f[x] + f[p]);
        f[x] = max(f[x], f[p] + 1);
    }
}

void init(){
    cnt = 0;
    REP(i, 0, n) he[i] = onD[i] = ans[i] = len[i] = 0;
    D.clear();
}

int main(){
    // clock_t st = clock();
    int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d", &n);
        init();
        FOR(i,n-1){
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        dfs1(1, 0);
        int u = 1, v = 1;
        REP(i, 1, n) if (dep[i] > dep[u]) u = i;
        dfs1(u, 0);
        v = u;
        REP(i, 1, n) if (dep[i] > dep[v]) v = i;
        for (int i = v; i;i=fa[i]) onD[i] = 1, D.pb(i);
        FOR(i, SZ(D)) dfs2(D[i]);
        FORD(i,SZ(D)-1){
            len[i] = max(len[i + 1], SZ(D) - i + f[D[i]] - 1);
        }
        FOR(i,SZ(D)-1){
            int l1 = i + f[D[i]];
            int l2 = len[i + 1];
            ans[l1] = max(ans[l1], l2);
            ans[l2] = max(ans[l2], l1);
        }
        REP(i, 1, n) if (!onD[i]){
            ans[SZ(D)] = max(ans[SZ(D)], g[i]);
            ans[g[i]] = max(ans[g[i]], SZ(D));
        }
        int last = 0;
        ll tot = 0;
        REPD(i, n, 1){
            if (ans[i]<=last) continue;
            tot += 1ll * (ans[i] - last) * i;
            last = ans[i];
        }
        printf("%lld\n", tot);
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
