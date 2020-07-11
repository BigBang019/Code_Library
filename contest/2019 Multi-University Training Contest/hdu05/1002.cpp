// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
const int B = 2;
const int MOD = 1e9 + 7;
struct Trie{
	struct NODE{
		int nxt[B];
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
} C, D;
int dfs(){
	int now1 = 0, now2 = 0;
	int ans = 0;
	for (int i = 29; i >= 0; i--)
	{
		bool fl = 0;
		for (int j = 0; j < 2;j++)
		{
			if (C[now1][j] == -1 || D[now2][j] == -1)
				continue;
			if (C[C[now1][j]].cnt == 0 || D[D[now2][j]].cnt == 0)
				continue;
			now1 = C[now1][j];
			now2 = D[now2][j];
			C[now1].cnt--;
			D[now2].cnt--;
			fl = 1;
			break;
		}
		if (fl)
			continue;
		for (int j = 0; j < 2;j++)
		{
			if (C[now1][j] == -1 || D[now2][j ^ 1] == -1)
				continue;
			if (C[C[now1][j]].cnt == 0 || D[D[now2][j ^ 1]].cnt == 0)
				continue;
			now1 = C[now1][j];
			now2 = D[now2][j ^ 1];
			C[now1].cnt--;
			D[now2].cnt--;
			ans += (1 << i);
			break;
		}
	}
	return ans;
}
vector<int> ans;
int main(){
	int _;
	for (scanf("%d", &_); _;_--)
	{
		int n;
		C.init();
		D.init();
		ans.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n;i++)
		{
			int x;
			scanf("%d", &x);
			C.update(x);
		}
		for (int i = 1; i <= n;i++)
		{
			int x;
			scanf("%d", &x);
			D.update(x);
		}
		for (int i = 1; i <= n;i++)
		{
			ans.pb(dfs());
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
