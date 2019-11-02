#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;
const int N =2e3 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;
 
int n, f[N];
struct node{
    ll x, y;
    node(){}
    node(ll x,ll y):x(x),y(y){}
} a[N];
 
ll spend[N];
 
 
struct edge{
    int x, y;
    ll v;
    edge(){
    }
    edge(int x, int y, ll v):x(x),y(y),v(v){}
    bool operator < (const edge & b) const {
        return v < b.v;
    }
    bool operator > (const edge & b) const {
        return v > b.v;
    }
};
priority_queue<edge, vector<edge>, greater<edge>> q;
 
int getf(int x)
{
    return f[x] == x ? x : f[x] = getf(f[x]);
}
 
ll getcost(int  x,int y){
    return (spend[x] + spend[y]) * (abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y));
}
 
 
vector<int> bui1;
vector<edge> con1;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = node(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        scanf("%lld",&x);
        q.push(edge(0, i, x));
        ++cnt;
    }
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld", spend + i);
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = i + 1; j <= n;j++)
        {
            q.push(edge(i, j, getcost(i, j)));
            ++cnt;
        }
    }
    ll ans = 0;
    while (cnt--)
    {
        edge tmp = q.top();
        q.pop();
        int x = tmp.x;
        int y = tmp.y;
        ll v = tmp.v;
        int fx = getf(x);
        int fy = getf(y);
        if (fx!=fy)
        {
            if (!x){
                bui1.push_back(y);
            }else if (!y){
                bui1.push_back(x);
            }else{
                con1.push_back(edge(x, y, 0));
            }
 
            f[fx] = fy;
            ans += v;
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", bui1.size());
    for (int x: bui1)
    {
        printf("%d ", x);
    }
    printf("\n%d\n", con1.size());
    for (edge tmp: con1){
        printf("%d %d\n", tmp.x, tmp.y);
    }
    puts("");
    return 0;
}
