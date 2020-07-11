#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
double f[N][N][N];
int a, b, c;
double rate(int x,int y,int z,int fl){
	int total = x * y + x * z + y * z;
	if (total==0)
		return 1;
	if (fl==1)
		return (x * y * 1.0 / total);
	if (fl==2)
		return (x * z * 1.0 / total);
	if (fl==3)
		return (y * z * 1.0 / total);
}
int main(){
	scanf("%d%d%d", &a, &b, &c);
	f[a][b][c] = 1.0;
	for (int i = a; i >= 0;i--)
	{
		for (int j = b; j >= 0;j--)
		{
			for (int k = c; k >= 0;k--)
			{
				if (i+1<=a)
					f[i][j][k] += f[i + 1][j][k] * rate(i + 1, j, k, 2);
				if (j+1<=b)
					f[i][j][k] += f[i][j + 1][k] * rate(i, j + 1, k, 1);
				if (k+1<=c)
					f[i][j][k] += f[i][j][k + 1] * rate(i, j, k + 1, 3);
				// cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
			}
		}
	}

	double ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 1; i <= a;i++)
	{
		ans1 += f[i][1][0];
	}
	for (int i = 1; i <= b;i++)
	{
		ans2 += f[0][i][1];
	}
	for (int i = 1; i <= c;i++)
	{
		ans3 += f[1][0][i];
	}
	printf("%.9f %.9f %.9f", ans1, ans2, ans3);
	return 0;
}
