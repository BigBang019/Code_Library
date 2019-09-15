#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=30;
typedef __int128 Bint;

Bint f[maxn][maxn][maxn];
char ch[100];
char ans[100];

Bint read() {
	scanf("%s", ch);
	int len=strlen(ch);
	Bint w=1;
	Bint res=0;
	for (int i=len-1;i>=0;i--) {
		Bint tmp = ch[i]-'0';
		res=res+w*tmp;
		w=w*10;
	}
	return res;
}



inline void init() {
	for (int i=0;i<=26;i++) {
		for (int j=0;j<=26;j++) {
			for (int k=0;k<=26;k++) {
				f[i][j][k]=0;
			}
		}
	}
	
	for (int i=0;i<=26;i++) {
		for (int j=1;j<=i;j++) {
			f[j][0][i]=1;
		}
	}
	
	for (int k=1;k<=26;k++) {
		for (int j=1;j<=k;j++) {
			for (int i=0;i<=k-j;i++){
				f[i][j][k]+=f[i+1][j-1][k];
				f[i][j][k]+=f[i][j-1][k]*(Bint)i;
			}
		}
	}
	
//	for (int i=1;i<=3;i++) {
//		for (int j=0;j<=3;j++) {
//			printf("%lld ", (long long) f[i][j][3]);
//		} printf("\n");
//	}
	
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	int rd=0;
	while (T--) {
		rd++;
		
		int n;
		scanf("%d", &n);
		Bint K = read();
		int bound=1;
		for (int i=1;i<=n;i++) {
			int p=0;
			Bint res=0;
			while (res+f[max(bound,p+1)][n-i][n]<K) {
				p++;
				res+=f[bound][n-i][n];
			}
			if (p>=bound) {
				bound=p+1;
			}
			ans[i]='A'+p;
			K=K-res;
		}
		
		printf("Case #%d: ",rd);
		for (int i=1;i<=n;i++) {
			printf("%c", ans[i]);
		}printf("\n");
	}
	return 0;
}
