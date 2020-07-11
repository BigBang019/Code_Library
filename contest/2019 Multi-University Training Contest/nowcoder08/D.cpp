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
const int N = 2e5 + 5;
 
struct BIT{
    vector<vector<vector<int>>> c;
    int n, m, h;
    void init(int _n, int _m, int _h){
        n = _n, m = _m, h = _h;
        c = vector<vector<vector<int>>>(n + 3, vector<vector<int>>(m + 3, vector<int>(h + 3, -1)));
    }
    void add(int x, int y, int z, int v){
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                for (int k = z; k <= h; k += k & -k)
                    c[i][j][k] = max(c[i][j][k], v);
    }
    int query(int x,int y,int z){
        int res = -1;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                for (int k = z; k > 0; k -= k & -k)
                    res = max(c[i][j][k], res);
        return res;
    }
} t[8];

 
int n, m, h, q;
int a[3], b[3], c[3];
void read(int &x){
	char ch; x = 0;
	ch = getchar();
	while (ch>'9' || ch<'0') ch = getchar();
	while (ch<='9' && ch>='0')
		x = x * 10 + ch - '0', ch = getchar();
}

int main(){
    scanf("%d%d%d%d", &n, &m, &h, &q);
    c[0] = n, c[1] = m, c[2] = h;
	FOR(i, 8) t[i].init(n, m, h);
	while (q--){
        int op;
		read(op); read(a[0]); read(a[1]); read(a[2]);
		int ans = 1e9;
        FOR(cas,8){
            FOR(i, 3) b[i] = a[i] * (cas >> i & 1 ? -1 : 1);
            FOR(i, 3) if (b[i] < 0) b[i] += c[i] + 1;
            if (op==1){
                t[cas].add(b[0], b[1], b[2], b[0] + b[1] + b[2]);
                // printf("%d: %d\n", cas, t[cas].query(n, m, h));
            }else{
                int res = t[cas].query(b[0], b[1], b[2]);
                if (~res)
                    ans = min(ans, b[0] + b[1] + b[2] - res);
            }
        }
        if (op==2) printf("%d\n", ans);
    }
    return 0;
}
