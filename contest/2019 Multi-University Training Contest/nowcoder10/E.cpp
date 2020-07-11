#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;

int n, k;
struct NODE{
    int x, y;
    ll v;
    NODE(){}
    NODE(int x, int y, ll v) : x(x), y(y), v(v){}
    bool operator<(const NODE &b) const{
        return v < b.v;
    }
};
vector<NODE> vc;

ll dfs(int x,int y,int k){
    if (!k){
        return 0;
    }
    int mid = (1 << (k - 1));
    if (x<=mid){
        if (y<=mid){
            return dfs(y, x, k - 1);
        }else{
            y -= mid;
            return dfs(mid - y + 1, mid - x + 1, k - 1) + 3ll * (1 << (2 * k - 2));
        }
    }
    else
    {
        x -= mid;
        if (y <= mid){
            return dfs(x, y, k - 1) + (1 << (2 * k - 2));
        }
        else
        {
            y -= mid;
            return dfs(x, y, k - 1) + 2ll * (1 << (2 * k - 2));
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vc.push_back(NODE(x, y, dfs(x, y, k)));
    }
    sort(vc.begin(), vc.end());
    for (auto it: vc){
        printf("%d %d\n", it.x, it.y);
    }
    return 0;
}
