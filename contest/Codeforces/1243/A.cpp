#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = -1e9 - 7;
 
int a[N];
 
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, [](int a, int b) {
            return a > b;
        });
        int ans = 1;
        for (int i = 1; i <= n;i++)
        {
            ans = max(ans, min(i, a[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
