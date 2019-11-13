#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, r;

int tot;

int x[N << 2], y[N << 2];

struct NODE{
    int cnt;
    int pos;
    bool operator > (const NODE & b) const {
        return cnt > b.cnt;
    }
    NODE(){}
    NODE(int pos, int cnt) : cnt(cnt), pos(pos){}
} X[N], Y[N];

map<int, int> vis[N << 2];

int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        ++vis[x0][y0];
        ++x[x0];
        ++y[y0];
    }
    tot = 0;
    for (int i = 0; i <= 1e5; ++i){
        ++tot;
        X[i] = NODE(i, x[i] + x[i + r] + x[i + 2 * r]);
        Y[i] = NODE(i, y[i] + y[i + r] + y[i + 2 * r]);
    }
    sort(X, X + tot + 1, [](NODE a, NODE b) {
        return a > b;
    });
    sort(Y, Y + tot + 1, [](NODE a, NODE b) {
        return a > b;
    });
    int ans = 0;
    for (int i = 0; i <= tot; ++i)
    {
        int x = X[i].pos;
        for (int j = 0; j <= tot; ++j)
        {
            int y = Y[j].pos;
            int now = X[i].cnt + Y[j].cnt;
            if (ans >= now)
            {
                break;
            }
            now -= vis[x][y] + vis[x][y + r] + vis[x][y + 2 * r] + vis[x + r][y] + vis[x + r][y + r] + vis[x + r][y + 2 * r] + vis[x + 2 * r][y] + vis[x + 2 * r][y + r] + vis[x + 2 * r][y + 2 * r];
            ans = max(ans, now);
        }
    }
    printf("%d\n", ans);
    return 0;
}
