#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (k % 3 != 0)
        {
            cout << (n % 3 ? "Alice" : "Bob") << endl;
        }
        else if (k != 3)
        {
            ll p = (k / 3) - 1;
            ll div = p * 3 + 4;
            ll rem = n % div;
            cout << ((rem == 0 || (rem != 0 && rem % 3 == 0) && rem != (div - 1)) ? "Bob" : "Alice") << endl;
        }
        else
        {
            cout << (n % 4 ? "Alice" : "Bob") << endl;
        }
    }
    return 0;
}
