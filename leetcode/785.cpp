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

    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color = vector<int>(n, -1);
        for (int i = 0; i < n;++i)
        {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int j = q.front();
                    q.pop();
                    for (int p: graph[j]) {
                        if (color[p]==-1) {
                            // -1
                            color[p] = color[j] ^ 1;
                            q.push(p);
                        } else if (color[p] == color[j]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main () {
    Solution solu = Solution();
    vector<vector<int>> triangle = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << solu.isBipartite(triangle) << endl;
    return 0;
}  