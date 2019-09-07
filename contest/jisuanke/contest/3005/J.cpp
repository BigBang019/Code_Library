#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=3000000;
const long long mod=1E9+7;
typedef long long ll;


struct Edge{
	int from;
	int to;
	int next;
} edge[maxn];
int tot;
int head[maxn];
int n;
int depth;

long long dp[maxn];
long long d[maxn];
 
inline void init() {
	tot=0;
	for (int i=1;i<=n;i++) {
		head[i]=0;
		d[i]=0;
	}
}

inline void addedge(int x,int y) {
	tot++;
	edge[tot].next=head[x];
	edge[tot].from=x;
	edge[tot].to=y;
	head[x]=tot;
	return ;
}

inline ll bin(ll base, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * base % p;
        base = base * base % p;
        n >>= 1;
    }
    return res;
}
inline ll get_inv(ll x, ll p) {  return bin(x, p - 2, p);  }

void dfs(int u, int fa, int dep) {
	if (depth<dep) {
		depth=dep;
	}
	d[u]=0;
	for (int p=head[u];p;p=edge[p].next) {
		int v=edge[p].to;
		if (v==fa) {
			continue;
		}
		d[u]++;
		dfs(v,u,dep+1); 
	}	
}


void solve(int u, int fa, int dep) {
//	printf("?? %d\n", u);
	if (d[u]==0) {
		if (depth==dep) {
			dp[u]=0;
		} else {
			dp[u]=1;
		}
//		printf("!! %lld\n", dp[u]);
		return;
	}
	dp[u]=0;
	long long sum=0;
	for (int p=head[u];p;p=edge[p].next) {
		int v=edge[p].to;
		if (v==fa) {
			continue;
		}
		solve(v,u,dep+1);
		sum=sum+dp[v];
		sum=sum%mod;
	}
	sum=sum*get_inv(d[u], mod)%mod;
	
	dp[u]=bin(sum, d[u], mod);
	return ;
}


int main() {
	scanf("%d", &n);
	for (int i=1;i<n;i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0,1);
	
	solve(1,0,1);
	
//	printf("%d\n", depth);
//	for (int i=1;i<=n;i++) {
//		printf("%lld ", d[i]);
//	}printf("\n");
//	for (int i=1;i<=n;i++) {
//		printf("%lld ", dp[i]);
//	}printf("\n");
	printf("%lld\n", (1-dp[1]+mod)%mod);
	return 0;
}
