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
    
    int searchInsert(vector<int>& nums, int target) {
        int d = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return d;
    }
};

int main () {
    Solution solu = Solution();
    vector<int> triangle = {1, 3, 5, 6};
    cout << solu.searchInsert(triangle, 7) << endl;
    return 0;
}  