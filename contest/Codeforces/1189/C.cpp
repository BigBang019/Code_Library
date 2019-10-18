#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int f[N][25];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        f[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n;j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = f[i][j - 1] + f[i + (1 << (j - 1))][j - 1];
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int len = r - l + 1;
        int k = 0;
        while ((1<<(k+1))<=len)
            k++;
        printf("%d\n", f[l][k] / 10);
    }
}
