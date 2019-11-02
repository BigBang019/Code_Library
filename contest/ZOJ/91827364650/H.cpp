#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
bool able[N];
int n;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i = 1; i <= n;i++)
		{
			scanf("%d",&a[i]);
		}
		int cnt = 0;
		int minus = 0;
		for (int i = 2; i < n;i++)
		{
			if (a[i]>a[i-1] && a[i]>a[i+1]){
				able[i] = 1;
				cnt++;
				if (a[i-1]==a[i+1])
					minus = 1;
				else if (a[i-1]>a[i+1]){
					if (i-2<=0 || a[i-1]<=a[i-2])
						minus = 1;
				}else {
					if (i+1>n || a[i+1]<=a[i+2])
						minus = 1;
				}
			}
			
		}
		for (int i = 2; i < n;i++)
		{
			if (able[i-1] && able[i+1] && a[i-1]==a[i+1]){
				minus = 2;
			}
		}
		printf("%d\n",max(cnt-minus,0));
	}
	return 0;
}
