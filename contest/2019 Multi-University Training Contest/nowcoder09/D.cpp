#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

struct NODE{
    ll now;
    string state;
    NODE(ll now, string state) : now(now), state(state){}
    NODE(){}
    bool operator < (const NODE & b) const {
        return now < b.now;
    }
    bool operator > (const NODE & b) const {
        return now > b.now;
    }
    bool operator <= (const NODE & b) const {
        return now <= b.now;
    }
    bool operator >= (const NODE & b) const {
        return now >= b.now;
    }
};
vector<NODE> b;

int n;
ll a[N], s;

ll now = 0;
string state = "";

void dfs1(int x){
    if (x > n / 2)
    {
        b.push_back(NODE(now, state));
        return;
    }
    state[x - 1] = '0';
    dfs1(x + 1);
    state[x - 1] = '1';
    now += a[x];
    dfs1(x + 1);
    now -= a[x];
}

bool ok = 0;
string final_state = "";

void dfs2(int x){
    if (ok)
        return;
    if (x > n)
    {
        int pos = lower_bound(b.begin(), b.end(), NODE(s - now, "")) - b.begin();
        if (pos < b.size() && b[pos].now + now == s)
        {
            ok = 1;
            final_state = b[pos].state + state;
        }
        return;
    }
    state[x - n / 2 - 1] = '0';
    dfs2(x + 1);
    state[x - n / 2 - 1] = '1';
    now += a[x];
    dfs2(x + 1);
    now -= a[x];
}

int main(){
    scanf("%d%lld", &n, &s);
    b.push_back(NODE(0, ""));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
    }
    state = "";
    for (int i = 1; i <= n / 2;++i)
    {
        state += "0";
    }
    dfs1(1);
    sort(b.begin(), b.end());
    now = 0;
    state = "";
    for (int i = 1 + n / 2; i <= n; ++i)
    {
        state += "0";
    }
    dfs2(n / 2 + 1);
    printf("%s\n", final_state.c_str());
    return 0;
}
