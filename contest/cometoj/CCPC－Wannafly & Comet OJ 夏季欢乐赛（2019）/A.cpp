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
int main(){
    int t;
    cin >> t;
    while (t--){
        ll k, n;
        cin >> k >> n;
        if (k==1) {
            cout << n - 1 << endl;
            continue;
        }
        ll now = 0;
        ll h;
        for (int i = 0;;i++)
        {
            now = now == 0 ? 1 : now * k;
            n -= now;
            if (n<=0){
                h = i;
                if (n<0)
                    n += now;
                now /= k;
                break;
            }
        }
        if (n==0)
            cout << 2 * h << endl;
        else {
            cout << (now < n ? 2 * h : 2 * h - 1) << endl;
        }
    }
}
