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
    

    const int LOW = -0x7f7f7f7f;
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vii f = vii(n, vi(m, -LOW));
        f[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (i == n - 1 && j == m - 1){
                    continue;
                }
                if (i<n-1) {
                    f[i][j] = min(f[i][j], max(f[i + 1][j] - dungeon[i + 1][j], 1));
                }
                if (j<m-1) {
                    f[i][j] = min(f[i][j], max(f[i][j + 1] - dungeon[i][j + 1], 1));
                }
            }
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < m; ++j)
        //     {
        //         cout << f[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return max(f[0][0] - dungeon[0][0], 1);
    }
};

int main () {
    Solution solu = Solution();
    vector<vector<int>> triangle = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};
    cout << solu.calculateMinimumHP(triangle) << endl;
    return 0;
}