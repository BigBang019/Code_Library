#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct NODE{
	ll p;
	ll v;
	NODE (){}
	NODE (ll p,ll v):p(p),v(v){}
} b[N];
bool cmp(NODE a,NODE b){
	return (a.v == b.v ? a.p < b.p : a.v < b.v);
}
int n;
ll x, y;
ll getIndex(ll p,ll v){
	int l = 1, r = n, mid;
	ll ans = -1;
	while (l<=r){
		mid = l + r >> 1;
		if (b[mid].v<v){
			l = mid + 1;
		}else if (b[mid].v>v){
			r = mid - 1;
		}else if (b[mid].p<p){
			l = mid + 1;
		}else if (b[mid].p>p){
			r = mid - 1;
		}else{
			ans = mid;
			break;
		}
	}
	return ans;
}
void work(){
	scanf("%d%lld%lld",&n,&x,&y);
	ll x1 = 0, y1 = 0;
	for (int i = 1; i <= n;i++)
	{
		scanf("%lld",&b[i].v);
		b[i].p = i;
		x1 += i * b[i].v;
		y1 += i * b[i].v * b[i].v;
	}
	
	sort(b+1,b+1+n,cmp);
	ll ans = 0;
	if (x1==x||y1==y){
		if (x1==x && y1==y){
			ll cnt = 0;
			for (int i = 1; i <= n;i++)
			{
				if (i==1 || b[i].v==b[i-1].v)
					cnt++;
				else {
					ans += cnt * (cnt - 1) / 2;
					cnt = 1;
				}
			}
			if (cnt)
				ans += cnt * (cnt - 1) / 2;
		}else
			ans = 0;
	}else{
		ll tmp = (y1 - y) % (x1 - x);
		if (tmp == 0 && (y1-y)/(x1-x)>0){
			ll C = (y1 - y) / (x1 - x);
			for (int i = 1; i <= n;i++)
			{
				ll v = C - b[i].v;//aj
				if (b[i].v==v)
					continue;
				ll pos = b[i].p - (x1 - x) / (b[i].v - v);//j
				ll ind = getIndex(pos, v);
				if (ind!=-1 && ind>=i)
					ans++;
			}
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
