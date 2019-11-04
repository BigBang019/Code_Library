/*

*/
#include<cstdio>
using namespace std;
const int maxn=2005;
const long long mod=1E9+7;

long long f[maxn][maxn];

int main() {
	int n,m;
	while (~scanf("%d%d", &n,&m)) {
		for (int i=0;i<=n+m;i++) {
			for (int j=0;j<=n+m;j++) {
				f[i][j]=0;
			}
		}
		f[0][0]=1;
		for (int i=0;i<=n+m;i++) {
			for (int j=0;j<=n+m;j++) {
				if (i<n || (i-n)<j) {
					f[i+1][j]+=f[i][j];
					f[i+1][j]%=mod;
				}
				if (j<m || (j-m)<i) {
					f[i][j+1]+=f[i][j];
					f[i][j+1]%=mod;
				}
			}
		}
		printf("%lld\n", f[n+m][n+m]);
	}
	return 0;
}
