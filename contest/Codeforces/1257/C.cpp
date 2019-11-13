#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
 
int last[N];
int a[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        memset(last, 0, sizeof(last));
        cin >> n;
        int ans = n + 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (last[a[i]]){
                ans = min(ans, i - last[a[i]] + 1);
            }
            last[a[i]] = i;
        }
        printf("%d\n", ans == n + 1 ? -1 : ans);
    }
 
    return 0;
}
