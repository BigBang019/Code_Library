#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n;
int cnt, he[N], ne[N << 1], v[N << 1];

int len[N], son[N];

int *id, tmp[N << 2], *f[N], ans[N];

void add(int x, int y)
{
    ++cnt;
    ne[cnt] = he[x];
    v[cnt] = y;
    he[x] = cnt;
}
void dfs1(int x,int fa){
    len[x] = 1;
    son[x] = 0;
    for (int i = he[x]; i; i = ne[i])
    {
        int p = v[i];
        if (p==fa)
            continue;
        dfs1(p, x);
        if (len[x] < len[p] + 1)
        {
            len[x] = len[p] + 1;
            son[x] = p;
        }
    }
}

void dfs2(int x,int fa){
    f[x][0] = 1;
    if (son[x])
    {
        f[son[x]] = f[x] + 1;
        dfs2(son[x], x);
        ans[x] = ans[son[x]] + 1;
    }
    for (int i = he[x]; i;i=ne[i])
    {
        int p = v[i];
        if (p==fa || p==son[x])
            continue;
        f[p] = id;
        id += len[p];
        dfs2(p, x);
        for (int j = 0; j < len[p];++j)
        {
            f[x][j + 1] += f[p][j];
            if (j+1<ans[x] && f[x][j+1]>=f[x][ans[x]] || j+1>ans[x] && f[x][j+1]>f[x][ans[x]]){
                ans[x] = j + 1;
            }
        }
        id -= len[p];
    }
    if (f[x][ans[x]]==1)
        ans[x] = 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n;++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0);
    f[1] = id = tmp;
    id += len[1];
    dfs2(1, 0);
    for (int i = 1; i <= n;++i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
