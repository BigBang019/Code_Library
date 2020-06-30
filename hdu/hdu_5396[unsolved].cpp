#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
const int MOD = 1e9 + 7;
ll f[N][N], A[N], C[N][N];
char s[N];
int n;
int main(){
	A[0] = 1;
	for (int i = 1; i <= 100;i++)
	{
		A[i] = (A[i - 1] * i) % MOD;
	}
	C[0][0] = 1;
	for (int i = 1; i <= 100;i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i;j++)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	while (~scanf("%d",&n)){
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n;i++)
		{
			scanf("%lld", &f[i][i]);
		}
		
		scanf(" %s", s + 1);
		for (int l = 2; l <= n;l++)
		{
			for (int i = 1; i + l - 1 <= n; i++)
			{
				int j = i + l - 1;
				for (int k = i; k < j;k++)
				{
					ll t;
					if (s[k]=='*')
						t = (f[i][k] * f[k + 1][j]) % MOD;
					else if (s[k]=='+')
						t = (f[i][k] * A[j - k - 1] + f[k + 1][j] * A[k - i]) % MOD;
					else
						t = (f[i][k] * A[j - k - 1] - f[k + 1][j] * A[k - i]) % MOD;
					
					f[i][j] = (f[i][j] + t * C[j - i - 1][k - i]) % MOD;
				}
			}
		}
		printf("%lld\n", (f[1][n] + MOD) % MOD);
	}
	return 0;
}
