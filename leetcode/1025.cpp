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

    bool divisorGame(int N) {
        vector<bool> f = vector<bool>(N + 1, 0);
        f[1] = 0;
        for (int i = 2; i <= N; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j == 0 && f[i-j]==0) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[N];
    }
};

int main () {
    Solution solu = Solution();
    
    auto ans = solu.divisorGame(4);
    cout << ans << endl;
    return 0;
}