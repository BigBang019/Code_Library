#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef unsigned long long ull;
    
    typedef long long ll;

    typedef vector<int> vi;
    typedef vector<vector<int>> vii;

    const int LOW = -0x7f7f7f7f;
    // action 0/1/2: buy/donothing/sell
    // status 0/1: hold/nothing
    vector<vii> f;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0 || n==1)
            return 0;
        f = vector<vii>(n, vii(3, vi(2, LOW)));

        f[0][0][0] = -prices[0];
        f[0][1][1] = 0;

        f[1][0][0] = -prices[1];
        f[1][1][0] = -prices[0];
        f[1][1][1] = 0;
        f[1][2][1] = prices[1] - prices[0];

        for (int i = 2; i < n; ++i)
        {
            f[i][0][0] = max(f[i - 2][1][1], f[i - 2][2][1]) - prices[i];
            f[i][1][0] = max(f[i - 1][0][0], f[i - 1][1][0]);
            f[i][1][1] = max(f[i - 1][1][1], f[i - 1][2][1]);
            f[i][2][1] = max(f[i - 1][1][0], f[i - 1][0][0]) + prices[i];
            // cout << i << endl;
            // cout << f[i][0][0] << " " << f[i][1][0] << " " << f[i][1][1] << " " << f[i][2][1] << endl;
        }
        int ans = max(f[n - 1][0][0], f[n - 1][1][0]);
        ans = max(f[n - 1][1][1], ans);
        ans = max(f[n - 1][2][1], ans);
        return ans;
    }
};

int main () {
    Solution solu = Solution();
    vector<int> M = { 1 };
    cout << solu.maxProfit(M) << endl;
    return 0;
}