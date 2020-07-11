#pragma GCC optimize(3)
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
const int M = 1e5 + 5;


namespace TRP{
    using namespace std;
    
    struct TREAP{
        int v, ch[2], rnd;
        int value;
        int sum;
    } tr[M * 30];
    int root[N], tot;
    inline void up(int x)
    {
        tr[x].sum = tr[tr[x].ch[0]].sum + tr[tr[x].ch[1]].sum + tr[x].value;
    }
    inline void rot(int & x,bool f){
        int t = tr[x].ch[f];
        tr[x].ch[f] = tr[t].ch[!f];
        tr[t].ch[!f] = x;
        up(x);
        up(t);
        x = t;
    }
    void insert(int &x,int v,ll val){
        if (!x){
            x = ++tot;
            tr[x].rnd = rand();
            tr[x].v = v;
            tr[x].ch[0] = tr[x].ch[1] = 0;
            tr[x].value = tr[x].sum = val;
            return;
        }
        tr[x].sum += val;
        if (tr[x].v == v)
        {
            tr[x].value += val;
            return;
        }
        bool f = v > tr[x].v;
        insert(tr[x].ch[f], v, val);
        if (tr[tr[x].ch[f]].rnd < tr[x].rnd)
            rot(x, f);
    }
    int getV(int x,int v){
        if (!x)
            return 0;
        if (tr[x].v==v){
            return tr[tr[x].ch[0]].sum + tr[x].value;
        }
        if (tr[x].v>v)
            return getV(tr[x].ch[0], v);
        else
            return getV(tr[x].ch[1], v) + tr[x].value + tr[tr[x].ch[0]].sum;
    }
}
using namespace TRP;

int n, m, q;
int mid;

inline int lb(int x) { return x & (-x); }
void update(int x,int p,ll val){
    for (int i = x; i <= n; i += lb(i))
        insert(root[i], p, val);
}
int query(int x,int p){
    int sum = 0;
    for (int i = x; i > 0; i -= lb(i))
        sum += getV(root[i], p);
    return sum;
}

inline void init(){
    tot = 0;
    REP(i, 1, n) root[i] = 0;
    mid = n + 1 >> 1;
}

struct MM{
    int x, y;
    int v;
    MM() {}
    MM(int x, int y) : x(x), y(y){}
    int value() const
    {
        return max(abs(x - mid), abs(y - mid));
    }
    bool operator < (const MM &b) const {
        return (*this).value() < b.value();
    }
    bool operator > (const MM &b) const {
        return (*this).value() > b.value();
    }
} a[M];

inline ll calc(int x,int y,ll ru){
    ll ld = n - ru + 1;
    if (x < y)
    {
        return abs(ld - ru) + abs(ld - ru) + abs(x - ld) + abs(y - ld);
    }
    else
    {
        return 1ll * abs(x - ru) + abs(y - ru);
    }
}
inline int conv(ll x){
    ll sum = 0;
    while (x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


int main()
{
    // clock_t st = clock();
    int _;
    for (scanf("%d", &_); _; --_)
    {
        scanf("%d%d%d", &n, &m, &q);
        init();
        mid = n + 1 >> 1;
        REP(i,1,m){
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = MM(x, y);
        }
        sort(a + 1, a + 1 + m, [](MM a, MM b) {
            return a > b;
        });
        ll now = 1;
        int ind = 1;
        for (int i = n - mid, j = n,edge=n; ~i; --i, --j,edge-=2)
        {
            while (ind<=m && a[ind].value()==i){
                a[ind].v = conv(now + calc(a[ind].x, a[ind].y, j));
                ++ind;
            }
            now += 4ll * edge - 4ll;
        }
        // REP(i,1,m){
        //     cout << a[i].x << " " << a[i].y << " " << a[i].v << endl;
        // }
        REP(i,1,m){
            update(a[i].x, a[i].y, a[i].v);
        }
        REP(i,1,q){
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int ans = query(x2, y2);
            ans -= query(x1 - 1, y2);
            ans -= query(x2, y1 - 1);
            ans += query(x1 - 1, y1 - 1);
            printf("%d\n", ans);
        }
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
