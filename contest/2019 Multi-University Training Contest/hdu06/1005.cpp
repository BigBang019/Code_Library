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
const int N = 2e3 + 5;
const int R = 1e9;

vector<int> X, Y;

struct NODE{
    int x, y;
    ll z;
    NODE(){}
    NODE(int x, int y, ll z) : x(x), y(y), z(z){};
} a[N];

ll mx[N << 2], ls[N << 2], rs[N << 2], sum[N << 2];

void init(){
    X.clear();
    Y.clear();
    memset(sum, 0, sizeof(sum));
    memset(mx, 0, sizeof(mx));
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
}
void Init_Hash(){
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
}
int has(int x){
    return lower_bound(Y.begin(), Y.end(), x) - Y.begin() + 1;
}

void up(int x,int l,int r){
    mx[x] = max(mx[2 * x], mx[2 * x + 1]);
    mx[x] = max(mx[x], rs[2 * x] + ls[2 * x + 1]);
    sum[x] = sum[2 * x] + sum[2 * x + 1];
    ls[x] = max(sum[2 * x] + ls[2 * x + 1], ls[2 * x]);
    rs[x] = max(sum[2 * x + 1] + rs[2 * x], rs[2 * x + 1]);
}

void update(int x,int l,int r,int p,ll v){
    if (l==r){
        mx[x] += v;
        sum[x] += v;
        ls[x] += v;
        rs[x] += v;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid) update(2 * x, l, mid, p, v);
    else update(2 * x + 1, mid + 1, r, p, v);
    up(x, l, r);
}

int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        int n;
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
        {
            int x, y;
            ll z;
            scanf("%d%d%lld", &x, &y, &z);
            a[i] = NODE(x, y, z);
            X.pb(x);
            Y.pb(y);
        }
        Init_Hash();
        int sx = X.size(), sy = Y.size();
        for (int i = 1; i <= n;i++)
        {
            a[i].y = has(a[i].y);
        }
        sort(a + 1, a + 1 + n, [](NODE a, NODE b) {
            return a.x < b.x;
        });
        vector<NODE> cur;
        ll ans = 0;
        int now = 0;
        for (int i = 0; i < sx;i++)
        {
            while (now < n && a[now + 1].x <= X[i]){
                now++;
                cur.pb(a[now]);
                update(1, 1, sy, a[now].y, a[now].z);
            }
            ans = max(mx[1], ans);
            int dec = -1;
            for (int j = 0; j < i;j++)
            {
                while (dec<(int)cur.size() && cur[dec+1].x<=X[j]){
                    dec++;
                    update(1, 1, sy, cur[dec].y, -cur[dec].z);
                }
                ans = max(mx[1], ans);
            }
            for (int j = 0; j <= dec;j++)
            {
                update(1, 1, sy, cur[j].y, cur[j].z);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
