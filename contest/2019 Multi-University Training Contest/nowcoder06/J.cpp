/*******************************************************************************
  贪心：
    枚举最低等级，枚举每行，统计它们的最大白嫖上界，当白嫖上界都为正时要舍弃最小的那个
    每行的白嫖上界预处理就行了
*******************************************************************************/
#pragma GCC optimize(2)
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
ll a[N][N], sum[N][N];
ll d[N];
ll pos[N][N], v[N][N];
ll dm[N];
ll nowV[N];
int main(){
    int _, cas = 0;
    for (scanf("%d", &_); _;_--)
    {
        memset(sum, 0, sizeof(sum));
        memset(v, 0, sizeof(v));
        memset(pos, 0, sizeof(pos));
        memset(dm, 0, sizeof(dm));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++){
                scanf("%lld", &a[i][j]);
                a[i][j] *= -1;
                sum[i][j] = sum[i][j - 1] + a[i][j];
            }
        for (int i = 1; i <= m;i++)
            scanf("%lld", &d[i]);
        for (int i = 1; i <= n;i++)
        {
            int po = -1;
            ll mx = -1e9 - 1;
            for (int j = m; j > 0;j--)
            {
                if (mx+a[i][j]<a[i][j]){//只选新来的那个
                    pos[i][j] = j;
                    po = j;
                    mx = a[i][j];
                }else{//选原先的那个
                    pos[i][j] = po;
                    mx += a[i][j];
                }
                v[i][j] = mx;
            }
        }
        for (int j = 1; j <= m;j++)
        {
            dm[j] = dm[j - 1] + d[j];
        }
        ll ans = 0;
        for (int j = 0; j <= m;j++)
        {
            bool fl = 0;
            ll mn;
            bool hh = 0;
            int po = 0;
            for (int i = 1; i <= n;i++)
            {
                if (v[i][j+1]<=0){
                    fl = 1;
                    break;
                }
                if (!hh){
                    mn = v[i][j + 1];
                    hh = 1;
                    po = i;
                    continue;
                }
                if (mn > v[i][j + 1]){
                    mn = v[i][j + 1];
                    po = i;
                }
            }
            for (int i = 1; i <= n;i++)
            {
                if (!fl && i==po){
                    nowV[i] = 0;
                    continue;
                }
                if (v[i][j+1]>0){
                    nowV[i] = v[i][j + 1];
                }else{
                    nowV[i] = 0;
                }
            }
            ll tmp = dm[j];
            for (int i = 1; i <= n;i++)
            {
                tmp += sum[i][j];
                tmp += nowV[i];
            }
            ans = max(ans, tmp);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
