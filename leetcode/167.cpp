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
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0;
        int q = numbers.size() - 1;
        while (numbers[p] + numbers[q]!=target) {
            if (numbers[p] + numbers[q] > target) {
                --q;
            } else if (numbers[p] + numbers[q] < target) {
                ++p;
            }
        }
        return {p + 1, q + 1};
    }
};

int main () {
    Solution solu = Solution();
    vector<int> a = {1, 2, 4, 7, 9};
    vector<int> b = {1, 0, 0, 1, 1};
    solu.twoSum(a, 9);
    return 0;
}  