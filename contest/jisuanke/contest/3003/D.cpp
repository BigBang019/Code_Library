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
const int N = 3e3 + 5;
const int MOD = 1e9 + 7;

int n;
ll A[N];

int ans = 0;

vector<int> vc[N << 1];

pi st[N];
int top;

int qp(int a, int k)
{
    int res = 1;
    while (k){
        if (k&1)
            res = 1ll * res * a % MOD;
        k >>= 1;
        a = 1ll * a * a % MOD;
    }
    return res;
}
int check()
{
    // cout << "begin" << endl;
    int res = A[n];
    for (int i = 1; i <= top; ++i)
    {
        // cout << st[i].fi << " " << st[i].sc << endl;
        int b = st[i].sc;
        if (b==1)
            continue;
        res = 1ll * res * qp(A[b], MOD - 2) % MOD;
    }
    // cout << "end\n" << endl;
    return res;
}

void dfs(int left,int sum,int mul,int last){
    if (!left){
        if (sum==0 && mul==1){
            ans += check();
            ans %= MOD;
        }
        return;
    }
    if (left>sum)
        return;
    for (int p : vc[mul])
    {
        if (p>sum)
            break;
        if (p>last)
            break;
        if (top!=0 && st[top].fi==p){
            ++st[top].sc;
        }else{
            st[++top] = mp(p, 1);
        }
        dfs(left - 1, sum - p, mul / p, p);
        if (--st[top].sc==0){
            --top;
        }
    }
    if (left==sum && 1==mul){
        st[++top] = mp(1, left);
        ans += check();
        ans %= MOD;
        --top;
    }
}

int main(){
    // clock_t sst = clock();
    A[1] = 1;
    for (register int i = 2; i <= 3000; ++i)
        A[i] = A[i - 1] * i % MOD;
    for (register int i = 2; i <= 6000;++i)
    {
        for (register int j = i; j <= 6000; j += i)
        {
            vc[j].pb(i);
        }
    }
    int _;
    for (scanf("%d", &_); _;--_)
    {
        scanf("%d", &n);
        top = ans = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
        {
            dfs(n, i, i, n);
        }
        printf("%d\n", ans);
    }
    // clock_t et = clock();
    // cout << (double)(et - sst) / CLOCKS_PER_SEC << endl;
    return 0;
}
