#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
 
int c[N];
int n;
int lb(int x){
    return x & (-x);
}
void update(int x,int v){
    for (int i = x; i <= 26; i += lb(i))
    {
        c[i] += v;
    }
}
int query(int x){
    int sum = 0;
    for (int i = x; i > 0; i -= lb(i))
    {
        sum += c[i];
    }
    return sum;
}
char s[N];
char t[N];
int vis1[27];
int vis2[27];
int main()
{
    ios_base::sync_with_stdio(false);
    int times;
    cin >> times;
    while (times--){
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
 
        cin >> n;
        cin >> s >> t;
        int tot1 = 0;
        bool ok = 1;
        bool dup = 0;
        int tot2 = 0;
        for (int i = 0; i < n;++i)
        {
            vis1[s[i] - 'a']++;
        }
        for (int i = 0; i < n;++i)
        {
            vis2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26;++i)
        {
            if (vis1[i]!=vis2[i]){
                ok = 0;
                break;
            }
            if (vis1[i]>1){
                dup = 1;
            }
        }
        if (!ok){
            puts("NO");
            continue;
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
        {
            tot1 += i - query(s[i] - 'a' + 1);
            update(s[i] - 'a' + 1, 1);
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
        {
            tot2 += i - query(t[i] - 'a' + 1);
            update(t[i] - 'a' + 1, 1);
        }
        if (((tot1%2)==(tot2%2)) || dup){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}
