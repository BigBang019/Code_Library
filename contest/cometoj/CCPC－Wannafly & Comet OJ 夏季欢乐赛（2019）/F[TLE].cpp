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
const int N = 2e5 + 5;
const int B = 31;
vector<int> b;
void Init_Hash(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int has(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
int c[N];

vector<pi> vc;
pi q[N];
int lb(int x) { return x & -x; }
void add(int x,int v){
    for (int i = x; i <= b.size(); i += lb(i))
    {
        c[i] += v;
    }
}
int query(int x){
    int sum = 0;
    for (int i = x; i > 0; i -= lb(i))
    {
        sum += c[i];
    }
    return sum;
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vc.pb(mp(x, y));
        b.pb(y + k);
        b.pb(y);
    }
    Init_Hash();
    sort(vc.begin(), vc.end());
    int now = 0, h = 1, t = 0;
    int ans = 0;
    for (int i = 0; i < vc.size(); i++)
    {
        int l = vc[i].fi;
        int r = vc[i].fi + k;
        for (; now < vc.size();now++){
            if (vc[now].fi>r)
                break;
            q[++t] = vc[now];
            add(has(vc[now].sc), 1);
        }
        while (h<=t && q[h].fi<l){
            add(has(q[h++].sc), -1);
        }
        for (int j = h; j <= t;j++)
        {
            int y = q[j].sc;
            ans = max(ans, query(has(y + k)) - query(has(y) - 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}
