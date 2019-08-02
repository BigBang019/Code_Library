#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1E6;

int dig[100];
int ans[maxn];
int ansn;


int main() {
    int T;
    dig[0]=1;
    for (int i=1;i<=30;i++) {
        dig[i]=dig[i-1]*2;
    }
    
    for (scanf("%d", &T);T;T--) {
        int n;
        long long ansn=0;
        scanf("%d", &n);
        for (int i=2;i<=n;i++) {
            bool pd=false;
            for (int j=0;dig[j]<=n;j++) {
                if ((dig[j]&i)==0) {
                    ans[i-1]=dig[j];
                    pd=true;
                    break;
                }
            }
            if (!pd) {
                ansn+=1;
                ans[i-1]=1;
            }
        }
        printf("%lld\n", ansn);
        for (int i=1;i<=n-1;i++) {
            printf("%d%s", ans[i], i==n-1? "\n":" ");
        }
    }        
    return 0;
}
