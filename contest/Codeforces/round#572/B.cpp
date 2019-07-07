#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    if (a[n]<a[n-1]+a[n-2]) {
        printf("YES\n");
        swap(a[n], a[n - 1]);
        for (int i = 1; i <= n;i++)
        {
            printf("%d ", a[i]);
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
