/****************************************************************
    //十进制倍增过程如果修改成以下代码就TLE了
    //仍然不知道为什么
    for (int i=0;i<strlen(s);i++){
        C=C^10;
        int rem=s[i]-'0';
        if (x>0){
            tmp=A^x;
            C*=tmp;
        }
    }
*****************************************************************/
// #pragma GCC optimize(2)
#include<bits/stdc++.h>
namespace MATRIX{
    using namespace std;
    typedef unsigned long long ull;
    typedef long long ll;
    const int B = 2;///change
    int MOD;
      
    inline ll add(ll a, ll b) { a += b; return (a >= MOD ? a - MOD : a);}
  
    inline ll mul(ll a, ll b) { return a * b % MOD; }
  
    template<typename T>
    class matrix{
        public:
            int a[B][B];
            int* operator [] (ull i) {
                return a[i];
            }
            matrix<T> operator * (matrix<T> & b) const {
                matrix<T> c;
                for (int i = 0; i < B;i++)
                {
                    for (int j = 0; j < B;j++)
                    {
                        for (int k = 0; k < B;k++)
                        {
                            c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
                        }
                    }
                }
                return c;
            }
            matrix<T> &operator *= (matrix<T> &b) {
                return *this = *this * b;
            }
            matrix<T> operator ^ (ull k) const {
                matrix<T> c;
                matrix<T> tmp = *this;
                for (int i = 0; i < B;i++) c[i][i] = 1;
                while (k){
                    if (k&1){
                        c *= tmp;
                    }
                    tmp *= tmp;
                    k /= 2;
                }
                return c;
            }
            matrix(){
                for (int i = 0; i < B;i++) for (int j = 0; j < B;j++) a[i][j] = 0;
            }
    };
}
using namespace MATRIX;
const int N = 1e6 + 5;
char s[N];
  
int main(){
    int x0, x1, a, b;
    scanf("%d%d%d%d", &x0, &x1, &a, &b);
    scanf(" %s%d", s, &MOD);
    matrix<ll> A, C, X, tmp;
    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = 1;
    C[0][0] = C[1][1] = 1;
    X[0][0] = x1;
    X[1][0] = x0;
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        int rem = s[i] - '0';
        if (rem>0){
            tmp = A ^ rem;
            C = C * tmp;
        }
        A = A ^ 10;
    }
    X = C * X;
    printf("%lld\n", X[1][0]);
    return 0;
}
