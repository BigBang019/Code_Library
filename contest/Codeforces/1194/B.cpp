#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, m;
vector<string> maze;
char s[N];
int col[N];
int row[N];
void init(){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    maze.clear();
}
void work(){
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++)
    {
        scanf(" %s", s);
        maze.push_back(s);
    }
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if (maze[i][j]=='*') {
                col[j]++;
                row[i]++;
            }
        }
    }
    int mi = 0x3f3f3f3f;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            int tmp = 0;
            if (maze[i][j]=='.')
                tmp--;
            tmp += n + m - col[j] - row[i];
            mi = min(tmp, mi);
        }
 
    }
    printf("%d\n", mi);
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
