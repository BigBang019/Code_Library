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
    
    int numTrees(int n) {
        vector<int> f = vector<int>(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];
    }
};

int main () {
    Solution solu = Solution();
    vector<vector<int>> triangle = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};
    cout << solu.numTrees(0) << endl;
    return 0;
}  