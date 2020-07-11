#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
pair<int, int> a[N];
map<int, int> m;
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n;i++)
	{
		m[a[i].first - a[i - 1].first]++;
	}
	int d1 = a[2].first - a[1].first;
	m[d1]--;
	if (m[d1]==0)
		m.erase(d1);
	if (m.size()<=1){
		printf("%d", a[1].second);
		return 0;
	}
	m[d1]++;

	d1 = a[n].first - a[n-1].first;
	m[d1]--;
	if (m[d1]==0)
		m.erase(d1);
	if (m.size()<=1){
		printf("%d", a[n].second);
		return 0;
	}
	m[d1]++;
	for (int i = 2; i < n;i++)
	{
		int d1 = a[i].first - a[i - 1].first, d2 = a[i + 1].first - a[i].first;
		m[d1]--;
		if (m[d1]==0)
			m.erase(d1);
		m[d2]--;
		if (m[d2]==0)
			m.erase(d2);
		m[d1 + d2]++;
		if (m.size()==1){
			printf("%d", a[i].second);
			return 0;
		}
		m[d1]++;
		m[d2]++;
		m[d1 + d2]--;
		if (m[d1+d2]==0)
			m.erase(d1 + d2);
	}
	printf("%d",-1);
	return 0;
}
