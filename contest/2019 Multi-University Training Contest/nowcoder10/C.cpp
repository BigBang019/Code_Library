// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define LEN(X) strlen(X)
#define SZ(X) ((ll)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (ll I = 0; I < (N); ++I)
#define FORD(I, N) for (ll I = N; ~I; --I)
#define REP(I, A, B) for (ll I = A; I <= (B); ++I)
#define REPD(I, B, A) for (ll I = B; I >= A; --I)
#define FORS(I, S) for (ll I = 0; S[I]; ++I)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef pair<ll, ll> pl;
const ll N = 1e6 + 5;
const int base = 13131;

char tmp[10], s[N * 2];
ll p[N], f[N * 2];
int L[N], R[N];
int d[N], n;
ll query(int l,int r){
    return (f[r] - f[l - 1] * p[r - l + 1]);
}
char id(string tmp){
    if (tmp=="do") return 'a';
    else if (tmp=="re") return 'b';
    else if (tmp=="mi") return 'c';
    else if (tmp=="fa") return 'd';
    else if (tmp=="sol") return 'e';
    else if (tmp=="la") return 'f';
    else return 'g';
}
int main(){
    p[0] = 1;
    for (int i = 1; i <= N - 5; i++) p[i] = p[i - 1] * base;
    scanf("%d", &n);
    int h = n + 5, t = n + 5;
    REP(i,1,n){
        char op;
        scanf(" %c %s", &op, tmp);
        (op == 'a' ? s[t++] : s[--h]) = id(tmp);
        L[i] = h, R[i] = t - 1;
    }
    REP(i, h, t - 1) f[i] = f[i - 1] * base + s[i];
    for (int x = 1; x <= n; x++)
    {
        int l = x, r = n, mid, ans = 1;
        while (l<=r){
            mid = l + r >> 1;
            if (query(L[mid], R[mid] - x) == query(L[mid] + x, R[mid]))
                l = (ans = mid) + 1;
            else
                r = mid - 1;
        }
        d[x]++;
        d[ans + 1]--;
        printf("%d\n", d[x] += d[x - 1]);
    }
    return 0;
}
