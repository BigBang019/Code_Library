#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = -1e9 - 7;
 
char s[N];
char t[N];
int viss[26];
int vist[26];
vector<pair<int, int>> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    int time;
    cin >> time;
    while (time--)
    {
        ans.clear();
        memset(viss, 0, sizeof(viss));
        memset(vist, 0, sizeof(vist));
        int n;
        cin >> n;
        cin >> s >> t;
        for (int i = 0; i < n;++i)
        {
            viss[s[i] - 'a']++;
            vist[t[i] - 'a']++;
        }
        bool ok = 1;
        for (int i = 0; i < 26; ++i)
        {
            if ((viss[i]+vist[i])%2){
                ok = 0;
                break;
            }
        }
        if (!ok){
            puts("No");
            continue;
            ;
        }
        for (int i = 0; i < n;i++)
        {
            if (s[i]==t[i])
                continue;
            //not
            int apos = -1;
            for (int j = i + 1; j < n;++j)
            {
                if (s[i]==s[j]){
                    apos = j;
                    break;
                }
            }
            if (~apos){//!=-1
                swap(t[i], s[apos]);
                ans.push_back(make_pair(apos + 1, i + 1));
                continue;
            }
            //==-1
            for (int j = i + 1; j < n;++j)
            {
                if (t[j]==s[i]){
                    apos = j;
                    break;
                }
            }
            swap(s[i + 1], t[apos]);
            swap(t[i], s[i + 1]);
            ans.push_back(make_pair(i + 2, apos + 1));
            ans.push_back(make_pair(i + 2, i + 1));
        }
        puts("Yes");
        printf("%d\n", ans.size());
        for (auto x: ans){
            printf("%d %d\n", x.first, x.second);
        }
    }
    return 0;
}
