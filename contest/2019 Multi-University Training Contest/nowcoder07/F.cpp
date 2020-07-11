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
const int R = 2e5;

set<int> S;

vector<int> add[N], del[N];

int C[N], E[N], L[N], n, m;

int c1[N], c2[N];
int lb(int x) { return x & -x; }
void update(int x,int v){
	for (int i = x; i <= R; i += lb(i))
	{
		c1[i] += v;
		c2[i] += x * v;
	}
}
pair<int,int> query(int x){
	pair<int, int> res = mp(0, 0);
	for (int i = x; i > 0; i -= lb(i))
	{
		res.fi += c1[i];
		res.sc += c2[i];
	}
	return res;
}

void s_ins(int x){
	auto it = S.insert(x).fi, l = it, r = it;
	if (S.size()==1) return;
	if (l!=S.begin() && r!=--S.end()){
		update(*(++r) - x, 1);
		update(x - *(--l), 1);
		update(*r - *l, -1);
	}else if (l!=S.begin()){
		update(x - *(--l), 1);
	}else {
		update(*(++r) - x, 1);
	}
}
void s_del(int x){
	auto it = S.find(x), l = it, r = it;
	if (S.size()==1) return;
	if (l!=S.begin() && r!=--S.end()){
		update(*(++r) - x, -1);
		update(x - *(--l), -1);
		update(*r - *l, 1);
	}else if (l!=S.begin()){
		update(x - *(--l), -1);
	}else{
		update(*(++r) - x, -1);
	}
	S.erase(it);
}

void init(){
	S.clear();
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	REP(i,1,n){
		add[i].clear();
		del[i].clear();
	}
}

int main(){
	int _, cas = 0;
	for (scanf("%d", &_); _;--_)
	{
		scanf("%d", &n);
		init();
		REP(i,1,n){
			scanf("%d%d%d", E + i, L + i, C + i);
		}
		scanf("%d", &m);
		REP(i,1,m){
			int t, l, r;
			scanf("%d%d%d", &t, &l, &r);
			add[l].pb(t);
			del[r].pb(t);
		}
		ll ans = 0;
		S.insert(0);
		REP(i,1,n){
			for (auto x : add[i]){
				s_ins(x);
			}

			if (S.size()<=1) continue;
			
			if (L[i]==0){
				ans += E[i];
			}else{
				int t = C[i] / L[i];
				pair<int, int> res = t ? query(t) : mp(0, 0);
				ans += 1ll * res.sc * L[i] + 1ll * (S.size() - res.fi - 1) * C[i];

				auto it=S.lower_bound(1);
				if (1ll * *it * L[i] < C[i])
				{
					ans += min(C[i] - *it * L[i], E[i]);
				}
			}

			for (auto x : del[i]){
				s_del(x);
			}
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
