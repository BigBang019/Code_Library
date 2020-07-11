#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;
const int N = 1e5 + 5;
bool ok[N];
int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        int d = gcd(a, b);
        printf("%s\n", d == 1 ? "finite" : "infinite");
    }
    return 0;
}
