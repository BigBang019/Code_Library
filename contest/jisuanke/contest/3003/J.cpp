#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn=200000;
const long long mod=1E9+7;
long long f[maxn];
int a[maxn];

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d", &n);
		int sum=0;
		for (int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		int hal = (sum+1)/2; // S' should be greater or equal that hal
		for (int i=0;i<=sum;i++) {
			f[i]=0;
		}
		f[0]=1;
		for (int i=n;i>=1;i--) {
			for (int j=hal-1;j>=0;j--) {
				if (j+a[i]<hal) { 
					f[j+a[i]]+=f[j];
				} else {
					if (sum-(j+a[i])>=j) {
						f[j+a[i]]+=f[j];
					}
				}
				f[j+a[i]]%=mod;
			}
			
//			for (int i=0;i<=sum;i++) {
//				printf("%lld ", f[i]);
//			}printf(" --\n");
			
		}
		long long res = 0;
		for (int i=hal;i<=sum;i++) {
			res=res+f[i];
			res%=mod;
		}
		printf("%d\n", res);
	}
	return 0;	
}
