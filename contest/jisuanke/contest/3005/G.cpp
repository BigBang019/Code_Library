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

struct PAM{
    int nxt[N][27]; //next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[N];    //fail指针，失配后跳转到fail指针指向的节点
    int cnt[N];
    int num[N];
    int len[N]; //len[i]表示节点i表示的回文串的长度
    int S[N];   //存放添加的字符
    int last;   //指向上一个字符所在的节点，方便下一次add
    int n;      //字符数组指针
    int p;      //节点指针

    int newnode(int l){ //新建节点
        for (int i = 0; i < 27; ++i)
            nxt[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init(){ //初始化
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1; //开头放一个字符集中没有的字符，减少特判
        fail[0] = 1;
    }

    int get_fail(int x){ //和KMP一样，失配后找一个尽量最长的
        while (S[n - len[x] - 1] != S[n])
            x = fail[x];
        return x;
    }

    void extend(int c){
        S[++n] = c;
        int cur = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        if (!nxt[cur][c])
        {                                            //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode(len[cur] + 2);         //新建节点
            fail[now] = nxt[get_fail(fail[cur])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            nxt[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nxt[cur][c];
        cnt[last]++;
    }

    void count(){
        for (int i = p - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
        //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    }

    int vis[27];
    int col[N];
    void dfs(int x)
    {
        
        for (int i = 0; i < 26;++i)
        {
            if (!nxt[x][i])
                continue;
            int p = nxt[x][i];
            col[p] = col[x] + (vis[i] == 0);
            vis[i]++;
            dfs(p);
            vis[i]--;
        }
    }
    ll getAns(){
        count();
        col[0] = col[1] = 0;
        for (int i = 0; i < 26;++i){
            vis[i] = 0;
        }
        dfs(1);
        dfs(0);
        ll ans = 0;
        for (int i = 2; i < p; ++i)
        {
            ans += 1ll * col[i] * cnt[i];
        }
        return ans;
    }
} pam;

char s[N];

int main(){
    // clock_t st = clock();
    scanf(" %s", s);
    int n = strlen(s);
    pam.init();
    for (register int i = 0; i < n;++i)
    {
        pam.extend(s[i] - 'a');
    }
    printf("%lld\n", pam.getAns());
    // clock_t et = clock();
    // cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
