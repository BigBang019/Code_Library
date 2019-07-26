#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
pair<int,int> a[N];
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = make_pair(x, y);
        }
        sort(a + 1, a + 1 + n);
        int mid = n / 2;
        if (a[mid].first==a[mid+1].first){
            printf("%d %d %d %d\n", a[mid].first - 1, a[mid].second + 10000000, a[mid].first + 1, a[mid + 1].second - 10000000);
        }else{
            printf("%d %d %d %d\n", a[mid].first, 999000000, a[mid + 1].first, -999000000);
        }
    }
    return 0;
}
