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
int maze[N][N];
int main(){
	int n;
	scanf("%d",&n);
	int now = 0;
	FOR(i,n/2){
		FOR(j,n/2){
			maze[i][j] = 4 * now + 1;
			maze[i + n / 2][j] = 4 * now + 2;
			maze[i][j + n / 2] = 4 * now + 3;
			maze[i + n / 2][j + n / 2] = 4 * now;
			now++;
		}
	}
	FOR(i,n){
		FOR(j,n){
			printf("%d%c", maze[i][j], " \n"[j == n - 1]);
		}
	}
	return 0;
}
