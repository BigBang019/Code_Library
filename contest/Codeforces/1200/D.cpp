#pragma GCC optimize(3)
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
const int N = 2e3 + 5;
 
int l[N], r[N];
char maze[N][N];
int n,k;
 
int c1[N][N], c2[N][N], c3[N][N], c4[N][N];
int lowbit(int x){
    return x & (-x);
}
void add(int x, int y, int z){
    for(register int i = x; i <= n; i += lowbit(i))
        for(register int j = y; j <= n; j += lowbit(j)){
            c1[i][j] += z;
            c2[i][j] += z * x;
            c3[i][j] += z * y;
            c4[i][j] += z * x * y;
        }
}
void range_add(int x1, int x2, int y1, int y2, int z){ //(xa, ya) 到 (xb, yb) 的矩形
    add(x1, y1, z);
    add(x1, y2 + 1, -z);
    add(x2 + 1, y1, -z);
    add(x2 + 1, y2 + 1, z);
}
int ask(int x, int y){
    int res = 0;
    for(register int i = x; i; i -= lowbit(i))
        for(register int j = y; j; j -= lowbit(j))
            res += (x + 1) * (y + 1) * c1[i][j]
                - (y + 1) * c2[i][j]
                - (x + 1) * c3[i][j]
                + c4[i][j];
    return res;
}
int range_ask(int x1, int x2, int y1, int y2){
    return ask(x2, y2) - ask(x2, y1 - 1) - ask(x1 - 1, y2) + ask(x1 - 1, y1 - 1);
}
 
int main(){
    scanf("%d%d", &n, &k);
    for (register int i = 1; i <= n;++i)
    {
        scanf(" %s", maze[i] + 1);
    }
    for (register int i = 1; i <= n; ++i)
    {
        int l = 0;
        for (register int j = 1; j <= n; ++j)
        {
            if (maze[i][j]=='B') break;
            l = j;
        }
        int r = n + 1;
        for (register int j = n; j >= 1; --j)
        {
            if (maze[i][j]=='B') break;
            r = j;
        }
        if (r==1 && l==n){
            range_add(1, n, 1, n, 1);
            continue;
        }
        if (l+1>=r-k)
            range_add(max(1, i - k + 1), i, max(1, r - k), min(l + 1, n), 1);
    }
    for (register int j = 1; j <= n; ++j)
    {
        int l = 0, r = n + 1;
        for (register int i = 1; i <= n; ++i)
        {
            if (maze[i][j]=='B') break;
            l = i;
        }
        for (register int i = n; i >= 1; --i)
        {
            if (maze[i][j]=='B') break;
            r = i;
        }
        if (r==1 && l==n){
            range_add(1, n, 1, n, 1);
            continue;
        }
        if (l+1>=r-k)
            range_add(max(1, r - k), min(l + 1, n), max(j - k + 1, 1), j, 1);
    }
    int ans = 0;
    for (register int i = 1; i <= n;++i) for (register int j = 1; j <= n;++j){
        ans = max(ans, range_ask(i, i, j, j));
    }
    printf("%d\n", ans);
    return 0;
}
close
