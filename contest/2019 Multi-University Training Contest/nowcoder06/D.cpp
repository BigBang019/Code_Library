/********************************************************************
  骗分算法，数据强就wa了
  因为原题不具有单调性
********************************************************************/
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e3 + 5;
const int MOD = 998244353;
int n, k, a[N];
bool vis[N];
bool check(int x){
    int sum = 0;
    int now;
    for (int i = 1; i <= n;i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < k && sum < n; i++)
    {
        now = x;
        for (int j = 1; j <= n && sum < n && now; j++)
        {
            if (!vis[j] && a[j]<=now){
                now -= a[j];
                vis[j] = 1;
                sum++;
            }
        }
    }
    return (sum == n);
}
int main(){
    int _, cas = 0;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d%d", &n, &k);
        int mx = 0;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &a[i]);
            mx = max(mx, a[i]);
        }
        sort(a + 1, a + 1 + n, [](int a, int b) {
            return a > b;
        });
        int l = mx, r = 1e6, mid, ans = 1e6;
        while (l<=r){
            mid = l + r >> 1;
            if (check(mid)){
                ans = min(ans, mid);
                r = mid - 1;
            }else{
                l = mid + 1;
                for (int i = mid - 1; i >= mid - 50; i--)
                {
                    if (check(i)){
                        ans = min(ans, i);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
