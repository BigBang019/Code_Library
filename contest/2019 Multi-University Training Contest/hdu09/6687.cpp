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
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int BIT = 2;
struct Trie{
	struct NODE{
		int nxt[BIT];
		int cnt;
		NODE() { memset(nxt, -1, sizeof(nxt)), cnt = 0; }
		int &operator [] (ull i){
			return nxt[i];
		}
	};
	NODE &operator [] (ull i){
		return po[i];
	}
	vector<NODE> po;
	void init(){
		po.clear();
		po.pb(NODE());
	}
	void update(int a){
		int now = 0;
		for (int i = 29; i >= 0; i--)
		{
			bool x = a & (1 << i);
			if (po[now][x]==-1){
				po[now][x] = po.size();
				po.pb(NODE());
			}
			now = po[now][x];
			po[now].cnt++;
		}
	}
} B, G;
ll match(int x,int y,int dep){
    if (x && y) --B[x].cnt, --G[y].cnt;
    if (dep==-1){
        return 0;
    }
    if (~B[x][0] && ~G[y][1] && B[B[x][0]].cnt && G[G[y][1]].cnt){
        return match(B[x][0], G[y][1], dep - 1) + (1ll << dep);
    }
    if (~B[x][1] && ~G[y][0] && B[B[x][1]].cnt && G[G[y][0]].cnt){
        return match(B[x][1], G[y][0], dep - 1) + (1ll << dep);
    }
    if (~B[x][0] && ~G[y][0] && B[B[x][0]].cnt && G[G[y][0]].cnt){
        return match(B[x][0], G[y][0], dep - 1);
    }
    if (~B[x][1] && ~G[y][1] && B[B[x][1]].cnt && G[G[y][1]].cnt){
        return match(B[x][1], G[y][1], dep - 1);
    }
}
int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        int n;
        B.init(), G.init();
        scanf("%d", &n);
        FOR(i, n){
            int x; scanf("%d",&x);
            B.update(x);
        }
        FOR(i,n){
            int x; scanf("%d",&x);
            G.update(x);
        }
        ll ans = 0;
        FOR(i,n){
            ans += match(0, 0, 29);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
