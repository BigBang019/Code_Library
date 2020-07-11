#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N], p[N];
int k, l[26], r[26];
int nxt[N][26];
int last[26];
int cnt[N][26];

int now[26];

bool ok(int ch,int num){
    return (num >= l[ch]);
}
bool check(int pos, int ppos)
{
    int p = s[pos] - 'a';
    if (now[p] + 1 > r[p])
        return 0;
    int left = k - ppos;
    for (int j = 0; j < 26; j++)
    {
        if (!ok(j, now[j] + cnt[pos + 1][j] + (j == p ? 1 : 0)))//后面的是否够用
            return 0;
        if (left + now[j] + (j == p ? 1 : 0) < l[j])//后面几个位置不够用了
            return 0;
    }
    int sum = 0;
    for (int j = 0; j < 26; j++)
    {
        sum += max(0, l[j] - now[j] - (j == p ? 1 : 0));
    }
    if (sum>left)//全部的最低需求
        return 0;
    return 1;
}

void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(p, 0, sizeof(p));
    memset(now, 0, sizeof(now));
}
void work(){
    init();
    for (int i = 0; i < 26;i++)
    {
        scanf("%d%d", &l[i], &r[i]);
    }
    memset(last, -1, sizeof(last));
    for (int i = strlen(s + 1); i; i--)
    {
        int p = s[i] - 'a';
        for (int j = 0; j < 26;j++)
        {
            nxt[i][j] = last[j];
            cnt[i][j] = cnt[i + 1][j];
        }
        last[p] = i;
        cnt[i][p]++;
    }
    for (int j = 0; j < 26;j++)
    {
        nxt[0][j] = last[j];
    }
    int ind = 0;
    bool fl = 0;
    for (int i = 1; i <= k; i++)
    {
        fl = 0;
        for (int j = 0; j < 26; j++)
        {
            int pos = nxt[ind][j];
            if (check(pos, i))
            {
                now[j]++;
                fl = 1;
                p[i] = 'a' + j;
                ind = nxt[ind][j];
                break;
            }
        }
        if (!fl)
            break;
    }
    printf("%s\n", fl ? p + 1 : "-1");
    
}
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    while (~scanf(" %s%d", s + 1, &k)){
        work();
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
