#include<cstdio>
using namespace std;
const int maxn=1000;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
 
int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			c[i][j]=a[i][j]^b[i][j];
		}
	}
	
	bool pd=true;
	
	for (int i=1;i<=n;i++) {
		int cnt=0;
		for (int j=1;j<=m;j++) {
			cnt+=c[i][j];
		}
		if (cnt%2==1) {
			pd=false;
		}
	}
	
	for (int j=1;j<=m;j++) {
		int cnt=0;
		for (int i=1;i<=n;i++) {
			cnt+=c[i][j];
		}
		if (cnt%2==1) {
			pd=false;
		}
	}
	
	if (pd==true) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
