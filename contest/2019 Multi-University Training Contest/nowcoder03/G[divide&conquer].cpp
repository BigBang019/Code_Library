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
const int N = 3e5 + 5;

ll sum[N];
int a[N];
ll ans = 0;
int n;
int LOG[N];
int f[N][20];

void init(){
	LOG[2] = 1;
	REP(i,2,N-5){
		LOG[i] = LOG[i / 2] + 1;
	}
}

int query(int l,int r){
	int k = LOG[r - l + 1];
	return a[f[l][k]] > a[f[r - (1 << k) + 1][k]] ? f[l][k] : f[r - (1 << k) + 1][k];
}

inline int Max(int a,int b){
	return a > b ? a : b;
}

void dfs(int l,int r){
	if (r-l<=1){
		if (l>=r)
			return;
		if (a[l]==a[r]){
			++ans;
		}
		return;
	}
	int p = query(l, r);
	int mx = a[p];
	
	int ql, qr, mid, res;
	if (p - l < r - p){
		for (register int i = l; i <= p; ++i)
		{
			ql = p, qr = r, res = n + 1;
			while (ql<=qr){
				mid = ql + qr >> 1;
				if ((sum[mid] - sum[i - 1]) / 2 >= mx)
					qr = (res = mid) - 1;
				else
					ql = mid + 1;
			}
			ans += Max(0, r - res + 1);
		}
	}else {
		for (register int i = p; i <= r; ++i)
		{
			ql = 1, qr = p, res = -1;
			while (ql<=qr){
				mid = ql + qr >> 1;
				if ((sum[i] - sum[mid - 1]) / 2 >= mx)
					ql = (res = mid) + 1;
				else
					qr = mid - 1;
			}
			ans += Max(0, res - l + 1);
		}
	}
	dfs(l, p - 1);
	dfs(p + 1, r);
}

int main(){
	init();
	int _;
	for (scanf("%d", &_); _;--_)
	{
		ans = 0;
		scanf("%d", &n);
		for (register int i = 1; i <= n; ++i)
		{
			scanf("%d", a + i);
			sum[i] = sum[i - 1] + 1ll * a[i];
			f[i][0] = i;
		}
		for (int j = 1; (1 << j) <= n; j++)
		{
			for (register int i = 1; i + (1 << j) - 1 <= n; i++)
			{
				f[i][j] = a[f[i][j - 1]] > a[f[i + (1 << (j - 1))][j - 1]] ? f[i][j - 1] : f[i + (1 << (j - 1))][j - 1];
			}
		}
		dfs(1, n);
		printf("%lld\n", ans);
	}
	return 0;
}
