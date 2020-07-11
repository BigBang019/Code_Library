#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int c[N], ans[N];
pair<int, int> info[N];
int lowbit(int x){
    return x & (-x);
}
void add(int x,int v){
    for (int i = x; i <= n;i+=lowbit(i))
    {
        c[i] += v;
    }
}
int query(int x){
    int sum = 0;
    for (int i = x; i > 0;i-=lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}
bool vis[N];
void work(int cas){
    memset(vis, 0, sizeof(vis));
    memset(c, 0, sizeof(c));
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        int h, k;
        scanf("%d%d", &h, &k);
        info[i] = make_pair(h, k);
        add(i, 1);
    }
    sort(info + 1, info + 1 + n);
    for (int i = 1; i <= n;i++)
    {
        int k = info[i].second;
        int h = info[i].first;
        if (k>n-i){
            printf("Case #%d: impossible\n", cas);
            return;
        }
        int p = min(k , n - i - k);  //前面需要p个空格
        int l = 1, r = n, tt = -1;
        while (l<=r){
            int mid = l + r >> 1;           //放在mid?
            int tmp = query(mid - 1);
            if (tmp>p)
                r = mid - 1;
            else if (tmp<p || tmp==p && vis[mid])
                l = mid + 1;
            else {
                tt = mid;
                break;
            }
        }
        ans[tt] = h;
        vis[tt] = 1;
        add(tt, -1);
    }
    printf("Case #%d:", cas);
    for (int i = 1; i <= n;i++)
    {
        printf(" %d",ans[i]);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t;i++)
    {
        work(i);
    }
    return 0;
}
