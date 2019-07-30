// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second;
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1e5 + 5;
ll h, l;
int main(){
    cin >> h >> l;
    printf("%.9f", (l * l - h * h) * 1.0 / 2 / h);
    return 0;
}
