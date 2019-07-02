#include<bits/stdc++.h>
namespace TANJAN{
    using namespace std;
    typedef long long ll;
    const int N = 5e4 + 5;
    const int M = 1e5 + 5;

    int n, m;

    int cnt, he[N], ne[M], v[M];
    ll w[M];
    void add(int x, int y, ll z)
    {
        cnt++;
        ne[cnt] = he[x];
        he[x] = cnt;
        v[cnt] = y;
        w[cnt] = z;
    }
    stack<int> st;
    int low[N], dfn[N], inst[N], icp[N], icpn[N];
    int ind,cpn;
    void tanjan(int x){
        st.push(x);
        inst[x] = 1;
        dfn[x] = low[x] = ++ind;
        for (int i = he[x]; i;i=ne[i])
        {
            int p = v[i];
            if (!inst[p]){
                tanjan(p);
                low[x] = min(low[x], low[p]);
            }else if (inst[p]==1){
                low[x] = min(low[x], dfn[p]);
            }
        }
        if (low[x]==dfn[x]){
            cpn++;
            while (!st.empty()){
                int j = st.top();
                icp[j] = cpn;
                icpn[cpn]++;
                st.pop();
                inst[j] = 2;
                if (j==x)
                    break;
            }
        }
    }
    void init(){
        cpn = ind = cnt = 0;
        memset(he, 0, sizeof(he));
        memset(inst, 0, sizeof(inst));
        memset(icpn, 0, sizeof(icpn));
    }
}
using namespace TANJAN;
struct EDGE{
    int x, y, v;
    EDGE(int x, int y, int v) : x(x), y(y), v(v){}
    EDGE(){}
    bool operator < (const EDGE & b) const {
        return v < b.v;
    }
    bool operator > (const EDGE & b) const {
        return b < (*this);
    }
};
ll indeg[N];
int main(){
    while (~scanf("%d%d",&n,&m)){
        init();
        memset(indeg, -1, sizeof(indeg));
        for (int i = 1; i <= m;i++)
        {
            int x, y;
            ll v;
            scanf("%d%d%lld", &x, &y, &v);
            x++;
            y++;
            add(x, y, v);
        }
        for (int i = 1; i <= n;i++)
        {
            if (!inst[i])
                tanjan(i);
        }
        for (int j = 1; j <= n;j++)
        {
            int ij = icp[j];
            for (int i = he[j]; i;i=ne[i])
            {
                int p = v[i];
                int ip = icp[p];
                if (ip==ij)
                    continue;
                indeg[ip] = (~indeg[ip]) ? min(indeg[ip], w[i]) : w[i];
            }
        }
        ll ans = 0;
        for (int i = 1; i <= cpn;i++)
        {
            if (i==icp[1])
                continue;
            ans += indeg[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
