#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n;
int a[N];
void work(){
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    int ans = -0x3f3f3f3f;
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            if (i==j)
                continue;
            int d = a[i] - a[j];
            for (int l = 1, r = j - 1; l < r;)
            {
                int sum = a[l] + a[r];
                if (sum==d){
                    ans = a[i];
                    break;
                }
                if (sum<d) {
                    l++;
                }else{
                    r--;
                }
            }
            if (ans!=-0x3f3f3f3f)
                break;
        }
        if (ans!=-0x3f3f3f3f)
            break;
    }
    if (ans==-0x3f3f3f3f)
        printf("no solution\n");
    else
        printf("%d\n", ans);
    
}
int main(){
    while(scanf("%d",&n) && n){
        work();
    }
    return 0;
}
