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
const int M = 1e5 + 5;

int n, m, q, tot;
int mid;
int ans[M];
int tree[N << 2];

struct MM{
    int x, y, v;
    MM() {}
    MM(int x, int y) : x(x), y(y){}
    inline int value()
    {
        return max(abs(x - mid), abs(y - mid));
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

inline void read(int &x){
    x = 0; char s = getchar();
    while (s<'0' || s>'9')
        s = getchar();
    while (s<='9' && s>='0')
        x = x * 10 + s - '0', s = getchar();
}

struct Q{
    int x, l, r, p, f;
    Q(){}
    Q(int x,int l,int r,int p,int f):x(x),l(l),r(r),p(p),f(f){}
    bool operator < (const Q& b) const {
        return x < b.x;
    }
} qu[M * 2];

void init(){
    tot = 0;
    memset(tree, 0, sizeof(tree));
    mid = n + 1 >> 1;
}

void update(int x,int l,int r,int p,int v){
    if (l==r){
        tree[x] += v;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(x << 1, l, mid, p, v);
    else
        update(x << 1 | 1, mid + 1, r, p, v);
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
int query(int x,int l,int r,int ql,int qr){
    if (qr<l || ql>r || ql>qr)
        return 0;
    if (ql<=l && qr>=r){
        return tree[x];
    }
    int mid = l + r >> 1;
    return query(x << 1, l, mid, ql, qr) + query(x << 1 | 1, mid + 1, r, ql, qr);
}

int main()
{
    // clock_t st = clock();
    int _;
    for (scanf("%d", &_); _; --_)
    {
        read(n);
        read(m);
        read(q);
        init();
        for (register int i = 1; i <= m; ++i)
        {
            int x, y;
            read(x);
            read(y);
            a[i] = MM(x, y);
        }
        sort(a + 1, a + 1 + m, [](MM a, MM b) {
            return a.value() > b.value();
        });
        ll now = 1;
        int ind = 1;
        for (register int i = n - mid, j = n, edge = n; ~i; --i, --j, edge -= 2)
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
        sort(a + 1, a + 1 + m, [](MM a, MM b) {
            return a.x < b.x;
        });

        for (register int i = 1; i <= q; ++i)
        {
            int x1, y1, x2, y2;
            read(x1);
            read(y1);
            read(x2);
            read(y2);
            qu[++tot] = Q(x1 - 1, y1, y2, i, -1);
            qu[++tot] = Q(x2, y1, y2, i, 1);
            ans[i] = 0;
        }
        sort(qu+ 1, qu + tot + 1);
        ind = 1;
        for (register int i = 1; i <= tot; ++i)
        {
            while (ind<=m && a[ind].x<=qu[i].x){
                update(1, 1, n, a[ind].y, a[ind].v);
                ind++;
            }
            ans[qu[i].p] += qu[i].f * query(1, 1, n, qu[i].l, qu[i].r);
        }
        for (register int i = 1; i <= q; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
