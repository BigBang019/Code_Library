#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%d", &a[i]);
        }
        sort(a+1,a+n+1);
        int p=1;
        long long ans1=0;
        long long ans2=0;
        for (int i=n;i>=1;i--) {
            p=p^1;
            if (p==0) {
                ans1+=(long long)a[i];
            } else {
                ans2+=(long long)a[i];
            }
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
