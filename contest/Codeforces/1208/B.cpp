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
const int N = 2e3 + 5;
 
vector<int> b;
int a[N];
int L[N][N], R[N][N];
bool f[N][N];
int has(int x){
	return lower_bound(ALL(b), x) - b.begin() + 1;
}
 
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	REP(i,1,n){
		cin >> a[i];
		b.pb(a[i]);
	}
	sort(ALL(b));
	b.erase(unique(ALL(b)),b.end());
	REP(i,1,n){
		a[i] = has(a[i]);
	}
	int mx = 0;
	REP(i,1,n){
		REP(j,1,n){
			L[i][j] = L[i - 1][j];
		}
		L[i][a[i]]++;
		mx = max(mx, L[i][a[i]]);
	}
	REPD(i,n,1){
		REP(j,1,n){
			R[i][j] = R[i + 1][j];
		}
		R[i][a[i]]++;
	}
	if (mx<2){
		puts("0");
		return 0;
	}
	f[1][n] = 1;
	for (int k = n - 1; k >= 1;k--)
	{
		for (int i = 1; i <= n;i++)
		{
			int j = i + k - 1;
			if (j>n)
				break;
			if (f[i][j+1] && R[j+1][a[j+1]]+L[i-1][a[j+1]]<2)
				f[i][j] = 1;
			if (f[i-1][j] && L[i-1][a[i-1]]+R[j+1][a[i-1]]<2)
				f[i][j] = 1;
		}
	}
	int ans = n;
	for (int i = 1; i <= n;i++)
	{
		for (int j = i; j <= n;j++)
		{
			if (f[i][j]){
				ans = min(ans, j - i + 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
