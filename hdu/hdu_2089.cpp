#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
const int MOD = 1e9 + 7;
int a[N], tot;
int f[N][2];	//数位长度为i且i+1位是否为6的总数

int dfs(int len,bool state,bool fp)//fp==true表示上一位已经枚举到顶了，当前位只能枚举0->digit[len]
{
    if(!len)
        return 1;
    if(!fp && f[len][state] != -1)
        return f[len][state];
	int ret = 0, fpmax = fp ? a[len] : 9;
	for (int i = 0; i <= fpmax; i++)
	{
        if(i == 4 || state && i == 2)
            continue;
		ret += dfs(len - 1, i == 6, fp && i == fpmax);
	}
    if(!fp)			//上一位没有枚举到顶，当前的ret表示数位长度为len且满足state条件的总个数，与f数组的含义相同
		f[len][state] = ret;
	return ret;
}

int solve(int x){
	tot = 0;
	f[0][0] = 1;
	while (x){
		a[++tot] = x % 10;
		x /= 10;
	}
	return dfs(tot, false, true);
}
int main(){
	int l, r;
	memset(f, -1, sizeof(f));
	while (scanf("%d%d",&l,&r) && l && r){
		printf("%d\n", solve(r) - solve(l - 1));
	}
	return 0;
}
