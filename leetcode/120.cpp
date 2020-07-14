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
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f[2] = {vector<int>(n, -LOW), vector<int>(n, -LOW)};
        f[0][0] = triangle[0][0];
        int id = 0;
        for (int i = 1; i < n; ++i)
        {
            id ^= 1;
            for (int j = 0; j <= i; ++j)
            {
                f[id][j] = f[id ^ 1][j] + triangle[i][j];
                if (j) {
                    f[id][j] = min(f[id][j], f[id ^ 1][j - 1] + triangle[i][j]);
                }
                // cout << f[id][j] << " ";
            }
            // cout << endl;
        }
        int ans = -LOW;
        for (int i = 0; i < n; ++i)
        {
            ans = min(ans, f[id][i]);
        }
        return ans;
    }
};

int main () {
    Solution solu = Solution();
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << solu.minimumTotal(triangle) << endl;
    return 0;
}