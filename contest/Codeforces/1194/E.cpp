#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int R = 1e4 + 1;
ll c[N];
int lb(int x) { return x & (-x); }
void add(int x,int v){
    for (int i = x; i <= R; i += lb(i))
    {
        c[i] += v;
    }
}
ll query(int x){
    ll sum = 0;
    for (int i = x; i > 0; i -= lb(i))
    {
        sum += c[i];
    }
    return sum;
}
vector<pair<int,pair<int,int> > > hon, ver;
int getnum(){
    bool fl = 0;
    char ch;
    int sum = 0;
    while ((ch=getchar())==' '||ch=='\n'||ch=='\r');
    if (ch=='-')
        fl = 1;
    else
        sum = ch - '0';
    while (isdigit(ch=getchar()))
        sum = sum * 10 + ch - '0';
    return sum * (fl ? -1 : 1);
}
int main(){
    int n;
    ll tmp, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1 += 5001;
        y1 += 5001;
        x2 += 5001;
        y2 += 5001;
        if (x1==x2){//ver
            if (y1>y2)
                swap(y1, y2);
            ver.push_back(make_pair(x1, make_pair(y1, y2)));
        }else{
            if (x1>x2)
                swap(x1, x2);
            hon.push_back(make_pair(x2, make_pair(y1, x1)));
        }
    }
    sort(ver.begin(), ver.end());
    sort(hon.begin(), hon.end());
    for (int i = 0; i < (int)ver.size() - 1; i++)
    {
        vector<pair<int, pair<int, int> > > cur;
        for (int j = 0; j < hon.size();j++)
        {
              if (hon[j].second.second<=ver[i].first){
                add(hon[j].second.first, 1);
                cur.push_back(hon[j]);
            }
        }
        int nxt = 0;
        for (int j = i + 1; j < ver.size(); j++)
        {
            while (nxt < cur.size() && cur[nxt].first<ver[j].first){
                add(cur[nxt].second.first, -1);
                nxt++;
            }
            int lo1 = ver[i].second.first, lo2 = ver[j].second.first;
            int hi1 = ver[i].second.second, hi2 = ver[j].second.second;
            if (lo1>hi2 || lo2>hi1)
                continue;
            int lo = max(lo1, lo2);
            int hi = min(hi1, hi2);
            tmp = query(hi) - query(lo - 1);
            ans += tmp * (tmp - 1) / 2;
        }
        for (int j = nxt; j < cur.size();j++)
        {
            add(cur[j].second.first, -1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
