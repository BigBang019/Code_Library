// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
vector<ll> s, p;
ll mn[N];
void work(){
    s.clear();
    p.clear();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        s.push_back(x);
        p.push_back(y);
    }
    memset(mn, -1, sizeof(mn));
    for (int i = n - 1; i >= 0; i--)
    {
        ll sx = s[i];
        ll px = p[i];
        mn[i] = mn[i + 1] == -1 ? sx * px : min(mn[i + 1], sx * px);
    }
    while (m--){
        int q;
        scanf("%d", &q);
        int id = lower_bound(s.begin(), s.end(), q) - s.begin();
        if (s[id]!=q)
            id--;
        printf("%lld\n", mn[id + 1] == -1 ? q * p[id] : min(q * p[id], mn[id + 1]));
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
