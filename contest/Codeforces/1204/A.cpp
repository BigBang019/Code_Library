// #pragma GCC optimize(3)
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
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
char s[N];
int main(){
    // ios::sync_with_stdio(false);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int len = n;
    int cnt = 0;
    while (n>1){
        n -= 2;
        cnt++;
    }
    for (int i = 2; i <= len;i++)
    {
        if (s[i]!='0' && len%2==1){
            cnt++;
            break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
