// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
// using namespace std;
// typedef long long ll;
// typedef unsigned int uint;
// typedef pair<int, int> pi;
// const int N = 2e5 + 5;
// const int B = 31;
namespace AC{
    typedef long long ll;
    using namespace std;
    const int N = 1e6 + 5;
    int nxt[N][30], fail[N];
    bool en[N];
    int tot, root;
    int newNODE(){
        tot++;
        for (int i = 0; i < 2;i++)
            nxt[tot][i] = -1;
        en[tot] = 0;
        return tot;
    }
    void init(){
        tot = 0;
        root = newNODE();
    }
    void update(char *s){
        int len = strlen(s);
        int now = root;
        for (int i = 0; i < len;i++)
        {
            int p = s[i] - '0';
            if (nxt[now][p]==-1)
                nxt[now][p] = newNODE();
            now = nxt[now][p];
        }
        en[now] = 1;
    }
    void build(){
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < 2;i++)
        {
            if (nxt[root][i]==-1)
                nxt[root][i] = root;
            else{
                int x = nxt[root][i];
                fail[x] = root;
                q.push(x);
            }
        }
        while (!q.empty()){
            int now = q.front(); 
            q.pop();
            for (int i = 0; i < 2;i++)
            {
                if (nxt[now][i]==-1)
                    nxt[now][i] = nxt[fail[now]][i];
                else{
                    int x = nxt[now][i];
                    en[x] |= en[nxt[fail[now]][i]];
                    fail[x] = nxt[fail[now]][i];
                    q.push(x);
                }
            }
        }
    }
}
using namespace AC;
bool vis[N], ins[N];
bool dfs(int x){
    ins[x] = 1;
    for (int i = 0; i < 2;i++)
    {
        int p = nxt[x][i];
        if (ins[p])
            return 1;
        if (en[p] || vis[p])
            continue;
        if (vis[p])
            continue;
        vis[p] = 1;
        if (dfs(p))
            return 1;
    }
    ins[x] = 0;
    return 0;
}
char s[N];
int main(){
    int n;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n;i++)
    {
        scanf(" %s", s);
        update(s);
    }
    build();
    printf("%s", dfs(root) ? "TAK" : "NIE");
    return 0;
}
