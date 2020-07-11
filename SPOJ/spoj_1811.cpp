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
const int MOD = 1e9 + 7;
struct SAM
{
    int nxt[N][27], fa[N], len[N];
    int root, tot, last;
    ll dp[N];
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
    int getAns(char *s){
        int slen = strlen(s);
        int now = 0;
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < slen;i++)
        {
            int x = s[i] - 'a';
            if (~nxt[now][x]){
                tmp++;
                now = nxt[now][x];
            }else{
                while (now!=-1 && nxt[now][x]==-1)
                    now = fa[now];
                if (now==-1){
                    now = tmp = 0;
                }else{
                    tmp = len[now] + 1;
                    now = nxt[now][x];
                }
            }
            ans = max(tmp, ans);
        }
        return ans;
    }
} sam;
char s[N], t[N];
int main(){
    sam.init();
    scanf(" %s %s", s, t);
    int slen = strlen(s);
    for (int i = 0; i < slen;i++)
    {
        sam.extend(s[i] - 'a');
    }
    printf("%d\n", sam.getAns(t));
    return 0;
}
