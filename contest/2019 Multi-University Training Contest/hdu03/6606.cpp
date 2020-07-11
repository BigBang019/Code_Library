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
const int N = 2e5 + 5;
const ll R = 1e15;

ll a[N], sum[N];
vector<ll> b;
int n, k;
int tree[N << 2];
int len;

int has(ll x){
    return lower_bound(ALL(b), x) - b.begin() + 1;
}

void update(int x,int l,int r,int p,int v){
    if (l==r){
		tree[x] = ~v ? max(v, tree[x]) : -1;
		return;
    }
    int mid = l + r >> 1;
    if (p<=mid) update(x << 1, l, mid, p, v);
    else update(x << 1 | 1, mid + 1, r, p, v);
    tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}

int query(int x,int l,int r,ll k){
    if (k>b[r-1])
        return -1;
    if (k<=b[l-1])
        return tree[x];
    int mid = l + r >> 1;
    int res = -1;
    if (k<=b[mid-1]){
        res = query(x << 1, l, mid, k);
    }
    res = max(query(x << 1 | 1, mid + 1, r, k), res);
    return res;
}
void build(int x,int l,int r){
	tree[x] = -1;
	if (l==r) return;
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
}
bool check(ll x){
    int mx = -1;
	build(1, 1, len);
	for (int i = 1; i <= n;i++)
    {
        int res = query(1, 1, len, sum[i] - x);
        int now = (sum[i] <= x ? 1 : -1);
        if (~res)
            now = max(res + 1, now);
        update(1, 1, len, has(sum[i]), now);
        mx = max(mx, now);
    }
    return mx >= k;
}

int main(){
	// clock_t st = clock();
	int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d%d", &n, &k);
        b.clear();
        REP(i,1,n){
            scanf("%lld", a + i);
            sum[i] = sum[i - 1] + a[i];
            b.pb(sum[i]);
        }
        sort(ALL(b));
        b.erase(unique(ALL(b)), b.end());
        len = b.size();
        ll l = -R, r = R, mid, ans;
        while (l<=r){
            mid = l + r >> 1;
            if (check(mid))
                r = (ans = mid) - 1;
            else
                l = mid + 1;
        }
        printf("%lld\n", ans);
    }
	// clock_t et = clock();
	// cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
