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
const int N = 5e5 + 5;
const int R = 1e9;

int n, k;
int tot;
vector<int> b;
int num[N];

ll sum;
int a[N];

int has(int x)
{
    return lower_bound(ALL(b), x) - b.begin() + 1;
}

bool checkH(int x){
    ll cost = 0;
    for (int i = tot; i > 0; --i)
    {
        if (b[i-1]<=x)
            break;
        cost += 1ll * num[i] * (b[i - 1] - x);
    }
    return cost <= k;
}
bool checkL(int x){
    ll cost = 0;
    for (int i = 1; i <= tot; ++i)
    {
        if (b[i-1]>=x)
            break;
        cost += 1ll * num[i] * (x - b[i - 1]);
    }
    return cost <= k;
}

int main(){
    while (~scanf("%d%d", &n, &k))
    {
        b.clear();
        sum = 0;
        REP(i, 1, n)
        {
            scanf("%d", &a[i]);
            b.pb(a[i]);
            sum += a[i];
        }
        ll fin = sum / n;
        int tot1 = n;
        int tot2 = sum - n * fin;

        sort(ALL(b));
        b.erase(unique(ALL(b)), b.end());
        tot = b.size();

        REP(i,1,tot){
            num[i] = 0;
        }
        REP(i, 1, n)
        {
            ++num[has(a[i])];
        }

        int H, L;
        int l = 1, r = R, mid, ans;
        // cout << checkH(4);
        while (l <= r)
        {
            mid = l + r >> 1;
            if (checkH(mid)){
                r = (ans = mid) - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        H = ans;
        l = 1, r = R;
        // cout << checkL(3);
        while (l <= r)
        {
            mid = l + r >> 1;
            if (checkL(mid)){
                l = (ans = mid) + 1;
            }else{
                r = mid - 1;
            }
        }
        L = ans;
        if (H<=L){
            printf("%d\n", tot2 == 0 ? 0 : 1);
        }else{
            printf("%d\n", H - L);
        }
    }
    return 0;
}
