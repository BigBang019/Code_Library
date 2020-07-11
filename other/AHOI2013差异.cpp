// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((ll)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (ll I = 0; I < (N); ++I)
#define FORD(I, N) for (ll I = N; ~I; --I)
#define REP(I, A, B) for (ll I = A; I <= (B); ++I)
#define REPD(I, B, A) for (ll I = B; I >= A; --I)
#define FORS(I, S) for (ll I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 1e6 + 5;

int n;
char s[N];

struct SAM
{
    int nxt[N][27], fa[N], len[N];
    int sz[N];
    int root, tot, last;
    bool T;//T=1位置不同的相同子串算多个;T=0本质相同的子串只算一次
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
        last = root = newnode(0);
    }
    void extend(int x)
    {
        int p = last;
        int cur = newnode(len[p] + 1);
        sz[cur] = 1;
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
    
    ll getSum(){
        int mx = 0;
        for (int i = 1; i <= tot; i++)
            mx = max(mx, len[i]), ++v[len[i]];
        for (int i = 1; i <= mx; i++)
            v[i] += v[i - 1];
        for (int i = 1; i <= tot; i++){
            id[v[len[i]]--] = i;
        }
        ll ans = 0;
        for (int i = tot; i; i--)
        {
            int t = id[i];
            sz[fa[t]] += sz[t];
            ans += 1ll*(len[t] - len[fa[t]]) * sz[t] * (n - sz[t]);
        }
        return ans;
    }
} sam;


int main(){
    sam.init();
    scanf(" %s", s);
    n = strlen(s);
    FORD(i,n-1){
        sam.extend(s[i] - 'a');
    }
    printf("%lld\n", sam.getSum());
    return 0;
}
