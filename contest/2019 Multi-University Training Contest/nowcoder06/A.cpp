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
const int N = 1e5 + 5;
const int MOD = 998244353;
int fn[27];
int vis[4];
char s[N], t[28];
int main(){
    int _, cas = 0;
    for (scanf("%d", &_); _;_--)
    {
        memset(vis, 0, sizeof(vis));
        scanf(" %s %s", s, t);
        int n = strlen(s);
        for (int i = 0; i < 26;i++)
        {
            fn[i] = (t[i] == 'h' ? 0 : (t[i] == 'd' ? 1 : 2));
        }
        for (int i = 0; i < n; i++)
        {
            int x = s[i] - 'a';
            vis[fn[x]]++;
        }
        if (vis[0]*4>=n){
            printf("Case #%d: Harmful\n", ++cas);
        }else if (n>=vis[0]*10){
            printf("Case #%d: Recyclable\n", ++cas);
        }else if (vis[1]>=2*vis[2]){
            printf("Case #%d: Dry\n", ++cas);
        }else{
            printf("Case #%d: Wet\n", ++cas);
        }
    }
    return 0;
}
