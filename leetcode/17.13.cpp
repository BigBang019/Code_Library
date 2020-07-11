#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef unsigned long long ull;

    typedef long long ll;

    map<ull, int> str_map;

    vector<ull> h;//1-n

    vector<int> f;//1-n

    vector<ull> PO;//0-n-1

    const ull BASE = 107;

    ull query(int l, int r) {
        return (h[r] - h[l - 1] * qp(BASE, r - l + 1));
    }

    ull qp(ull a, int k) {
        ull sum = 1;
        while (k) {
            if (k&1) {
                sum *= a;
            }
            a *= a;
            k >>= 1;
        }
        return sum;
    }

    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length();

        PO.push_back(1);
        for (int i = 1; i < n; ++i)
        {
            PO.push_back(PO.back() * BASE);
        }

        h.push_back(0);
        for (int i = 0; i < n; ++i)
        {
            h.push_back(h.back() * BASE + sentence[i]);
            // cout << h[i + 1] << " ";
        }
        // cout << endl;

        for (string s: dictionary) {
            ull hash = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                hash = hash * BASE + s[i];
            }
            str_map[hash] = s.length();
            // cout << hash << " ";
        }
        // cout << endl;
        vector<int> f = vector<int>(n + 1, 0);
        for (int i = n; ~i; --i)
        {
            f[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                f[i] = min(f[i], f[j] + i - j);
            }
            for (int j = 0; j < i; ++j)
            {
                ull s_hash = query(j + 1, i);
                auto it = str_map.find(s_hash);
                // cout << j + 1 << " " << i << " " << s_hash << " ";
                // if (it != str_map.end()) {
                //     cout << it->first << " " << it->second;
                // }
                
                if (it != str_map.end() && it->second == i - j) {
                    f[i] = min(f[i], f[j]);
                    // cout << " " << f[i];
                }
                // cout << endl;
            }
            // cout << i << " " << f[i] << endl;
        }
        return f[n];
    }
};

int main () {
    Solution solu = Solution();
    // cout << solu.qp(solu.BASE, 3) <<endl;
    // return 0;
    vector<string> a = {"looked","just","like","her","brother"};
    string b = "jesslookedjustliketimherbrother";
    cout << solu.respace(a, b);
    return 0;
}