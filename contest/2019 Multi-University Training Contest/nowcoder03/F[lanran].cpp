#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef double db;
int a[510][510];
int mi[510][510][20], ma[510][510][20], n;
inline int Max(int aa, int bb) {
    return aa > bb ? aa : bb;
}
inline int Min(int aa, int bb) {
    return aa < bb ? aa : bb;
}
P tmp[510];
const int Log = 10;
const int N = 510;
const int inf = 1e9;
int maxv[Log][Log][N][N];
int minv[Log][Log][N][N];
int pre[N];
inline void init2() {
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) {
        maxv[0][0][i][j] = a[i][j];
        minv[0][0][i][j] = a[i][j];
    }
    pre[2] = pre[3] = 1;
    for (int i = 4, up = n; i <= up; i++)pre[i] = pre[i >> 1] + 1;
    int up1 = pre[n] + 1, up2 = pre[n] + 1;
    for (int l1 = 0; l1 <= up1; l1++) {
        for (int l2 = 0; l2 <= up2; l2++) {
            if (!l1 && !l2) continue;
            for (int i = 1; (i + (1 << l1) - 1) <= n; i++) {
                for (int j = 1; (j + (1 << l2) - 1) <= n; j++) {
                    if (l2) {
                        maxv[l1][l2][i][j] = Max(maxv[l1][l2 - 1][i][j], maxv[l1][l2 - 1][i][j + (1 << (l2 - 1))]);
                        minv[l1][l2][i][j] = Min(minv[l1][l2 - 1][i][j], minv[l1][l2 - 1][i][j + (1 << (l2 - 1))]);
                    }
                    else {
                        maxv[l1][l2][i][j] = Max(maxv[l1 - 1][l2][i][j], maxv[l1 - 1][l2][i + (1 << (l1 - 1))][j]);
                        minv[l1][l2][i][j] = Min(minv[l1 - 1][l2][i][j], minv[l1 - 1][l2][i + (1 << (l1 - 1))][j]);
                    }
                }
            }
        }
    }
}
int queryma(int x1, int y1, int x2, int y2) {
    int p = pre[x2 - x1 + 1], q = pre[y2 - y1 + 1];
    int ans = -inf;
    ans = Max(maxv[p][q][x1][y1], maxv[p][q][x1][y2 - (1 << q) + 1]);
    ans = Max(ans, Max(maxv[p][q][x2 - (1 << p) + 1][y1], maxv[p][q][x2 - (1 << p) + 1][y2 - (1 << q) + 1]));
    return ans;
}
int querymi(int x1, int y1, int x2, int y2) {
    int p = pre[x2 - x1 + 1], q = pre[y2 - y1 + 1];
    int ans = inf;
    ans = Min(minv[p][q][x1][y1], minv[p][q][x1][y2 - (1 << q) + 1]);
    ans = Min(ans, Min(minv[p][q][x2 - (1 << p) + 1][y1], minv[p][q][x2 - (1 << p) + 1][y2 - (1 << q) + 1]));
    return ans;
}
int main() {
    int T, m;
    clock_t st = clock();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        //init();
        init2();
        int wa = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((n - i + 1)*(n - j + 1) < wa)break;
                int y, mn = a[i][j], mx = a[i][j];
                for (y = j; y <= n; y++) {
                    mx = Max(mx, a[i][y]);
                    mn = Min(mn, a[i][y]);
                    if (mx - mn > m)break;
                }
                y--;
                int x = i;
                while (y >= j && x <= n) {
                    wa = Max(wa, (x - i + 1)*(y - j + 1));
                    if ((n - i + 1)*(y - j + 1) < wa)break;
                    if (queryma(i, j, x + 1, y) - querymi(i, j, x + 1, y) <= m)x++;
                    else y--;
                }
            }
        }
        printf("%d\n", wa);
    }
    clock_t et = clock();
    cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
}
