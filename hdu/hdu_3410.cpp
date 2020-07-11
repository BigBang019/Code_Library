#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
stack<pair<int, int> > st;
pair<int, int> a[N];
pair<int, int> ans[N];
int ma[N * 4];
int l[N], r[N];
map<int, int> mapp;
int n;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a > b;
}
void up(int x){
    ma[x] = max(ma[2 * x], ma[2 * x + 1]);
}
void build(int x,int l,int r){
    if (l==r){
        ma[x] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    up(x);
}
int queryM(int x,int l,int r,int ql,int qr){
    if (ql>qr)
        return 0;
    if (ql<=l && qr>=r){
        return ma[x];
    }
    int mid = l + r >> 1;
    if (ql>mid)
        return queryM(2*x+1, mid+1, r, ql, qr);
    else if (qr<=mid)
        return queryM(2 * x, l, mid, ql, qr);
    else
        return max(queryM(2 * x, l, mid, ql, mid), queryM(2 * x + 1, mid + 1, r, mid+1, qr));
}

void update(int x,int l,int r,int p,int v){
    if (l==r){
        ma[x] = v;
        return;
    }
    int mid = l + r >> 1;
    if (p<=mid)
        update(2 * x, l, mid, p, v);
    else
        update(2 * x + 1, mid + 1, r, p, v);
    up(x);
}
void work(int cas){
    scanf("%d", &n);
    while (!st.empty())
        st.pop();
    build(1, 1, n);
    mapp.clear();
    for (int i = 1; i <= n;i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = make_pair(x, i);
        mapp[x] = i;
        while (!st.empty() && x>st.top().first){
            pair<int, int> j = st.top();
            st.pop();
            r[j.second] = i - 1;
        }
        st.push(make_pair(x, i));
    }
    while (!st.empty()){
        pair<int, int> j = st.top();
        st.pop();
        r[j.second] = n;
    }
    for (int i = n; i >= 1;i--)
    {
        int x = a[i].first;
        while (!st.empty() && x>st.top().first){
            pair<int, int> j = st.top();
            st.pop();
            l[j.second] = i+1;
        }
        st.push(make_pair(x, i));
    }
    while (!st.empty()){
        pair<int, int> j = st.top();
        st.pop();
        l[j.second] = 1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++)
    {
        int h = a[i].first;
        int pos = a[i].second;
        int maxx = queryM(1, 1, n, l[pos], pos - 1);
        ans[pos].first = (maxx == 0) ? 0 : mapp[maxx];
        maxx = queryM(1, 1, n, pos + 1, r[pos]);
        ans[pos].second = (maxx == 0) ? 0 : mapp[maxx];
        update(1, 1, n, pos, h);
    }
    printf("Case %d:\n", cas);
    for (int i = 1; i <= n;i++)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
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
