#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
char s[N], t[N];
ll countSubstrings(string s) {
	//预处理
	string t = "#";
	for (int i = 0; i < s.size(); ++i) {
		t += s[i];
		t += "#";
	}

	vector<ll> RL(t.size(), 0);
	ll MaxRight = 0, pos = 0;
	ll res = 0;
	for (int i = 0; i < t.size(); ++i) {
		RL[i] = MaxRight > i ? min(RL[2 * pos - i], MaxRight - i) : 1;

		while (i-RL[i] >=0 && i+RL[i] < t.size() && t[i + RL[i]] == t[i - RL[i]])//扩展，注意边界
			++RL[i];
		//更新最右端及其中心
		if (MaxRight < i + RL[i] -1) {
			MaxRight = i + RL[i] -1;
			pos = i;
		}
		
		res += RL[i]/2;
	}
	return res;
}

void work(){
	scanf(" %s",s);
	scanf(" %s",t);
	int left = -1, right = -1;
	for (int i = 0; i < strlen(s);i++)
	{
		if (s[i]!=t[i]){
			if (left==-1)
				left = i;
			right = i;
		}
	}
	
	ll ans = 0;
	if (left==-1 && right==-1){
		ans = countSubstrings(s);
	}else{
		bool flag = 0;
		for (int i = left, j = right; i <= right;i++,j--)
		{
			if (s[i]!=t[j]) {
				flag = 1;
				break;
			}
		}
		if (flag){
			printf("0\n");
			return;
		}
		ans = 1;
		for (int i = left-1, j = right+1; i >= 0 && j < strlen(s);i--,j++)
		{
			if (s[i]!=s[j]){
				break;
			}
			ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		work();
	}
	return 0;
}
