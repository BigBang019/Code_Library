/*
 * Author: zwh
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc(ll x, int d) {
	ll ret = 0, r = x, fac = 1ll;
	while(x) {
		ret += fac * (x / 10);
		if(x % 10 > d) ret += fac;
		else if(x % 10 == d) ret += r - x * fac + 1;
		x /= 10; fac *= 10;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int d; ll x, r; scanf("%d%lld", &d, &x);
		while(calc(x, d) > x) {
			x--;
			ll l = 0, r = x;
			while(l < r) {
				ll mid = (l + r) >> 1;
				if(calc(mid, d) > x) r = mid;
				else l = mid + 1;
			}
			x = l;
		}
		for(; calc(x, d) != x; x = calc(x, d));
		printf("%lld\n", x);
	}
	return 0;
}
