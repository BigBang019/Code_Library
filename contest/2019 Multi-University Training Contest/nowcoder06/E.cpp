#include<cstdio>
#include<cstring>
using namespace std;
 
int aa[5][5];
int bb[5];
int f[2010][2010];
int to[2010];
 
inline void init() {
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    aa[1][2]=1;
    aa[2][1]=1;
    aa[2][3]=1;
    aa[3][2]=1;
    aa[3][4]=1;
    aa[4][3]=1;
    bb[1]=2;
    bb[2]=4;
    bb[3]=1;
    bb[4]=3;
}
inline void addedge(int x,int y) {
    f[x][y]=1;
    f[y][x]=1;
}
 
int main() {
    int T;
    init();
    scanf("%d", &T);
    for (int fuck=1;fuck<=T;fuck++) {
        memset(f,0,sizeof(f));
        memset(to,0,sizeof(to));
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", fuck);
        if (!(n%4==0 || n%4==1)) {
            printf("No\n");
            continue;
        }
        if (n%4==1) {
            to[1]=1;
            for (int i=1;i<=4;i++) {
                to[i+1]=bb[i]+1;
            }
            for (int i=1;i+4<=n;i+=4) {
                for (int j=1;j<=3;j++) {
                    addedge(i+j, i+j+1);
                }
                for (int j=1;j<=4;j++) {
                    if (i>=5) {
                        to[i+j]=to[i+j-4]+4;
                    }
                }
                for (int j=1;j<=i;j++) {
                    addedge(i+2, j);
                    addedge(i+3, j);
                }
            }
        } else {
            for (int i=1;i<=4;i++) {
                for (int j=1;j<=4;j++) {
                    f[i][j]=aa[i][j];
                }
                to[i]=bb[i];
            }
            for (int i=4;i+4<=n;i+=4) {
                for (int j=1;j<=3;j++) {
                    addedge(i+j, i+j+1);
                }
                for (int j=1;j<=4;j++) {
                    to[i+j]=to[i+j-4]+4;
                }
                for (int j=1;j<=i;j++) {
                    addedge(i+2, j);
                    addedge(i+3, j);
                }
            }
        }
        printf("Yes\n");
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                printf("%d", f[i][j]);
            }printf("\n");
        }
        for (int i=1;i<=n;i++) {
            printf("%d%s", to[i], i==n? "\n":" ");
        }
    }
    return 0;
}
