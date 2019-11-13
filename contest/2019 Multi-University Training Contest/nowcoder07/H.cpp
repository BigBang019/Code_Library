/***************************************************************
  Author: 演我的队友XiaoMing
***************************************************************/
#include<cstdio>
using namespace std;
const int maxn=35;
int A[maxn];
int B[maxn];
int C[maxn];
long long f[maxn][2][2][3][3];
 
inline void init(long long x,long long y,long long z) {
    for (int i=0;i<=30;i++) {
        A[i]=x&1;
        B[i]=y&1;
        C[i]=z&1;
        x>>=1;
        y>>=1;
        z>>=1;
        for (int j=0;j<=1;j++) {
            for (int k=0;k<=1;k++) {
                for (int l=0;l<=2;l++) {
                    for (int r=0;r<=2;r++) {
                        f[i][j][k][l][r]=-1;
                    }
                }
            }
        }
    }
}
 
 
 
long long dfs(int pos,int lima,int limb,int f1,int f2) {
    if (pos<0) {return 1;}
    if (~f[pos][lima][limb][f1][f2]) {
        return f[pos][lima][limb][f1][f2];
    }
    long long res=0;
    int upA = lima? A[pos]:1;
    int upB = limb? B[pos]:1;
    for (int i=0;i<=upA;i++) {
        for (int j=0;j<=upB;j++) {
            int ff1;
            int ff2;
            if (f1!=1) {
                ff1=f1;
            } else {
                if ((i&j)==C[pos]) {
                    ff1=1; // A&B=C
                } else if ((i&j)<C[pos]) {
                    ff1=0; // A&B<C
                } else {
                    ff1=2; // A&B>C
                }
            }
            if (f2!=1) {
                ff2=f2;
            } else {
                if ((i^j)==C[pos]) {
                    ff2=1; //A^B=C
                } else if ((i^j)<C[pos]) {
                    ff2=0; //A^B<C
                } else {
                    ff2=2; //A^B>C
                }
            }
             
            if (ff1==2 || ff2==0) { //求的是不符合条件的
                continue;
            }
            res+=dfs(pos-1, lima && i==A[pos],limb && j==B[pos], ff1,ff2);
        }
    }
    f[pos][lima][limb][f1][f2]=res;
    return res;
}
 
// 思考： 为什么要求不满足条件的？
// 满足条件状态太多？
  
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x,y,z;
        scanf("%d%d%d", &x,&y,&z);
        init(x,y,z);
        long long res=dfs(30,1,1,1,1);
        if(x>=z) {res-=x-z+1;} //删去A&0 <=C 和 A^0 >=C 的情况
        if(y>=z) {res-=y-z+1;} //删去B&0 <=C 和 B^0 >=C 的情况
        long long ans=1ll*x*y-res; // 这边的容斥我看傻了QAQ
        printf("%lld\n", ans);
    }
    return 0;
}
