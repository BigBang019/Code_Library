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
    ll n, m, k;
    cin >> n >> m >> k;
    ll dis = n + m - 2;
    ll blank = n * m - dis - 1;
    if (k>blank)
        cout << -1 << endl;
    else
        cout << dis << endl;
    return 0;
}
