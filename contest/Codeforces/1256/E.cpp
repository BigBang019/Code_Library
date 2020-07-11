#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
const int INF = -1e9 - 7;
 
int a[N];
 
int dp[N][3];
int ans[N];
int to[N];
 
int pre[N][3];
 
int n;
 
int depp[N];
void getans(int n) {
 
    int num = 0;
    int p = pre[n][3];
    int q = n;
    while (p != 0)
    {
        num++;
		while (q>=p) {
            ans[to[q]] = num;
            q--;
        }
        p = pre[p-1][3];
	}
    printf("%d %d\n", a[to[n]] - a[to[1]] - dp[n][3], num);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}
 
bool cmp(int x,int y) {
    return a[x] < a[y];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        to[i] = i;
        pre[i][1]=0;
		pre[i][2]=0;
		pre[i][3]=0;
	}
    dp[3][1] = INF;
    dp[3][2] = INF;
    dp[3][3] = 0;
 
    pre[3][1] = 1;
    pre[3][2] = 1;
    pre[3][3] = 1;
    sort(to + 1, to + n + 1, cmp);
    for (int i = 1; i < n; ++i)
    {
        depp[i] = a[to[i + 1]] - a[to[i]];
    }
    depp[n] = 0;
    depp[0] = 0;
 
    
 
    for (int i = 4; i <= n; ++i)
    {
        dp[i][1] = dp[i - 1][3] + depp[i - 1];
        pre[i][1] = i;
        dp[i][2] = dp[i - 1][1];
        pre[i][2] = pre[i - 1][1];
 
        if (dp[i-1][2]>dp[i-1][3]) {
            dp[i][3] = dp[i - 1][2];
            pre[i][3] = pre[i - 1][2];
        }
        else
        {
            dp[i][3] = dp[i - 1][3];
            pre[i][3] = pre[i - 1][3];
        }
	}
    getans(n);
    return 0;
}
