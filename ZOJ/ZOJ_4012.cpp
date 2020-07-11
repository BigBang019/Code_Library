#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const int K = 6;
const ll inf = 0x7fffffff;
//namespace KDTREE{
int dim;
int k;
bool smaller;
struct NODE{
	ll d[K];
	ll l[K],r[K];					//初始化时要让l=r=d
	int lc, rc;
	bool operator < (const NODE & a) const {
        return d[dim] < a.d[dim];
    }
    bool operator > (const NODE & a) const {
        return a < (*this);
    }
} point[N]; 							//起点从0开始
priority_queue<pair<ll, NODE> > q;
ll square(ll x){
	return x * x;
}
ll distance(NODE a,NODE b){
	ll sum = 0;
	for (int i = 0; i < k;i++)
	{
		sum += square(a.d[i] - b.d[i]);
	}
	return sum;
}
NODE tree[N << 2];
int tot;
void up(int x){
	int lc = tree[x].lc;
	int rc = tree[x].rc;
	for (int i = 0; i < k;i++)
	{
		if (~lc){
			tree[x].l[i] = min(tree[x].d[i], min(tree[x].l[i], tree[lc].l[i]));
			tree[x].r[i] = max(tree[x].d[i], max(tree[x].r[i], tree[lc].r[i]));
		}
		if (~rc){
			tree[x].l[i] = min(tree[x].d[i], min(tree[x].l[i], tree[rc].l[i]));
			tree[x].r[i] = max(tree[x].d[i], max(tree[x].r[i], tree[rc].r[i]));
		}		
	}
}
void build(int l,int r,int dep){	//[l,r]
	tot++;
	int now = tot;
	dim = dep % k;
	int mid = (l + r) / 2;
	nth_element(point + l, point + mid, point + r + 1);
	tree[now] = point[mid];
	tree[now].lc = tree[now].rc = -1;
	if (l<mid){
		tree[now].lc = tot + 1;
		build(l, mid - 1, dep + 1);
	}
	if (mid<r){
		tree[now].rc = tot + 1;
		build(mid + 1, r, dep + 1);
	}
	up(now);
}
void build(int l,int r){
	tot = 0;
	build(l,r,0);
}
bool judge(NODE x, pair<ll,ll> line){
    ll a = line.first, b = line.second;
    bool f1 = (a * x.l[1] <= a * b - b * x.r[0]) && (a * x.r[1] >= b * a - b * x.r[0]);
    bool f2 = (a * x.l[1] <= a * b - b * x.l[0]) && (a * x.r[1] >= b * a - b * x.l[0]);
    bool f3 = (b * x.l[0] <= a * b - a * x.l[1]) && (b * x.r[0] >= b * a - a * x.l[1]);
    bool f4 = (b * x.l[0] <= a * b - a * x.r[1]) && (b * x.r[0] >= b * a - a * x.r[1]);
    return (f1 || f2 || f3 || f4);
}
bool online(NODE x, pair<ll, ll> line){
    ll a = line.first, b = line.second;
    return (a * x.d[1] == a * b - b * x.d[0]);
}
void query(int x,pair<ll,ll> line,int & cnt){
    if (online(tree[x],line))
        cnt++;
    int xx = tree[x].lc;
    int yy = tree[x].rc;
    if (~xx && judge(tree[xx], line))
        query(xx, line, cnt);
    if (~yy && judge(tree[yy], line))
        query(yy, line, cnt);
}
int query(pair<ll,ll> line){
    int ans = 0;
    query(1, line, ans);
    return ans;
}
//}
int n, m;
void work(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld%lld", &point[i].d[0], &point[i].d[1]);
        point[i].l[0] = point[i].r[0] = point[i].d[0];
        point[i].l[1] = point[i].r[1] = point[i].d[1];
    }
    build(1, n);
    
    for (int i = 1; i <= m;i++)
    {
        pair<ll, ll> a;
        scanf("%lld%lld", &a.first, &a.second);
        printf("%d\n", query(a));
    }
}
int main(){
    int t;
    scanf("%d",&t);
    k = 2;
    while (t--)
    {
        work();
    }
    return 0;
}
