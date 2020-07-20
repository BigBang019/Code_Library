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
    
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vii f = vii(n + 1, vi(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = 0;
                }
                ans = max(ans, f[i][j]);
                // cout << i << " " << j << " " << f[i][j] << endl;
            }
        }
        return ans;
    }
};

int main () {
    Solution solu = Solution();
    vector<int> a = {1, 0, 0, 0, 1};
    vector<int> b = {1, 0, 0, 1, 1};
    cout << solu.findLength(a, b) << endl;
    return 0;
}