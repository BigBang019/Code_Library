#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
 
char ch[50][50000];
int len[50];
int p[50];
int cnt[50];
char ans[50000];
 
int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    int mm=m*(m-1)/2;
    for (int i=1;i<=mm;i++) {
        getchar();
        char x,y;
        scanf("%c%c", &x,&y);
        scanf("%d", &len[i]);
        getchar();
        for (int j=1;j<=len[i];j++) {
            scanf("%c", &ch[i][j]);
        }
         
    }
//  for (int i=1;i<=mm;i++) {
//      for (int j=1;j<=len[i];j++) {
//          printf("%c", ch[i][j]);
//      }printf("\n");
//  }
     
    for (int i=1;i<=mm;i++) {
        p[i]=1;
    }
    bool pd=true;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<m;j++) {
            cnt[j]=0;
        }
        for (int j=1;j<=mm;j++) {
            if (p[j]<=len[j]){
                cnt[ch[j][p[j]]-'a']++;
            }
        }
        int num=0;
        int numj;
        for (int j=0;j<m;j++) {
            if (cnt[j]==m-1) {
                num++;
                numj=j;
            }
        }
        if (num==1) {
            ans[i]=numj+'a';
            for (int j=1;j<=mm;j++) {
                if (p[j]<=len[j] && ch[j][p[j]]==ans[i]) {
                    p[j]++;
                }
            }
        } else {
            pd=false;
            break;
        }
    }
    for (int i=1;i<=mm;i++) {
        if (p[i]!=len[i]+1) {
            pd=false;
            break;
        }
    }
    if (pd) {
        for (int i=1;i<=n;i++) {
            printf("%c", ans[i]);
        }printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}
