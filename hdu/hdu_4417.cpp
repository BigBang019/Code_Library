#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Q{
	int l, r, h, p;
	bool operator < (const Q & b) const{
		return h < b.h;
	}
} query[N];
pair<int, int> a[N];
int b[N];
int ans[N];
int c[N];
int n, m;
int lowbit(int x){
	return x & (-x);
}
void add(int x,int v){
	for (int i = x; i <= n;i+=lowbit(i))
	{
		c[i] += v;
	}
}
int getSum(int x){
	int sum = 0;
	for (int i = x; i > 0;i-=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
void work(int cas){
	memset(c, 0, sizeof(c));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m;i++)
	{
		scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].h);
		query[i].l++;
		query[i].r++;
		query[i].p = i;
	}
	sort(query + 1, query + 1 + m);
	int ind = 0;
	a[ind] = make_pair(-1, 0);
	for (int i = 1; i <= m;i++)
	{
		while (ind<n && a[ind + 1].first <= query[i].h)
		{
			add(a[++ind].second, 1);
		}
		ans[query[i].p] = getSum(query[i].r) - getSum(query[i].l - 1);
	}
	printf("Case %d:\n", cas);
	for (int i = 1; i <= m;i++)
	{
		printf("%d\n", ans[i]);
	}
}
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t;i++)
	{
		work(i);
	}
	return 0;
}
