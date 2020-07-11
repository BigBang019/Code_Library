#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000100;
int n;
int b[maxn];
int pre[maxn][3][3];
int f[maxn][3][3];
int v[maxn][3];
int ans[maxn];
 
int getmid(int a,int b,int c) {
    int res[3]={a,b,c};
    sort(res,res+3);
    return res[1];
}
 
inline void init() {
    b[1]=b[3];
    b[2]=b[3];
    b[n+1]=b[n];
    b[n+2]=b[n];
    for (int i=1;i<=n;i++) {
        v[i][0]=b[i];
        v[i][1]=b[i+1];
        v[i][2]=b[i+2];
    }
    for (int i=1;i<=n;i++) {
        sort(v[i],v[i]+2);
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=2;j++) {
            for (int k=0;k<=2;k++) {
                f[i][j][k]=0;
                pre[i][j][k]=0;
            }
        }
    }
}
 
bool solve() {
    for (int j=0;j<=2;j++) {
        for (int k=0;k<=2;k++) {
            f[2][j][k]=1;
        }
    }
    for (int i=3;i<=n;i++) {
        for (int j=0;j<=2;j++) {
            for (int k=0;k<=2;k++) {
                for (int l=0;l<=2;l++) {
                    if (f[i-1][k][l]==1) {
                        if (getmid(v[i-2][l], v[i-1][k], v[i][j])==b[i]) {
                            f[i][j][k]=1;
                            pre[i][j][k]=l;
                            break;
                        }
                    }
                }
            }
        }
    }
    bool pd=false;
    int pj;
    int pk;
    int l;
    for (int j=0;j<=2;j++) {
        for(int k=0;k<3;k++) {
            if(f[n][j][k]==1) {
                pj=j;pk=k;
                pd=true;
                break;
            }
        }
        if (pd) {
            break;
        }
    }
    if (!pd) {
        return false;
    }
    for (int i=n;i>=2;i--) {
        ans[i]=v[i][pj];
        int l=pre[i][pj][pk];
        pj=pk;
        pk=l;
    }
    ans[1]=b[1];
    return true;
}
 
int main() {
    int T;
    for (scanf("%d", &T);T;T--) {
        scanf("%d", &n);
        for (int i=3;i<=n;i++) {
            scanf("%d", &b[i]);
        }
        init();
        if (solve()) {
            for (int i=1;i<=n;i++) {
                printf("%d ", ans[i]);
            }printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
