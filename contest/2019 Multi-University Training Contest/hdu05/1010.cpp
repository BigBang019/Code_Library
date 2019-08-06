// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 5e4 + 5;
const int MOD = 1e9 + 7;
int n, b[N];
bool vis[N << 1];
int highn, lown, high[N], low[N];
vector<pi> d[N << 1];
void init(){
    highn = 0;
    lown = 0;
    for (int i = 1; i <= 2 * n;i++)
    {
        vis[i] = 0;
        d[i].clear();
    }
}
int get_left_bound(int x){
    int ans = 1, mid, l = -1, r = highn - 1;
    while (l<r){
        mid = l + r + 1 >> 1;
        if (abs(b[high[mid]]) <= x) l = mid;
        else r = mid - 1;
    }
    if (~l) ans = n + high[l];
    l = -1, r = lown - 1;
    while (l<r){
        mid = l + r + 1 >> 1;
        if (abs(b[low[mid]]) >= x) l = mid;
        else r = mid - 1;
    }
    if (~l) ans = max(ans, low[l] + n);
    return ans;
}
bool invalid(){
    multiset<int> s;
    for (int i = 1; i <= 2 * n;i++)
    {
        for (auto pp : d[i])
        {
            s.insert(pp.fi);
        }
        if (s.empty() || *s.begin()<i) return 1;
        s.erase(s.begin());
    }
    return 0;
}
int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n;i++)
        {
            vis[abs(b[i])] = 1;
            d[get_left_bound(abs(b[i]))].pb(mp(n + i - 1, abs(b[i])));
            if (b[i]>0){
                while (highn && abs(b[high[highn - 1]]) > abs(b[i])) highn--;
                high[highn++] = i;
            }else{
                while (lown && abs(b[low[lown - 1]]) < abs(b[i])) lown--;
                low[lown++] = i;
            }
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (!vis[i]){
                d[get_left_bound(i)].pb(mp(2 * n, i));
            }
        }
        if (invalid()){
            puts("-1");
            continue;
        }
        set<int> s;
        for (int i = 0; i < d[1].size(); i++)
        {
            s.insert(d[1][i].sc);
        }
        vector<int> ans;
        for (int i = 1; i < n;i++)
        {
            ans.pb(*s.begin());
            s.erase(s.begin());
        }
        for(int i = n; i < 2 *n; i++) {
            for(int j = 0; j < d[i].size(); j++) {
                s.insert(d[i][j].second);
            }
            int me = abs(b[i - n + 1]);
            if(s.count(me)) {
                ans.push_back(me);
                s.erase(me);
            }
            else {
                ans.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
        for(int i = 0; i < d[2 * n].size(); i++) {
            s.insert(d[2 * n][i].second);
        }
        ans.push_back(*s.begin());
        for(int i = 0; i < 2 * n; i++) printf("%d%c", ans[i], " \n"[i == 2 * n - 1]);
    }
    return 0;
}
