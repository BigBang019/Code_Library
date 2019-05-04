#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<climits>
#include<queue>
#define N 1000005
#define ll long long
using namespace std;
int c[N],n,m;
int f[N][3][3];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	memset(f,-1,sizeof(f));
	f[0][0][0]=0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<3;j++){
			for (int k=0;k<3;k++){
				for (int l=0;l<3;l++){
					if (j+k+l>c[i] || f[i-1][k][l]==-1) continue;
					f[i][j][k]=max(f[i][j][k],f[i-1][k][l]+l+(c[i]-j-k-l)/3);
				}
			}
		}
	}
	int ans=0;
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			ans=max(ans,f[m][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
