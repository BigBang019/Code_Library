/**********************************************************************
  Author: XiaoMing
***********************************************************************/
#include<cstdio>
#include<cstring>
 
using namespace std;
char ch[1000];
int a[10];
int vis[10];
 
int res[10];
 
int main() {
    int T;
    scanf("%d", &T);
    for (int fuck=1;fuck<=T;fuck++) {
        scanf("%s", ch);
        for (int i=1;i<=8;i++) {
            int dig=1;
            a[i]=0;
            for (int j=1;j<=16;j++) {
                if (ch[i*16-j]=='1') {
                    a[i]+=dig;
                }
                dig=dig<<1;
            }
        }
        memset(vis,0,sizeof(vis));
        int l=0;
        for (int i=1;i<=8;i++) {
            if (a[i]==0) {
                vis[i]=vis[i-1]+1;
            } else {
                vis[i]=0;
            }
            if (vis[i]>l) {
                l=vis[i];
            }
        }
        int p=0;
        for (int i=7;i>=1;i--) {
            if (vis[i]==l) {
                p=i;
                break; 
            }
        }
        if ((p==0 || (p-l+1==1)) && vis[8]==l) {
            p=8;
        }
//      if (p==0 && vis[8]==l) {
//          p=8;
//      }
         
        int tot=0;
        res[0]=0;
        for (int i=1;i<=8;i++) {
            if (l>1 && p-l+1<=i && i<=p) {
                res[tot]=-2;
            } else {
                tot++;
                res[tot]=a[i];
                tot++;
                res[tot]=-1;
            }
        }
        if (res[tot]==-1) {
            tot--;
        }
         
        printf("Case #%d: ", fuck);
         
        if (res[0]==-2) {
            printf("::");
        }
        for (int i=1;i<=tot;i++) {
            if (res[i]==-1) {
                printf(":");
            } else if (res[i]==-2) {
                printf("::");
            } else {
                printf("%x", res[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
