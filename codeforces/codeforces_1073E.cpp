#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
const int MOD = 998244353;
int a[N], k;
pair<ll, ll> f[N][1030];//f表示剩下数位长度为i且在i+1到更高位数位情况为state的统计情况
ll po[N];
pair<ll,ll> dfs(int pos,int state,bool zero,bool fp){
	if (!pos)
		return make_pair(1, 0);
	if (!fp && ~f[pos][state].first && ~f[pos][state].second)
		return f[pos][state];
	int top = fp ? a[pos] : 9;
	pair<ll, ll> sum = make_pair(0, 0), res;
	for (int i = 0; i <= top;i++)
	{
		int nstate = state | ((zero || i) << i);
		if (__builtin_popcount(nstate)>k)
			continue;
		res = dfs(pos - 1, nstate, zero || i, fp && i == a[pos]);
		sum.first = (sum.first + res.first) % MOD;
		sum.second = (sum.second + res.second + 1ll * i * po[pos - 1] % MOD * res.first % MOD) % MOD;
	}
	if (!fp)
		f[pos][state] = sum;
	return sum;
}
ll solve(ll x){
	int tot = 0;
	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < 1030;j++)
		{
			f[i][j].first = f[i][j].second = -1;
		}
	}
	while (x){
		a[++tot] = x % 10;
		x /= 10;
	}
	return dfs(tot, 0, 0, true).second;
}
int main(){
	ll l, r;
	po[0] = 1;
	for (int i = 1; i <= 18;i++)
	{
		po[i] = po[i - 1] * 10 % MOD;
	}
	scanf("%lld%lld%d", &l, &r, &k);
	printf("%lld\n", (solve(r) - solve(l - 1) + MOD) % MOD);
	return 0;
}
