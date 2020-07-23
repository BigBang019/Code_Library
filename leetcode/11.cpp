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
    
    int minArray(vector<int>& numbers) {
        for (int p = 0; p < numbers.size() - 1; ++p)
        {
            if (numbers[p + 1] < numbers[p]){
                return numbers[p + 1];
            }
        }
        return min(numbers[0], numbers[numbers.size() - 1]);
    }
};

int main () {
    Solution solu = Solution();
    Solution::vii a = {
        {1, 3, 1},
        { 1, 5, 1 },
        { 4, 2, 1 }};
    vector<int> b = {1,3,4,5};
    cout << solu.minArray(b) << endl;
    return 0;
}