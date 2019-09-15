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
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

char name[20], cards[20];
int n;

struct NODE{
    int k, v, r;
    NODE(){}
    NODE(int k, int v, int r) : k(k), v(v), r(r){}
    bool operator < (const NODE &b) const
    {
        if (k==b.k){
            if (v==b.v)
                return r > b.r;
            else
                return v > b.v;
        }else
            return k > b.k;
    }
};
pair<NODE, string> a[N];

NODE work()
{
    int len = strlen(cards);
    int pos = 0;

    int mx = 0;
    int who = 0;
    vector<int> vis = vector<int>(20, 0);
    int sum = 0;
    while (pos < len)
    {
        int x = 0;
        if (cards[pos]=='A')
            x = 1;
        else if (cards[pos]=='J')
            x = 11;
        else if (cards[pos]=='Q')
            x = 12;
        else if (cards[pos]=='K')
            x = 13;
        else if (cards[pos]=='1')
            x = 10, ++pos;
        else
            x = cards[pos] - '0';
        
        ++pos;
        sum += x;
        if (mx < ++vis[x])
        {
            mx = vis[x];
            who = x;
        }
    }
    if (vis[1] && vis[10] && vis[11] && vis[12] && vis[13])
        return NODE(8, 0, 0);

    for (int i = 1; i <= 9;++i)
    {
        if (vis[i] && vis[i+1] && vis[i+2] && vis[i+3] && vis[i+4])
            return NODE(7, i + 4, 0);
    }
    if (mx==4){
        return NODE(6, who, sum - 4 * who);
    }
    if (mx==3){
        for (int i = 1; i <= 13; ++i)
        {
            if (vis[i]==2)
                return NODE(5, who, i);
        }
        return NODE(4, who, sum - 3 * who);
    }
    if (mx==2){
        for (int i = 1; i <= 13;++i)
        {
            if (vis[i]==2 && i!=who) {
                if (who<i)
                    swap(who, i);
                return NODE(3, who * 100 + i, sum - 2 * who - 2 * i);
            }
        }
        return NODE(2, who, sum - 2 * who);
    }
    return NODE(1, sum, 0);
}

int main(){
    while (~scanf("%d",&n)){
        for (int i = 1; i <= n;++i){
            scanf("%s%s", name, cards);
            a[i] = mp(work(), name);
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n;++i){
            printf("%s\n", a[i].sc.c_str());
        }
    }
    return 0;
}
