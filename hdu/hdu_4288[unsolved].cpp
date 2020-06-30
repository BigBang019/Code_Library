#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N];
pair<int, int> q[N];
struct NODE{
	ll sum[5];
	int cnt;
	ll & operator [] (ull i) {
		return sum[i];
	}
} tree[N * 4];
int n;
void up(int x){
	tree[x].cnt = tree[2 * x].cnt + tree[2 * x + 1].cnt;
	for (int i = 0; i < 5;i++)
	{
		int k = (i + tree[2 * x].cnt) % 5;
		tree[x][k] = tree[2 * x][k] + tree[2 * x + 1][i];
	}
}
void build(int x,int l,int r){
	if (l==r){
		for (int i = 0; i < 5;i++)
		{
			tree[x][i] = 0;
		}
		tree[x].cnt = 0;
		return;
	}
	int mid = l + r >> 1;
	build(2 * x, l, mid);
	build(2 * x, mid + 1, r);
	up(x);
}
void update(int x,int l,int r,int p,int v,int fl){
	if (l==r){
		if (~fl){
			tree[x].cnt = 1;
			tree[x][1] = v;
		}else{
			tree[x].cnt = 0;
			tree[x][1] = 0;
		}
		return;
	}
	int mid = l + r >> 1;
	if (p>mid)
		update(2 * x + 1, mid + 1, r, p, v, fl);
	else
		update(2 * x, l, mid, p, v, fl);
	up(x);
}
int main(){
	while (~scanf("%d",&n)){
		int tot = 0;
		for (int i = 1; i <= n;i++)
		{
			char sign[3];
			int x;
			scanf(" %s", sign);
			switch(sign[0]){
				case 'a':
					scanf("%d", &x);
					a[++tot] = x;
					q[i] = make_pair(1, x);
					break;
				case 'd':
					scanf("%d", &x);
					a[++tot] = x;
					q[i] = make_pair(2, x);
					break;
				case 's':
					q[i] = make_pair(3, 0);
					break;
			}
		}
		sort(a + 1, a + 1 + tot);
		int m = unique(a + 1, a + 1 + tot) - a - 1;
		build(1, 1, m);
		int d;
		for (int i = 1; i <= n;i++)
		{
			switch(q[i].first){
				case 1:
					d = lower_bound(a + 1, a + 1 + m, q[i].second) - a;
					update(1, 1, m, d, a[d], 1);
					break;
				case 2:
					d = lower_bound(a + 1, a + 1 + m, q[i].second) - a;
					update(1, 1, m, d, a[d], -1);
					break;
				default:
					printf("%lld\n", tree[1][3]);
			}
		}
	}
	return 0;
}
