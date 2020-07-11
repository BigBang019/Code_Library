// #pragma GCC optimize(3)
#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
const int INF = 1e9;
namespace UFS{
    using namespace std;
    int rank[N], fa[N];
    int n;
    stack<pair<int*, int> > cur;
    void init()
    {
        memset(rank, 0, sizeof(rank));
        REP(i, 1, n) fa[i] = i;
    }
    inline int find(int x) { return x == fa[x] ? x : find(fa[x]); }
    inline int join(int x,int y){
        x = find(x), y = find(y);
        if (x==y) return 0;
        int tot = 0;
        if (rank[x]<rank[y]){
            cur.push(mp(fa + x, fa[x]));
            fa[x] = y;
            tot = 1;
        }else {
            cur.push(mp(fa + y, fa[y]));
            fa[y] = x;
            tot = 1;
            if (rank[x]==rank[y]){
                cur.push(mp(rank + y, rank[y]));
                ++rank[y];
                tot++;
            }
        }
        return tot;
    }
    inline void undo(int x){
        FOR(i,x){
            *cur.top().fi = cur.top().sc;
            cur.pop();
        }
    }
}
using namespace UFS;

struct EDGE{
    int x, y, l, r;
    EDGE(){}
    EDGE(int x, int y, int l, int r) : x(x), y(y), l(l), r(r){}
};
vector<int> tree[N << 2];
vector<EDGE> E;
vector<int> b;
int ans = 0;
int has(int x){
    return lower_bound(ALL(b), x) - b.begin() + 1;
}
void update(int x,int l,int r,int ql,int qr,int v){
    if (ql>r || qr<l) return;
    if (ql<=l && qr>=r){
        tree[x].pb(v);
        return;
    }
    int mid = l + r >> 1;
    update(x << 1, l, mid, ql, qr, v);
    update(x << 1 | 1, mid + 1, r, ql, qr, v);
}
void dfs(int x,int l,int r){
    int now = 0;
    for (int id : tree[x]) now += join(E[id].x, E[id].y);
    if (l==r || find(1)==find(n)){
        if (find(1)==find(n)){
            ans += b[r] - b[l - 1];
        }
    }else{
        int mid = l + r >> 1;
        dfs(x << 1, l, mid);
        dfs(x << 1 | 1, mid + 1, r);
    }
    undo(now);
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    init();
    FOR (i,m){
        int x, y, l, r;
        scanf("%d%d%d%d", &x, &y, &l, &r);
        E.pb(EDGE(x, y, l, ++r));
        b.pb(l), b.pb(r);
    }
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    int len = b.size();
    FOR(i, SZ(E)) update(1, 1, len, has(E[i].l), has(E[i].r) - 1, i);
    dfs(1, 1, len);
    printf("%d\n", ans);
    return 0;
}
