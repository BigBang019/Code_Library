// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
const int N = 2e6 + 5;
const int B = 31;
int a[N];
bool vis[N];
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 2; i <= n;i++)
    {
        if (!vis[i-1] && abs(a[i] - a[i - 1]) < k)
        {
            ans++;
            vis[i] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
