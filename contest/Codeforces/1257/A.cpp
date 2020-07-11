#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
 
int main(){
    int _;
    for (scanf("%d", &_); _; --_)
    {
        int n, x, a, b;
        scanf("%d%d%d%d", &n, &x, &a, &b);
        if (a>b)
            swap(a, b);
        int now = abs(a - b);
        int cnt = min(x, n - b);
        now += cnt;
        x -= cnt;
        cnt = min(x, a - 1);
        now += cnt;
        printf("%d\n", now);
    }
    return 0;
}

