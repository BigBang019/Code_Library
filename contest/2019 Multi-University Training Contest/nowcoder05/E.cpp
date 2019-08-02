/**********************************************************
  状压dp
  本来想lb=i&-x; who=log(lb)/log(2)求状态i的最低位位置
  但是TLE
  可以学一下这个人的技巧（虽然他求的不是最低位）
**********************************************************/
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
const int N = 26;
const int MOD = 998244353;
int n, m;
char f[1 << N];
int C[N];
int main(){
    f[0] = '0';
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        C[x] |= (1 << y);
        C[y] |= (1 << x);
    }
    for (int i = 0; i < n;i++)
    {
        C[i] |= (1 << i);
        C[i] = ~C[i];
    }
    int ans = 0;
    int who = 0;
    for (int i = 1; i < (1 << n);i++)
    {
        if (!((i>>who)&1)) who++;
        f[i] = max(f[i - (1<<who)], (char)(f[i & (C[who])] + 1));
        ans += f[i] - '0';
    }
    printf("%d\n", ans);
    return 0;
}
