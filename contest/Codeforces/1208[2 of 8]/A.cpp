#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORD(I, N) for (int I = N; ~I; --I)
#define REP(I, A, B) for (int I = A; I <= (B); ++I)
#define REPD(I, B, A) for (int I = B; I >= A; --I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int N = 2e5 + 5;
const ll R = 1e15;
ll a, b, n;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--){
		cin >> a >> b >> n;
        if (n%3==0){
            cout << a;
        }else if (n%3==1){
            cout << b;
        }else{
            cout << (a ^ b);
        }
        cout << endl;
    }
	return 0;
}
