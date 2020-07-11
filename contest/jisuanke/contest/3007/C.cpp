#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=2000;
const int maxm=100000;
const long long INF = 1E18;
long long P[maxn];
long long C[maxn];

long long f[maxm];
int pre[maxm];

int main() {
	int n,m;
	while (~scanf("%d%d", &n,&m)) {
		long long bou = 0;
		for (int i=1;i<=n;i++) {
			scanf("%lld%lld", &P[i], &C[i]);
			if (bou<C[i]) {
				bou=C[i];
			}
		}
		for (int i=0;i<=m+bou;i++) {
			f[i]=INF;
		}
		f[0]=0;
		pre[0]=-1;
		for (int i=1;i<=n;i++) {
			for (int j=C[i];j<=m+bou;j++) {
				if (f[j]>f[j-C[i]]+P[i]) {
					f[j]=f[j-C[i]]+P[i];
				}
			}
		}
		long long ans=INF;
		long long ansp= 0;
		for (int i=m;i<=m+bou;i++) {
			if (f[i]<=ans) {
				ans=f[i];
				ansp=i;
			}
		}
//		for (int i=0;i<=m+bou;i++) {
//			printf("%lld ", f[i]);
//		}printf("\n");
		printf("%lld %d\n",ans,ansp);
	}
	return 0;
}
