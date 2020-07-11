#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
struct EDGE{
    int a, b;
    ll v;
    bool operator < (const EDGE& c) const {
        return v < c.v;
    }
    bool operator > (const EDGE& c) const {
        return c < (*this);
    }
    EDGE(){}
    EDGE(int a, int b, ll v) : a(a), b(b), v(v){}
};
vector<EDGE> vc;
bool disable[N];
int n, f[N];
void init(){
    for (int i = 1; i <= n;i++)
    {
        f[i] = i;
    }
}
int getf(int x){
    if (x!=f[x]){
        f[x] = getf(f[x]);
    }
    return f[x];
}
void make(int x,int y){
    int xx = getf(x), yy = getf(y);
    if (xx!=yy){
        f[xx] = yy;
    }
}
void work(){
    int m;
    vc.clear();
    memset(disable, 0, sizeof(disable));
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m;i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y,&v);
        vc.push_back(EDGE(x, y, v));
    }
    sort(vc.begin(), vc.end());
    ll ans = 0;
    int now = vc[0].v;
    int he = 0, ta;
    for (int i = 0; i < vc.size();i++)
    {
        if (i<vc.size()-1 && vc[i+1].v!=now){
            ta = i;
            for (int j = he; j <= ta;j++)
            {
                int x = vc[j].a, y = vc[j].b;
                if (getf(x)==getf(y))
                    disable[j] = 1;
            }
            for (int j = he; j <= ta;j++)
            {
                int x = vc[j].a, y = vc[j].b;
                ll v = vc[j].v;
                if (disable[j])
                    continue;
                if (getf(x)==getf(y)) {
                    printf("Not Unique!\n");
                    return;
                }
                make(x, y);
                ans += v;
            }
            he = i + 1;
            now = vc[he].v;
        }
    }
    ta = vc.size() - 1;
    for (int j = he; j <= ta;j++)
    {
        int x = vc[j].a, y = vc[j].b;
        if (getf(x)==getf(y))
            disable[j] = 1;
    }
    for (int j = he; j <= ta;j++)
    {
        int x = vc[j].a, y = vc[j].b;
        ll v = vc[j].v;
        if (disable[j])
            continue;
        if (getf(x)==getf(y)) {
            printf("Not Unique!\n");
            return;
        }
        make(x, y);
        ans += v;
    }
    printf("%lld\n", ans);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        work();
    }
    return 0;
}
