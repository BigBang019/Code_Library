#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
 
int last[N];
int a[N];
struct NODE{
    int p, s;
    NODE(int p,int s):p(p),s(s){}
    NODE(){}
    bool operator < (const NODE & b) const {
        return p < b.p;
    }
    bool operator <= (const NODE & b) const {
        return p <= b.p;
    }
};
vector<NODE> b;
int n, m;
vector<NODE> st;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        st.clear();
        b.clear();
        cin >> n;
        int mxa = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            mxa = max(a[i], mxa);
        }
        cin >> m;
        bool ok = 0;
        for (int i = 1; i <= m; ++i)
        {
            NODE tmp;
            cin >> tmp.p >> tmp.s;
            b.push_back(tmp);
            if (tmp.p>=mxa)
                ok = 1;
        }
        sort(b.begin(), b.end(), [](NODE a, NODE b) {
            return a.p < b.p;
        });
        for (int i = 0; i < b.size(); ++i)
        {
            while (st.size() && st.back().s<=b[i].s)
                st.pop_back();
            st.push_back(b[i]);
        }
        int last = 0;
        int ans = 1;
        int curmx = 0;
        for (int i = 1; i <= n; ++i)
        {
            curmx = max(curmx, a[i]);
            int pos = lower_bound(st.begin(), st.end(), NODE(curmx, i - last)) - st.begin();
            if (pos >= st.size() || st[pos].s < i - last)
            {
                ++ans;
                last = i - 1;
                curmx = a[i];
            }
        }
        printf("%d\n", ok ? ans : -1);
    }
 
    return 0;
}

