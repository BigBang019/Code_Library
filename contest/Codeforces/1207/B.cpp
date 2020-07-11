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
const int N = 1e2 + 5;
const int MOD = 1e9 + 7;
 
int a[N][N];
int b[N][N];
vector<pi> cur;
bool check(int x,int y){
    if (a[x][y] && a[x+1][y] && a[x][y+1] && a[x+1][y+1])
        return 1;
    return 0;
}
void doit(int x,int y){
    b[x][y] = b[x][y + 1] = b[x + 1][y] = b[x + 1][y + 1] = 1;
}
int main(){
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    bool fl = 1;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> a[i][j];
            if (a[i][j]>1)
                fl = 0;
        }
    }
    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j < m;j++)
        {
            if (check(i,j)){
                doit(i, j);
                cur.pb(mp(i, j));
            }
        }
    }
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=m;j++)
        {
            if (b[i][j]!=a[i][j])
                fl = 0;
        }
    }
    if (fl){
        cout << cur.size() << endl;
        for (auto p:cur){
            cout << p.fi << " " << p.sc << endl;
        }   
    }else{
        cout << -1 << endl;
    }
    return 0;
}
