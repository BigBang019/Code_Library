/*
    0-1 mst的cost为0-联通块的个数-1
    那么我们需要求一共多少个0-联通块
    基本思路：
        step1：用当前块的点去拓展新点，直到不能拓展为止
        step2：当前仍有未处理过的点，新建一个块，重复step1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = -1e9 - 7;

map<pair<int, int>, int> fn;
int n, m;
set<int> st;

void dfs(int x){
    vector<int> vals;
    for (int i: st){
        if (fn.find(make_pair(x,i))==fn.end()){
            vals.push_back(i);
        }
    }
    for (int i: vals){
        st.erase(i);
    }
    for (int i: vals)
    {
        dfs(i);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        fn[{x, y}] = 1;
        fn[{y, x}] = 1;
    }
    for (int i = 1; i <= n;++i)
    {
        st.insert(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (st.size()){
            auto it = st.begin();
            st.erase(*it);
            dfs(*it);
            ++ans;
        }else{
            break;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}
