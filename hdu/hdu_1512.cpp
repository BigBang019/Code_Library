#include <bits/stdc++.h>
namespace LHEAP{
    using namespace std;
    const int N = 1e6 + 5;
    struct NODE{
        int v, lc, rc, dis, pa;
        NODE(){}
        NODE(int v, int lc, int rc, int dis, int pa) : v(v), lc(lc), rc(rc), dis(dis), pa(pa){};
    } t[N];
    int n;
    int getf(int x){
        return (x == t[x].pa ? x : t[x].pa = getf(t[x].pa));
    }
    void init(){
        for (int i = 1; i <= n;i++)
        {
            t[i] = NODE(0, 0, 0, 0, i);
        }
    }
    int unite(int x,int y){
        if (!x)
            return y;
        if (!y)
            return x;
        if (t[x].v<t[y].v)
            swap(x, y);
        t[x].rc = unite(t[x].rc, y);
        t[t[x].rc].pa = x;
        if (t[t[x].lc].dis<t[t[x].rc].dis)
            swap(t[x].lc, t[x].rc);
        if (t[x].rc==0)
            t[x].dis = 0;
        else
            t[x].dis = t[t[x].rc].dis + 1;
        return x;
    }
    int pop(int x){
        int l = t[x].lc, r = t[x].rc;
        t[x] = NODE(t[x].v, 0, 0, 0, x);
        t[l].pa = l;
        t[r].pa = r;
        return unite(l, r);
    }
}
using namespace LHEAP;
void make(int x,int y){
    x = getf(x);
    y = getf(y);
    t[x].v /= 2;
    t[y].v /= 2;
    int xx = pop(x), yy = pop(y);
    xx = unite(xx, x);
    yy = unite(yy, y);
    xx = unite(xx, yy);
    printf("%d\n", t[xx].v);
}
int main(){
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &t[i].v);
        }
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (getf(x)==getf(y)){
                printf("-1\n");
            }else{
                make(x, y);
            }
        }
    }
    return 0;
}
