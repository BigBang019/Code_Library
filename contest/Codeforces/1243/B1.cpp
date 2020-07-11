#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = -1e9 - 7;
 
int a[N];
char s[N];
char t[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    int time;
    cin >> time;
    while (time--)
    {
        int n;
        cin >> n;
        cin >> s >> t;
        int dif = 0;
        char sa, sb, ta, tb;
        sa = sb = ta = tb = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i]!=t[i]){
                dif++;
                if (sa){
                    sb = s[i];
                    tb = t[i];
                }else{
                    sa = s[i];
                    ta = t[i];
                }
            }
        }
        if (dif>2 || dif==1){
            puts("No");
            continue;
        }
        if (sa==sb && tb==ta){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}
