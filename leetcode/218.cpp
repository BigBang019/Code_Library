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

    map<int, int> height;

    struct Line{
        int x, h;
        bool f;
        bool operator < (const Line & b) const {
            return x < b.x;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Line> line = vector<Line>();
        vii ans = vii();
        for (auto it: buildings) {
            line.pb({it[0], it[2], 1});
            line.pb({it[1], it[2], 0});
        }
        sort(line.begin(), line.end());
        int n = line.size();
        int last = -1;
        for (int i = 0; i < n;)
        {
            Line l;
            do{
                l = line[i];
                if (l.f) {
                    ++height[l.h];
                } else if (--height[l.h] == 0){
                    auto it = height.find(l.h);
                    height.erase(it);
                }
                ++i;
            } while (i < n && line[i].x == l.x);
            int _m = 0;
            if (height.size()) {
                _m = (--height.end())->first;
            }
            if (last != _m) {
                ans.pb({l.x, _m});
            }
            last = _m;
        }
        return ans;
    }
};

int main () {
    Solution solu = Solution();
    Solution::vii a = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
    // Solution::vii a = {{0,2,3}, {2,5,3}};
    vector<int> b = {1,3,4,5};
    Solution::vii ans = solu.getSkyline(a);
    for (auto item : ans) {
        for (auto ele: item) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}