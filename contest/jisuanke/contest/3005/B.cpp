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

pi qu[N];
vector<int> b;
int n, q;
bool tree[N << 2];
bool mm[N << 2];
int has(int x)
{
    return lower_bound(ALL(b), x) - b.begin() + 1;
}
void update(int x,int l,int r,int p){
    if (l==r){
        tree[x] = 0;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        update(x << 1, l, mid, p);
    else
        update(x << 1 | 1, mid + 1, r, p);
    tree[x] = tree[x << 1 | 1] || tree[x << 1];
}

int query(int x,int l,int r,int k){
    if (l==r){
        return b[l - 1];
    }
    int mid = l + r >> 1;
    int le = b[mid - 1] + 1;
    int re = b[mid] - 1;
    if (k <= mid && (tree[x << 1] || mm[x << 1]))
    {
        int res=query(x << 1, l, mid, k);
        if (~res)
            return res;
    }
    if (k<=mid && re-le>=0){
        return le;
    }
    if (tree[x << 1 | 1] || mm[x << 1 | 1])
    {
        return query(x << 1 | 1, mid + 1, r, k);
    }
    return -1;
}

void build(int x,int l,int r){
    mm[x] = 0;
    tree[x] = 1;
    if (l == r){
        return;
    }
    int mid = l + r >> 1;
    int le = b[mid - 1] + 1;
    int re = b[mid] - 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    mm[x] = (re >= le) || mm[x << 1] || mm[x << 1 | 1];
}

int main(){
    scanf("%d%d", &n, &q);
    REP(i,1,q){
        scanf("%d%d", &qu[i].fi, &qu[i].sc);
        b.pb(qu[i].sc);
    }
    b.pb(n);
    b.pb(1);
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    n = b.size();
    build(1, 1, n);
    REP(i, 1, q)
    {
        if (qu[i].fi==1){
            update(1, 1, n, has(qu[i].sc));
        }else{
            int res = query(1, 1, n, has(qu[i].sc));
            printf("%d\n", res);
        }
    }
    return 0;
}
