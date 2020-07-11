#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<queue>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
const int MOD = 100000;
 
int main(){
    ios_base::sync_with_stdio(false);
    int a, b, n, S;
    int t;
    cin >> t;
    while (t--){
        cin >> a >> b >> n >> S;
        int x = min(S / n, a);
        if (b>=S-x*n){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}
