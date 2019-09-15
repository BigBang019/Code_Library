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

vector<int> b;
struct Q
{
    int pos, f;
    Q(int pos, int f) : pos(pos), f(f){}
    Q(){}
} qu[10005];

int tot;
short d[10005];

int has(int x){
    return lower_bound(ALL(b), x) - b.begin() + 1;
}

int main()
{
    int _, n, m;
    scanf("%d", &_);
    for (int cas = 1; cas <= _;++cas)
    {
        tot = 0;
        b.clear();
        scanf("%d%d", &n, &m);
        REP(i,1,m){
            int l, r;
            scanf("%d%d", &l, &r);
            ++l;
            ++r;
            qu[++tot] = Q(l, 1);
            qu[++tot] = Q(r + 1, -1);
            b.pb(l);
            b.pb(r + 1);
        }
        sort(ALL(b));
        b.erase(unique(ALL(b)), b.end());
        int cnt = b.size();
        REP(i, 1, cnt) d[i] = 0;
        REP(i, 1, tot)
        {
            d[has(qu[i].pos)] += qu[i].f;
        }
        int last = 0;
        int now = 0;
        int ans = 0;
        REP(i, 1, cnt)
        {
            if (now&1){
                ans += (b[i - 1] - last - 1);
            }
            now += d[i];
            last = b[i - 1] - 1;
        }
        if (now&1){
            ans += (n - last);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
