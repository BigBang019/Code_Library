#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;

int T[N], tot, nex[N * 10][30], cot[N * 10];

int cnt, he[N], ne[N * 2], v[N * 2];
string w[N * 2];

int dep[N], f[N][30];

void init(){
    cnt = 0;
    T[0] = 0;
    tot = 0;
    memset(he, 0, sizeof(he));
}
void add(int x,int y,string z){
    cnt++;
    v[cnt] = y;
    ne[cnt] = he[x];
    w[cnt] = z;
    he[x] = cnt;
}
void insert(int &rt,int la,string s,int p){
    rt = ++tot;
    int now = tot;
    cot[now] = cot[la] + 1;
    for (int i = 0; i < 26;i++)
    {
        nex[now][i] = nex[la][i];
    }
    if (p+1 < s.size())
        insert(nex[now][s[p + 1] - 'a'], nex[la][s[p + 1] - 'a'], s, p + 1);
}
void dfs(int x,int fa,int dp){
    f[x][0] = fa;
    dep[x] = dp;
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fa)
            continue;
        insert(T[p], T[x], w[i], -1);
        dfs(p, x, dp + 1);
    }
}
int query(int now,string s){
    int sum = 0;
    for (int i = 0; i < s.size();i++)
    {
        int p = s[i] - 'a';
        if (nex[now][p]){
            now = nex[now][p];
        }else
            return 0;
    }
    return cot[now];
}
void LCA(){
    for (int j = 1; (1 << j) <= n;j++)
    {
        for (int i = 1; i <= n;i++)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
}
int getlca(int x,int y){
    if (dep[x]<dep[y])
        swap(x, y);
    for (int j = 24; j >= 0;j--)
    {
        int fx = f[x][j];
        if (dep[fx]>=dep[y]){
            x = fx;
        }
    }
    for (int j = 24; j >= 0;j--)
    {
        int fx = f[x][j];
        int fy = f[y][j];
        if (fx==fy)
            continue;
        x = fx;
        y = fy;
    }
    if (x!=y){
        x = f[x][0];
    }
    return x;
}

char s[100];
int main(){
    scanf("%d", &n);
    init();
    for (int i = 1; i < n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        scanf(" %s", s);
        add(x, y, s);
    }
    dfs(1, 0, 1);
    LCA();
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        scanf(" %s", s);
        int lca = getlca(x, y);
        int a1 = query(T[x], s);
        int a2 = query(T[y], s);
        int a3 = query(T[lca], s);
        printf("%d\n", a1 + a2 - 2 * a3);
    }
    return 0;
}
