#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
int c[N];
int res[N];
int main(){
    ios_base::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    int p = n+1;
    for (int i = m; i >= 1; i--)
    {
        p = p - c[i];
        a[i] = p;
    }
    p=0;
    for (int i = 1; i <= m; i++)
    {
        if (p+d<a[i]) {
            a[i] = p + d;
        }
        p = a[i] + c[i] - 1;
    }
    if (p+d<n+1) {
        puts("NO");
    }else{
        puts("YES");
        for (int i = 1; i <= n; i++)
        {
            res[i]=0;
		}
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < c[i]; j++)
            {
                res[a[i] + j] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", res[i], " \n"[i == n]);
        }
    }
	
}
