#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int n;
int f[N][30], dep[N];
int g[N][30];
int cnt, he[N], ne[N * 2], v[N * 2], w[N * 2];
void add(int x,int y,int z){
    cnt++;
    ne[cnt] = he[x];
    v[cnt] = y;
    w[cnt] = z;
    he[x] = cnt;
}
void LCA(){
    for (int j = 1; (1 << j) <= n;j++)
    {
        for (int i = 1; i <= n;i++)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
            g[i][j] = g[f[i][j - 1]][j - 1] + g[i][j - 1];
        }
    }
}
pair<int,int> getDis(int x,int y){//x深度深一些
    int sum1 = 0, sum2 = 0;
    for (int j = 22; j >= 0;j--)
    {
        int fx = f[x][j];
        if (dep[fx]>=dep[y]){
            x = fx;
            sum1 += (1 << j);
        }
    }
    for (int j = 22; j >= 0;j--)
    {
        int fx = f[x][j];
        int fy = f[y][j];
        if (fx==fy)
            continue;
        x = fx;
        y = fy;
        sum1 += (1 << j);
        sum2 += (1 << j);
    }
    if (x!=y){
        sum1++;
        sum2++;
    }
    return make_pair(sum1, sum2);
}
int getDist(int x,int y){
    int sum = 0;
    if (dep[x]<dep[y])
        swap(x, y);
    for (int j = 22; j >= 0;j--)
    {
        int fx = f[x][j];
        if (dep[fx]>=dep[y]){
            sum += g[x][j];
            x = fx;
        }
    }
    for (int j = 22; j >= 0;j--)
    {
        int fx = f[x][j];
        int fy = f[y][j];
        if (fx==fy)
            continue;
        sum += g[x][j];
        sum += g[y][j];
        x = fx;
        y = fy;
    }
    if (x!=y){
        sum += g[x][0] + g[y][0];
    }
    return sum;
}
int getNode(int x,int k){
    for (int j = 22; j >= 0;j--)
    {
        if ((1<<j)>k)
            continue;
        k -= (1 << j);
        x = f[x][j];
    }
    return x;
}
int getNode(int x,int y,int k){
    int xx = (dep[x] > dep[y] ? x : y);
    int yy = (xx == x ? y : x);
    pair<int, int> res = getDis(xx, yy);
    int total = res.first + res.second;
    if (xx!=x){//x不是深的那个
        k = total - k;
    }
    if (k>res.first)
        return getNode(yy, total - k);
    else
        return getNode(xx, k);
}
void dfs(int x,int fa,int dp){
    f[x][0] = fa;
    dep[x] = dp;
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fa)
            continue;
        g[p][0] = w[i];
        dfs(p, x, dp + 1);
    }
}
void init(){
    cnt = 0;
    memset(he, 0, sizeof(he));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
}
char s[100];
void work(){
    init();
    scanf("%d", &n);
    for (int i = 1; i < n;i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0, 1);
    LCA();
    while (true){
        scanf(" %s", s);
        if (s[0]=='D' && s[1]=='I'){
            int a, b;
            scanf("%d%d",&a,&b);
            printf("%d\n", getDist(a, b));
        }else if (s[0]=='K'){
            int a, b, k;
            scanf("%d%d%d", &a, &b, &k);
            printf("%d\n", getNode(a, b, k - 1));
        }else
            break;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
