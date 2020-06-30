#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
pair<int, int> e[N];
pair<pair<int, int>, int> q[N];
int ans[N];
int n, qu, c[N];
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
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}
void work(){
    memset(c, 0, sizeof(c));
    scanf("%d%d", &n, &qu);
    for (int i = 1; i < n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x>y)
            swap(x, y);
        e[i] = make_pair(x,y);//<l,r>
    }
    for (int i = 1; i <= qu;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x>y)
            swap(x, y);
        q[i].second = i;
        q[i].first = make_pair(x, y);
    }
    sort(q + 1, q + 1 + qu);
    sort(e + 1, e + n);
    for (int i = 1; i < n;i++)
    {
        add(e[i].second, 1);
    }
    int j = 1;
    for (int i = 1; i <= qu;i++)
    {
        while(j<n && e[j].first<q[i].first.first){
            add(e[j++].second, -1);
        }
        int tmp = query(q[i].first.second);
        ans[q[i].second] = q[i].first.second - q[i].first.first + 1 - tmp;
    }
    for (int i = 1; i <= qu;i++)
    {
        printf("%d\n", ans[i]);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        work();
    }
    return 0;
}
