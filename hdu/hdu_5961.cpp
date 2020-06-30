/*
    暴力题，只有N^2条边所以可以过，
    关键点读入的时候不要一个字符串一个字符串读
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2050;
bool vis[N][N][2];
char maze[N][N];
bool ok;
int n;
vector<int> m[N][2];
bool graph(bool flag){
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < m[i][flag].size();j++)
        {
            int p = m[i][flag][j];
            for (int k = 0; k < m[p][flag].size();k++)
            {
                int pp = m[p][flag][k];
                if (!vis[i][pp][flag])
                    return 0;
            }
        }
    }
    return 1;
}
void init(){
    for (int i = 1; i < N;i++)
    {
        m[i][0].clear();
        m[i][1].clear();
    }
    memset(vis,0,sizeof(vis));
}
void work(){
    scanf("%d",&n);
    init();
    for (int i = 1; i <= n;i++)
    {
        scanf("%s", maze[i] + 1);
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            char ch = maze[i][j];
            if (ch=='-')
                continue;
            m[i][ch == 'P'].push_back(j);
            vis[i][j][ch == 'P'] = 1;
        }
    }
    ok=graph(1);
    if (ok)
        ok=graph(0);
    printf("%s\n", ok?"T":"N");
}
int main(){
    freopen("E:\\vscode\\main\\in.txt","r",stdin);
    freopen("E:\\vscode\\main\\out.txt","w",stdout);
    clock_t st = clock();
    int t;
    scanf("%d",&t);
    while (t--){
        work();
    }
    clock_t et = clock();
    cout << (double)(et - st) / CLOCKS_PER_SEC << endl;
    fclose(stdout);
    fclose(stdin);
    return 0;
}
