#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef unsigned long long ull;
    
    typedef long long ll;

    typedef vector<int> vi;
    typedef vector<vector<int>> vii;
    

    

    vector<bool> vis;

    const int LOW = -0x7f7f7f7f;

    vector<TreeNode*> dfs(int x, int low, int up) {
        vector<TreeNode *> ans;
        vector<TreeNode *> l = vector<TreeNode *>();
        vector<TreeNode *> r = vector<TreeNode *>();
        // left
        for (int i = low; i <= x - 1; ++i)
        {
            if (vis[i]) {
                vis[i] = 0;
                vector<TreeNode *> tmp = dfs(i, low, x - 1);
                for (auto info: tmp) {
                    l.pb(info);
                }
                vis[i] = 1;
            }
        }
        if (l.size()==0)
            l.pb(nullptr);
        // right
        for (int i = x + 1; i <= up; ++i)
        {
            if (vis[i]) {
                vis[i] = 0;
                vector<TreeNode *> tmp = dfs(i, x + 1, up);
                for (auto info: tmp) {
                    r.pb(info);
                }
                vis[i] = 1;
            }
        }
        if (r.size()==0)
            r.pb(nullptr);
        ans = vector<TreeNode *>();
        for (int i = 0; i < l.size(); ++i)
        {
            for (int j = 0; j < r.size(); ++j)
            {
                ans.pb(new TreeNode(x, l[i], r[j]));
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vis = vector<bool>(n + 1, 1);
        vector<TreeNode *> tr = vector<TreeNode *>();
        for (int i = 1; i <= n; ++i)
        {
            vis[i] = 0;
            vector<TreeNode *> tmp = dfs(i, 1, n);
            // cout << i << " " << tmp.size() << endl;
            for (auto info: tmp) {
                tr.pb(info);
            }
            vis[i] = 1;
        }
        return tr;
    }
};

int main () {
    Solution solu = Solution();
    vector<int> a = {1, 2, 4, 7, 9};
    vector<int> b = {1, 0, 0, 1, 1};
    cout << solu.generateTrees(8).size() << endl;
    return 0;
}