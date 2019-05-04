#include <bits/stdc++.h>
using namespace std;
// #define MOD 1000000007
#define ll long long
#define N 100005
const ll MOD = 1e9 + 7;
vector<char> s[N];
ll pre[N][30],su[N][30];
ll f[N][30],dp[N][30];
int n;
inline void getString(int x){
    char c;
    while ((c=getchar())=='\n' || c=='\r' || c==' ');
    s[x].push_back(c);
    while ((c=getchar())!='\n' && c!='\r' && c!=' ') s[x].push_back(c);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        getString(i);
    }
    for (int i=1;i<=n;i++) {
        ll sum = 1;
        char ch = s[i][0];
        for (int j = 1; j < s[i].size(); j++) {
            if (ch != s[i][j]) break;
            sum++;
        }
        pre[i][ch - 'a'] = sum;
        sum=1;
        ch= s[i][s[i].size()-1];
        for (int j=s[i].size()-2;j>=0;j--){
            if (s[i][j]!=ch) break;
            sum++;
        }
        su[i][ch-'a']=sum;
    }
    for (int i=1;i<=n;i++){
        ll sum=1;
        char ch=s[i][0];
        for (int j=1;j<s[i].size();j++) {
            if (s[i][j] != ch) {
                f[i][ch - 'a'] = max(f[i][ch - 'a'], sum);
                sum = 1;
                ch = s[i][j];
            }else sum++;
        }
        f[i][ch-'a']=max(f[i][ch-'a'],sum);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++){
            if (f[i][j]==s[i].size()){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+(dp[i-1][j]+1)*f[i][j]);
            }else {
                dp[i][j]=(dp[i-1][j]?max(pre[i][j]+su[i][j]+1,f[i][j]):f[i][j]);
            }
        }
    }
    ll ans=0;
    for (int j=0;j<26;j++){
        ans=max(ans,dp[n][j]);
    }
    printf("%I64d",ans);
    return 0;
}
