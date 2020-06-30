#include <cmath>
#include <cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 3e6 + 5;
char s[N];
ll x, y, k, k2;
int main(){
    int n;
    scanf("%d%lld%lld", &n, &x, &y);
    scanf(" %s", s);
    int i = 0;
    k = 0;
    for (; i < strlen(s);i++)
    {
        if (s[i]=='0')
            break;
    }
    for (; i < strlen(s);i++)
    {
        if (s[i]=='1' && s[i-1]=='0')
            k++;
    }
    if (s[i-1]=='0')
        k++;
    cout << min(k * y , max(k - 1, 0ll) * x + y);
    return 0;
}
