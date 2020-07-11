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

char s[N];
int cur[N], mn[N], id[N];

struct SAM
{
    int nxt[N][27], fa[N], len[N];
    int root, tot, last;
    int newnode(int l)
    {
        fa[tot] = -1;
        for (int i = 0; i < 27; ++i)
            nxt[tot][i] = -1;
        len[tot++] = l;
        return tot - 1;
    }
    void init()
    {
        tot = 0;
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
    int getAns(){
        while (~scanf("%s",s)){
            memset(cur, 0, sizeof(cur));
            int tmp = 0;
            int now = 0;
            FORS(i,s){
                int x = s[i] - 'a';
                if (~nxt[now][x]){
                    now = nxt[now][x];
                    tmp++;
                }else{
                    while (~now && nxt[now][x]==-1) now = fa[now];
                    if (now==-1){
                        tmp = now = 0;
                    }else{
                        tmp = len[now] + 1;
                        now = nxt[now][x];
                    }
                }
                cur[now] = max(cur[now], tmp);
            }
            REPD(i, tot - 1, 0){
                int who = id[i];
                mn[who] = min(cur[who], mn[who]);
                if (cur[who] && ~fa[who]) cur[fa[who]] = len[fa[who]];
            }
        }
        int ans = 0;
        FOR(i,tot){
            ans = max(ans, mn[i]);
        }
        return ans;
    }
} sam;

int v[N];

int main(){
    sam.init();
    scanf("%s", s);
    FORS(i, s) sam.extend(s[i] - 'a');
    /**
     * 我们需要用孩子的信息更新father的信息
     * 但是id大的点不一定是id小的点的father
     * 需要按照len从小到大重新编号
     * 使得能在线性时间内更新完所有son对father的信息
    */
    REP(i,1,sam.tot-1) v[sam.len[i]]++;
    int n = strlen(s); 
    REP(i, 1, n) { v[i] += v[i - 1]; }
    REP(i, 1, sam.tot){
        id[v[sam.len[i]]--] = i;
    }
    /**
     * END
    */
    FOR(i, sam.tot) mn[i] = sam.len[i];

    printf("%d\n", sam.getAns());
    return 0;
}
