#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef unsigned long long ull;

    typedef long long ll;

    vector<int> to;

    vector<int> he;
    vector<int> v;
    vector<int> w;
    vector<int> ne;

    int n, m;

    void add(int x, int y ,int z) {
        v.push_back(y);
        w.push_back(z);
        ne.push_back(he[x]);
        he[x] = v.size() - 1;
    }

    int dijkstra() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<bool> vis = vector<bool>(n * m + 1, false);
        vector<int> dis = vector<int>(n * m + 1, 0x7f7f7f7f);
        dis[1] = 0;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            auto j = q.top();
            // cout << "start " << j.second << " " << dis[j.second] << endl;
            q.pop();
            int t = j.second;
            if (vis[t])
                continue;
            vis[t] = 1;
            for (int i = he[t]; ~i; i = ne[i])
            {
                int p = v[i];
                int z = w[i];
                // cout << t << " " << j.first << " " << p << " " << z << " ";
                if (!vis[p] && dis[p]> j.first + z) {
                    dis[p] = j.first + z;
                    // cout << "dis: " << dis[p];
                    q.push(make_pair(dis[p], p));
                }
                // cout << endl;
            }
        }
        return dis[n * m];
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        he = vector<int>(n * m + 1, -1);
        to = vector<int>(n * m + 1, 0);

        int i = n - 1, j = 0, dir = 1, now = 1;
        while (i >= 0) {
            while (j < m && j >= 0) {
                if (board[i][j] != -1){
                    to[now] = board[i][j];
                } else {
                    to[now] = now;
                }
                ++now;
                j += dir;
            }
            j -= dir;
            dir *= -1;
            --i;
        }
        for (int i = 1; i <= n * m; ++i)
        {
            // cout << i << " " << to[i] << endl;
            for (int j = 1; j <= 6; j++)
            {
                if (i + j > n * m)
                    break;
                add(i, to[i + j], 1);
                // cout << i << " " << to[i + j] << endl;
            }
        }
        int dij = dijkstra();
        return dij == 0x7f7f7f7f ? -1 : dij;
    }
};

int main () {
    Solution solu = Solution();
    vector<vector<int>> M = {
        {-1, -1, 30, 14, 15, -1},
        {23, 9, -1, -1, -1, 9},
        {12, 5, 7, 24, -1, 30},
        {10, -1, -1, -1, 25, 17},
        {32, -1, 28, -1, -1, 32},
        {-1, -1, 23, -1, 13, 19}};
    cout << solu.snakesAndLadders(M) << endl;
    return 0;
}