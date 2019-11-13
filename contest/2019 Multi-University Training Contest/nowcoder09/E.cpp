#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

int sz[N];
int f[N];
int n, m;

__int128_t C[N][5];

void init(){
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= min(4, i); ++j)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void print(__int128_t x){
    if (x>9)
        print(x / 10);
    putchar('0' + (x % 10));
}

int getf(int x){
    return (x == f[x] ? x : f[x] = getf(f[x]));
}

int main(){
    scanf("%d%d", &n, &m);
    init();
    __int128_t ans = C[n][4];
    __int128_t allS = 0;
    print(ans);
    puts("");
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = getf(a);
        int fb = getf(b);
        if (fa != fb){
            int A = sz[fa];
            int B = sz[fb];
            ans -= C[A][1] * C[B][1] * (C[n - A - B][2] - allS + C[A][2] + C[B][2]);
            allS -= C[A][2];
            allS -= C[B][2];
            allS += C[A + B][2];

            f[fa] = fb;
            sz[fb] += sz[fa];
        }
        print(ans);
        puts("");
    }
    return 0;
}
