// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
const int N = 2e6 + 5;
const int B = 31;
struct SAM{
    int next[N][27], fa[N], len[N];
    int root, tot, last;
    ll dp[N];
    int newnode(int l){
        fa[tot] = -1;
        for(int i=0;i<27;++i) next[tot][i] = -1;
        len[tot++] = l;
        return tot - 1;
    }
    void init(){
        tot = 0;
        memset(dp, -1, sizeof(dp));
        last = root = newnode(0);
    }
    void extend(int x){
        int p = last;
        int cur = newnode(len[p] + 1);
        while(p!=-1&&next[p][x]==-1){
            next[p][x] = cur;
            p = fa[p];
        }
        if(p==-1) fa[cur] = root;
        else{
            int q = next[p][x];
            if(len[q]==len[p]+1)
                fa[cur] = q;
            else{
                int tmp = newnode(len[p] + 1);
                memcpy(next[tmp], next[q], sizeof(next[q]));
                fa[tmp] = fa[q];
                fa[q] = fa[cur] = tmp;
                while (p != -1 && next[p][x] == q)
                {
                    next[p][x] = tmp;
                    p = fa[p];
                }
            }
        }
        last = cur;
    }
      
    ll dfs(int u){
        if(dp[u]!=-1) return dp[u];
        ll res = 1;
        for (int i = 0; i < 26; ++i)
        {
            if (next[u][i] == -1) continue;
            res += dfs(next[u][i]);
        }
        return dp[u] = res;
    }
}sam;
  
struct PAM{
    int next[N][26], fail[N], len[N];
    int txt[N];
    int tot, root0, root1, last, size;
    void init(){
        last = tot = size = 0;
        txt[size] = -1;
        root0 = newnode(0);
        root1 = newnode(-1);
        fail[root0] = 1;
        fail[root1] = 0;
    }
    int newnode(int l){
        len[tot] = l;
        memset(next[tot], 0, sizeof(next[tot]));
        tot++;
        return tot - 1;
    }
    int getfail(int x){
        while(txt[size-len[x]-1]!=txt[size]) x = fail[x];
        return x;
    }
    void extend(int c){
        txt[++size] = c;
        int now = getfail(last);
        if(!next[now][c]){
            int tmp = newnode(len[now] + 2);
            fail[tmp] = next[getfail(fail[now])][c];
            next[now][c] = tmp;
        }
        last = next[now][c];
    }
}pam;
  
char s[N];
int n;
  
int main(){
    scanf("%s",s); sam.init(); n=strlen(s); pam.init();
    for(int i=0;i<n;++i) sam.extend(s[i]-'a'); sam.extend(26);
    for(int i=n-1;i>=0;--i) sam.extend(s[i]-'a');
    for(int i=0;i<n;++i) pam.extend(s[i]-'a');
    printf("%lld\n",(sam.dfs(sam.root)+pam.tot-3)/2);
}
