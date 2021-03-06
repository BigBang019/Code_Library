// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
const int B = 26;
const int MOD = 998244353;
ll ans = 0;
struct PAM{
    int nxt[N][B+3];    //next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[N];        //fail指针，失配后跳转到fail指针指向的节点
    int len[N]; //len[i]表示节点i表示的回文串的长度
    int S[N];   //存放添加的字符
    int last;   //指向上一个字符所在的节点，方便下一次add
    int n;      //字符数组指针
    int p;      //节点指针

    int newnode(int l){ //新建节点
        for (int i = 0; i < B; ++i)
            nxt[p][i] = 0;
        len[p] = l;
        return p++;
    }

    inline void init(){ //初始化
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

    inline void extend(int c){
        S[++n] = c;
        int cur = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        if (!nxt[cur][c])
        {                                            //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode(len[cur] + 2);         //新建节点
            fail[now] = nxt[get_fail(fail[cur])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            nxt[cur][c] = now;
        }
        last = nxt[cur][c];
    }
    int sz[N];
    int vis[N];
    int cnt[N];
    void dfs(int x){
        sz[x] = 1;
        cnt[x] = 1 + (vis[fail[x]] == 0);
        vis[x]++;
        vis[fail[x]]++;
        for (int i = 0; i < 26;i++)
        {
            if (nxt[x][i]){
                dfs(nxt[x][i]);
                sz[x] += sz[nxt[x][i]];
            }
        }
        vis[x]--;
        vis[fail[x]]--;
    }
    ll getAns(){
        for (int i = 0; i <= p;i++)
        {
            vis[i] = 0;
            cnt[i] = 0;
        }
        ll ans = 0;
        dfs(0);
        dfs(1);
        for (int i = 2; i < p;i++)
        {
            ans += 1ll * sz[i] * cnt[i] - 1;
        }
        return ans;
    }
} pam;

char s[N]; //abaabacac
int main()
{
    int _, cas = 0;
    for (scanf("%d", &_); _; _--)
    {
        pam.init();
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len;i++)
        {
            pam.extend(s[i] - 'a');
        }
        printf("Case #%d: %lld\n", ++cas, pam.getAns());
    }
    return 0;
}
