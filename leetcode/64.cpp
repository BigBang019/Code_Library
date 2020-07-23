#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

class Solution {
public:
    typedef unsigned long long ull;
    
    typedef long long ll;

    typedef vector<int> vi;
    typedef vector<vector<int>> vii;
    
    vector<bool> vis;

    const int LOW = -0x7f7f7f7f;
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vii f = vii(n, vi(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                f[i][j] = i || j ? -LOW : grid[0][0];
                if (i) {
                    f[i][j] = grid[i][j] + f[i - 1][j];
                }
                if (j) {
                    f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
                // cout << f[i][j] << " ";
            }
            // cout << endl;
        }
        return f[n - 1][m - 1];
    }
};

int main () {
    Solution solu = Solution();
    Solution::vii a = {
        {1, 3, 1},
        { 1, 5, 1 },
        { 4, 2, 1 }};
    vector<int> b = {1, 0, 0, 1, 1};
    cout << solu.minPathSum(a) << endl;
    return 0;
}