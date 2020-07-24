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

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main () {
    Solution solu = Solution();
    Solution::vi a = {1,1};
    auto ans = solu.firstMissingPositive(a);
    cout << ans << endl;
    return 0;
}