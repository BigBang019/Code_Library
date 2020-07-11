#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1E6+10;
const int maxl=1E7+10;


int n;
int l[maxn];
int r[maxn];
int le[maxn];
int ri[maxn];
int cur[3*maxl];


int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
	l[0]=r[0]=-1;
	l[n+1]=r[n+1]=1E9;
	int sum=0;
	for (int i=1;i<=n;i++) {
		sum=sum+r[i]-l[i]+1;
		if (sum>=l[i+1]-r[i]-1) {
			sum=sum-(l[i+1]-r[i]-1);
			ri[i]=l[i+1]-1;
		} else {
			ri[i]=r[i]+sum;
			sum=0;
		}
	}
	sum=0;
	for (int i=n;i>=1;i--) {
		sum=sum+r[i]-l[i]+1;
		if (sum>=l[i]-r[i-1]-1) {
			sum=sum-(l[i]-r[i-1]-1);
			le[i]=l[i-1]+1;
		} else {
			le[i]=l[i]-sum;
			sum=0;
		}
	}
	
	int minn=maxl;
	int maxx=maxl;
	int pos=0;
	int now=-1;
	long long ans=0;
	for (int i=1;i<=n;i++) {
		if (now<le[i]) {
			for (int j=minn;j<=maxx;j++) {
				cur[j]=0;
			}
			minn=maxx=maxl;
			pos=maxl;
			sum=0;
			now=le[i];
			cur[maxl]=1;
		}
		
		while (now<l[i]) {
			sum-=cur[--pos];
			cur[pos]++;
			ans+=sum;
			now++;
			minn=min(minn,pos);
		}
		
		while (now<=r[i]) {
			sum+=cur[pos++];
			cur[pos]++;
			ans+=sum;
			now++;
			maxx=max(maxx,pos);
		}
		
		while (now<=ri[i]) {
			sum-=cur[--pos];
			cur[pos]++;
			ans+=sum;
			now++;
			minn=min(minn,pos);
		}
	}
	printf("%lld\n", ans);
}
