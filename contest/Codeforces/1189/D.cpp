#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n;
int deg[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        deg[x]++;
        deg[y]++;
    }
    ll e = n - 1;
    ll le = 0;
    ll va = 0;
    bool fl = 0;
    for (int i = 1; i <= n;i++)
    {
        if (deg[i]==1)
            le++;
        if (deg[i]==2)
            fl = 1;
    }
    va = (le - 1) * le / 2;
    printf("%s\n", (va >= e && !fl) ? "YES" : "NO");
    return 0;
}
