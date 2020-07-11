#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000000;

struct Node{
	int id;
	int w;
	bool operator < (const Node &x) {
		if (w==x.w) {
			return id<x.id;
		} else {
			return w<x.w;
		}
	}
} a[maxn];

int mx[maxn];
int ans[maxn];


int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d", &x);
		a[i].id=i;
		a[i].w=x;
	}
	sort(a+1,a+n+1);
	mx[n+1]=0;
	for (int i=n;i>=1;i--) {
		if (mx[i+1]>a[i].id) {
			mx[i]=mx[i+1];
		} else {
			mx[i]=a[i].id;
		}
	}
	for (int i=1;i<=n;i++) {
		int w=a[i].w+m;
		int l=i+1;
		int r=n+1;
		while (l<r) {
			int mid=(l+r)/2;
			if (a[mid].w>=w) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		if (l<=n) {
			ans[a[i].id] = mx[l]-a[i].id-1;
		} else {
			ans[a[i].id] = -1;
		}
	}
	for(int i=1;i<=n;i++) if(ans[i]<0) ans[i]=-1;
	for (int i=1;i<=n;i++) {
		printf("%d%s", ans[i], i==n?"":" ");
	}
	return 0;
}
