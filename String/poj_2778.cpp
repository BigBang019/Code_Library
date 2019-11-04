#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<queue>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
const int B = 4;
const int mod = 100000;

map<char, int> fn;

struct ACAM{
    int nxt[N][B], fail[N], cnt[N];
    bool end[N];
    int tot, root;
    ll mat[N][N];
    int newNODE(){
        tot++;
        for (int i = 0; i < B;i++)
            nxt[tot][i] = -1;
        cnt[tot] = 0;
        end[tot] = 0;
        return tot;
    }
    void init(){
        tot = 0;
        root = newNODE();
        memset(mat, 0, sizeof(mat));
    }
    void update(char *s){
        int len = strlen(s);
        int now = root;
        for (int i = 0; i < len;i++)
        {
            int p = fn[s[i]];
            if (nxt[now][p]==-1)
                nxt[now][p] = newNODE();
            now = nxt[now][p];
        }
        cnt[now]++;
        end[now] = true;
    }
    void build(){
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < B;i++)
        {
            if (nxt[root][i]==-1)
                nxt[root][i] = root;
            else{
                int x = nxt[root][i];
                fail[x] = root;
                q.push(x);
            }
        }
        while (!q.empty()){
            int now = q.front(); 
            q.pop();
            if (end[fail[now]])
                end[now] = true;
            for (int i = 0; i < B; i++)
            {
                if (nxt[now][i]==-1)
                    nxt[now][i] = nxt[fail[now]][i];
                else{
                    int x = nxt[now][i];
                    fail[x] = nxt[fail[now]][i];
                    q.push(x);
                }
            }
        }
    }
    
    void setmat()
    {
        for ( int i=1;i<=tot;i++ )
        {
            for ( int j=0;j<B;j++ )
            {
                if ( !end[i] && !end[nxt[i][j]] ) mat[i][nxt[i][j]]++;
            }
        }
    }
    ll res[N][N],tmp[N][N];
    void mul(ll a[][N],ll b[][N])
    {
        for ( int i=1;i<=tot;i++ )
        {
            for ( int j=1;j<=tot;j++ )
            {
                tmp[i][j]=0;
                for ( int k=1;k<=tot;k++ ) tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
        for ( int i=1;i<=tot;i++ )
        {
            for ( int j=1;j<=tot;j++ ) a[i][j]=tmp[i][j]%mod;
        }
    }
    void pow(ll k)
    {
        memset(res,0,sizeof(res));
        for ( int i=1;i<=tot;i++ ) res[i][i]=1;
        while ( k )
        {
            if ( k&1 ) mul(res,mat);
            mul(mat,mat);
            k/=2;
        }
    }
} ac;
char s[N];
int n, m;
int main()
{
    fn['A'] = 0;
    fn['C'] = 1;
    fn['G'] = 2;
    fn['T'] = 3;
    while (~scanf("%d%d", &n, &m))
    {
        ac.init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", s);
            ac.update(s);
        }
        ac.build();
        ac.setmat();
        ac.pow(m);
        ll ans = 0;
        for ( int i=1;i<=ac.tot;i++ ) 
        {                                                                                                                                                                                  
            ans=(ans+ac.res[1][i])%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
