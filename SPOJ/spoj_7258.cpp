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


struct SAM
{
    int nxt[N][27], fa[N], len[N];
    int root, tot, last;
    ll dp[N];
    int newnode(int l)
    {
        ++tot;
        fa[tot] = -1;
        for (int i = 0; i < 27; ++i)
            nxt[tot][i] = -1;
        len[tot] = l;
        return tot;
    }
    void init()
    {
        tot = -1;
        memset(dp, -1, sizeof(dp));
        last = root = newnode(0);
    }
    void extend(int x)
    {
        int p = last;
        int cur = newnode(len[p] + 1);
        while (p != -1 && nxt[p][x] == -1)
        {
            nxt[p][x] = cur;
            p = fa[p];
        }
        if (p == -1)
            fa[cur] = root;
        else
        {
            int q = nxt[p][x];
            if (len[q] == len[p] + 1)
                fa[cur] = q;
            else
            {
                int tmp = newnode(len[p] + 1);
                memcpy(nxt[tmp], nxt[q], sizeof(nxt[q]));
                fa[tmp] = fa[q];
                fa[q] = fa[cur] = tmp;
                while (p != -1 && nxt[p][x] == q)
                {
                    nxt[p][x] = tmp;
                    p = fa[p];
                }
            }
        }
        last = cur;
    }

    int id[N];
    int v[N];
    int sum[N];
    void getSum(){
        for (int i = 1; i <= tot;i++)
            sum[i] = 1;
        int mx = 0;
        for (int i = 1; i <= tot; i++)
            mx = max(mx, len[i]), ++v[len[i]];
        for (int i = 1; i <= mx; i++)
            v[i] += v[i - 1];
        for (int i = 1; i <= tot; i++)
            id[v[len[i]]--] = i;
        for (int i = tot; i; i--)
        {
            int t = id[i];
            for (int j = 0; j < 26;j++)
                sum[t] += sum[nxt[t][j]];
        }
    }
    void solve(){
        int x, now = 0; scanf("%d", &x);
        while (x){
            for (int i = 0; i < 26;i++)
            {
                if (~nxt[now][i]){
                    if (sum[nxt[now][i]]>=x){
                        putchar('a' + i);
                        now = nxt[now][i];
                        --x;
                        break;
                    }else
                        x -= sum[nxt[now][i]];
                }
            }
        }
        puts("");
    }
} sam;

char s[N];
int main(){
    sam.init();
    scanf(" %s", s);
    FORS(i,s){
        sam.extend(s[i] - 'a');
    }
    sam.getSum();
    int q; scanf("%d", &q);
    while (q--) sam.solve();
    return 0;
}
