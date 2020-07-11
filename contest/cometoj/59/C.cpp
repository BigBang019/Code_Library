// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
const int N = 2e6 + 5;
const int B = 31;
int a[N];
bool vis[N];
int main(){
    ll MOD;
    int n;
    cin >> n >> MOD;
    if (n==1 || n==0){
        cout << 1 % MOD << endl;
    }else if (n==2){
        cout << 2 % MOD << endl;
    }else if (n==3){
        ll ans = 1;
        for (int i = 1; i <= 720;i++)
        {
            ans = ans * i % MOD;
        }
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
