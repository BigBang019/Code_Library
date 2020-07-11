// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second;
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1e5 + 5;
int n, x, y;
int a[N];
int main(){
    cin >> n >> x >> y;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++)
    {
        bool ok1 = 1;
        for (int j = i - 1; j >= i - x && j > 0;j--)
        {
            if (a[j]<=a[i]){
                ok1 = 0;
                break;
            }
        }
        bool ok2 = 1;
        for (int j = i + 1; j <= i + y && j <= n;j++)
        {
            if (a[j]<=a[i]){
                ok2 = 0;
                break;
            }
        }
        if (ok1 && ok2){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
