// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORD(I, N) for (int I = N; ~I; --I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, B, A) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 2e5 + 5;
const int BLC = 1e3;

int n, m, S, q;

pi edge[N];
int cnt, he[N], ne[N << 1], v[N << 1], w[N << 1];
int deg[N];
ll V[N];

int Q[N], id[N], tot;
int bel[N], st[BLC], ed[BLC];

int lazy[BLC], cur[N];

ll F[BLC][BLC], G[BLC][BLC];

void add(int x,int y,int i){
	ne[++cnt] = he[x];
	he[x] = cnt;
	v[cnt] = y;
	w[cnt] = i;
}

void Force(int l,int r){
	int k = bel[l];
	REP(i,l,r){
		cur[i] ^= 1;
		int x = edge[i].fi, y = edge[i].sc;
		if (deg[x]>S){
			F[k][id[x]] ^= V[y];
			G[k][id[x]] ^= V[y];
		}
		if (deg[y]>S){
			F[k][id[y]] ^= V[x];
			G[k][id[y]] ^= V[x];
		}
	}
}

void update(int l,int r){
	int u = bel[l], v = bel[r];
	if (u==v) return Force(l, r);
	REP(i,u+1,v-1)
		lazy[i] ^= 1;
	Force(l, ed[u]);
	Force(st[v], r);
}

ll query(int x){
	ll ans = 0;
	if (deg[x]>S){
		REP(i,1,tot){
			ans ^= (lazy[i] ? G[i][id[x]] : F[i][id[x]]);
		}
	}else{
		for (int i = he[x]; i; i = ne[i]){
			int k = w[i];
			int u = v[i];
			ans ^= (lazy[bel[k]] ^ cur[k] ? V[u] : 0);
		}
	}
	return ans;
}

void init(){
	*Q = tot = cnt = 0;
	REP(i,1,n){
		he[i] = 0;
		deg[i] = id[i] = 0;
	}
}
ll Rand(){
	return ((ll)rand() << 30ll) + rand();
}
int main(){
	int _;
	for (scanf("%d", &_); _;--_)
	{
		scanf("%d%d", &n, &m);
		init();
		REP(i, 1, n) V[i] = Rand();
		REP(i,1,m){
			int x, y;
			scanf("%d%d", &x, &y);
			edge[i] = mp(x, y);
			add(x, y, i); add(y, x, i);
			++deg[x]; ++deg[y];
			cur[i] = 1;
		}
		for (S = 1; S * S <= m; S++); --S;
		for (int i = 1; i <= m; i += S){
			lazy[++tot] = 0;
			st[tot] = i;
			ed[tot] = min(m, i + S - 1);
			REP(j, st[tot], ed[tot]) bel[j] = tot;
		}
		REP(i,1,n){
			if (deg[i]>S){
				Q[++*Q] = i;
				id[i] = *Q;
			}
		}
		REP(i,1,*Q){
			REP(j,1,tot)
				F[j][i] = G[j][i] = 0;
			for (int t = he[Q[i]]; t; t = ne[t]){
				F[bel[w[t]]][i] ^= V[v[t]];
			}
		}
		scanf("%d", &q);
		FOR(i,q){
			int op, l, r;
			scanf("%d%d%d", &op, &l, &r);
			if (op==1) update(l, r);
			else putchar((query(l) == query(r)) + '0');
		}
		puts("");
	}
	return 0;
}
