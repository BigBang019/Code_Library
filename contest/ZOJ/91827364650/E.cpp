#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct NODE{
	int p, v;
	bool operator < (const NODE & a) const {
		return this->v < a.v;
	}
	bool operator > (const NODE & a) const {
		return a < (*this);
	}
} a[N];
int d[N];
int c[N];
int n, cnt;
int lowbit(int x){
	return x & (-x);
}
void add(int x){
	for (int i = x; i <= cnt;i+=lowbit(i))
	{
		c[i]++;
	}
}
int query(int x){
	int sum = 0;
	for (int i = x; i > 0;i-=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for (int i = 1; i <= n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].p = i;
		}
		sort(a+1,a+1+n);
		cnt = 0;
		for (int i = 1; i <= n;i++)
		{
			if (i==1 || a[i].v!=a[i-1].v){
				cnt++;
			}
			d[a[i].p] = cnt;
		}
		int ans=0;
		int ma = 0;
		for (int i = 1; i <= n;i++)
		{
			add(d[i]);
			if (query(d[i])<i){
				ma = max(ma,query(d[i]-1)-ans);
				ans++;
			}
		}
		printf("%d\n", ans + ma);
	}
	return 0;
}
