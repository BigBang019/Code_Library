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
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
int L[N], R[N];
int LD[N], RD[N];
int n, k;
int pre[N], a[N];
stack<pi> st;
ll ans = 0;

void dfs(int l,int r){
    if (r-l<=3){
        REP(i,l,r){
            set<int> s;
            int mx = -1;
            REP(j,i,r){
                mx = max(mx, a[j]);
                if (s.count(a[j])) break;
                s.insert(a[j]);
                if (mx-(j-i+1)<=k) ans++;
            }
        }
        return;
    }
    int mid = l + r >> 1;

    int mx = -1, p = -1;
    int nr = r, tr = r, tl, nl;
    REPD(i,mid,l){
        if (a[i]>mx){
            mx = a[i];
            p = i;
        }
        nr = min(nr, RD[i] - 1);
        tr = min(nr, R[p] - 1);
        tl = max(mid + 1, mx + i - k - 1);
        ans += max(0, tr - tl + 1);
    }
    nl = tl = l;
    mx = p = -1;
    REP(i,mid+1,r){
        if (a[i]>mx){
            mx = a[i];
            p = i;
        }
        nl = max(nl, LD[i] + 1);
        tl = max(nl, L[p] + 1);
        tr = min(mid, k + i + 1 - mx);
        ans += max(0, tr - tl + 1);
    }
    dfs(l, mid);
    dfs(mid + 1, r);
}

void init(){
    memset(pre, 0, sizeof(pre));
    ans = 0;
}

int main(){
    int _;
    for (scanf("%d", &_); _;_--)
    {
        scanf("%d%d", &n, &k);
        init();
        REP(i,1,n){
            scanf("%d", &a[i]);
        }
        REP(i,1,n){
            while (!st.empty() && st.top().fi<a[i]){
                R[st.top().sc] = i;
                st.pop();
            }
            st.push(mp(a[i], i));
            LD[i] = max(LD[i - 1], pre[a[i]]);
            pre[a[i]] = i;
        }
        while (!st.empty()){
            R[st.top().sc] = n + 1;
            st.pop();
        }
        memset(pre, 0x3f, sizeof(pre));
        RD[n + 1] = n + 1;
        REPD(i,n,1){
            while (!st.empty() && st.top().fi<a[i]){
                L[st.top().sc] = i;
                st.pop();
            }
            st.push(mp(a[i], i));
            RD[i] = min(RD[i + 1], pre[a[i]]);
            pre[a[i]] = i;
        }
        while (!st.empty()){
            L[st.top().sc] = 0;
            st.pop();
        }
        dfs(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}
