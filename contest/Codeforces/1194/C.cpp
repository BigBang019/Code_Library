#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
char s[N], t[N], p[N];
int vis[30];
bool work(){
    memset(vis, 0, sizeof(vis));
    scanf(" %s %s %s", s, t, p);
    for (int i = 0; i < strlen(p);i++)
    {
        int pos = p[i] - 'a';
        vis[pos]++;
    }
    int j = 0;
    int k = 0;
    while (k<strlen(t)){
        if (s[j]==t[k]){
            j++;
            k++;
        }else{
            int pos = t[k] - 'a';
            if (vis[pos]){
                vis[pos]--;
                k++;
            }else
                return 0;
        }
    }
    if (k==strlen(t) && j==strlen(s))
        return 1;
    else
        return 0;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        printf("%s\n", work() ? "YES" : "NO");
    }
    return 0;
}
