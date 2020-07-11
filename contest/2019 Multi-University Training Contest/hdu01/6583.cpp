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

ll q, p;
char s[N];
ll f[N];
int n;

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
    void work(){
        init();
        f[0] = 0;
        f[1] = p;
        extend(s[1] - 'a');
        int j = 1;
        int now = 0;
        for (int i = 2; i <= n;i++)
        {
            int x = s[i] - 'a';
            if (~nxt[now][x]){
                now = nxt[now][x];
            }else{
                while (~now && nxt[now][x]==-1){
                    now = fa[now];
                    while (j < i - len[now] - 1){
                        extend(s[++j] - 'a');   //***get a instant update to SAM***
                    }
                }
                if (now==-1){
                    now = 0;
                    extend(s[++j] - 'a');       //if not, j will be i-1, which is not what we want
                }else{
                    now = nxt[now][x];          //transfer to next state
                }
            }
            f[i] = f[i - 1] + p;
            if (j<i) f[i] = min(f[i], f[j] + q);//if j>=i, then no match
        }
    }
    
} sam;


int main(){
    while (~scanf("%s", s + 1))
    {
        n = strlen(s + 1);
        scanf("%lld%lld", &p, &q);
        sam.work();
        printf("%lld\n", f[n]);
    }
    return 0;
}
