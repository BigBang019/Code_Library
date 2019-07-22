#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int B = 30;
int f[N][B + 3], pos[N][B + 3];
void init(){
    memset(f, 0, sizeof(f));
    memset(pos, 0, sizeof(pos));
}
void add(int i,int x){
    int k = i, tmp;
    for (int j = B; ~j;j--) f[i][j] = f[i - 1][j], pos[i][j] = pos[i - 1][j];
    for (int j = B; ~j;j--) if (x>>j)
    {
        if (!f[i][j]){
            f[i][j] = x;
            pos[i][j] = k;
            break;
        }else{
            if (k>pos[i][j]){
                tmp = k, k = pos[i][j], pos[i][j] = tmp;
                tmp = x, x = f[i][j], f[i][j] = tmp;
            }
            x ^= f[i][j];
        }
    }
}
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    int t, n, m;
    scanf("%d", &t);
    while (t--){
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n;i++)
        {
            int x;
            scanf("%d", &x);
            add(i, x);
        }
        int ans = 0;
        while(m--){
            int op, l, r;
            scanf("%d%d", &op, &l);
            if (op==0){
                scanf("%d", &r);
                l = (ans ^ l) % n + 1;
                r = (ans ^ r) % n + 1;
                if (l>r)
                    swap(l, r);
                ans = 0;
                for (int i = B; ~i;i--) if ((ans^f[r][i])>ans && pos[r][i]>=l) ans ^= f[r][i];
                printf("%d\n", ans);
            }else{
                l = (l ^ ans);
                add(++n, l);
            }
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
