#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;

struct Q{
	ll l, r, p;
} query[N], ans[N];
int a[N], cnt[N];
int S, n, m;
ll now;
bool cmp(Q a, Q b){
	return (a.l / S == b.l / S ? a.r < b.r : a.l / S < b.l / S);
}
ll gcd(ll a,ll b){
	return b ? gcd(b, a % b) : a;
}

void move(int pos,int v){
	ll tmp = cnt[a[pos]];
	now -= tmp * (tmp - 1) / 2;

	cnt[a[pos]] += v;

	tmp = cnt[a[pos]];
	now += tmp * (tmp - 1) / 2;
}
int main(){
	scanf("%d%d", &n, &m);
	S = sqrt(n);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <= m;i++)
	{
		scanf("%d%d", &query[i].l, &query[i].r);
		query[i].p = i;
	}
	sort(query + 1, query + 1 + m, cmp);
	int l = 1, r = 1;
	now = 0;
	cnt[a[1]]++;
	for (int i = 1; i <= m;i++)
	{
		while(l<query[i].l)
			move(l++, -1);
		while(l>query[i].l)
			move(--l, 1);
		while(r<query[i].r)
			move(++r, 1);
		while(r>query[i].r)
			move(r--, -1);
		ll len = r - l + 1;
		ll d = gcd(now, len * (len - 1) / 2);
		ans[query[i].p].l = now / d;
		ans[query[i].p].r = len * (len - 1) / 2 / d;
	}
	for (int i = 1; i <= m;i++)
	{
		printf("%lld/%lld\n", ans[i].l, ans[i].r);
	}
	return 0;
}
