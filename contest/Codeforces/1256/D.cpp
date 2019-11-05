#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
 
char s[N];
vector<int> pos;
bool vis[N];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        memset(vis, 0, sizeof(vis));
        pos.clear();
 
        int n;
        ll k;
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < n; ++i)
        {
            if (s[i]=='0'){
                pos.push_back(i);
            }
        }
        int now = 0;
        for (int i = 0; i < pos.size(); ++i)
        {
            int cost = pos[i] - now;
            if (cost>k){
                vis[pos[i] - k] = 1;
                for (int j = pos[i] + 1; j < n; ++j)
                {
                    if (s[j]=='0')
                        vis[j] = 1;
                }
                break;
            }
            k -= cost;
            vis[now++] = 1;
        }
        for (int i = 0; i < n;++i)
        {
            putchar('0' + !vis[i]);
        }
        puts("");
    }
    return 0;
}
