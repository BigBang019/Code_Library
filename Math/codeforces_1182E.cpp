#include <bits/stdc++.h>
namespace MATRIX{
    using namespace std;
    typedef unsigned long long ull;
    typedef long long ll;
    const int MOD = 1e9 + 6;///////////////////////////////////坑1
    const int MOD2 = 1e9 + 7;//////////////////////////////////坑2

    inline ll add(ll a, ll b) { a += b; return (a >= MOD ? a - MOD : a);}

    inline ll mul(ll a, ll b) { return a * b % MOD; }

    template<typename T>
    class matrix{
        public:
            int n;
            vector<vector<T>> vc;
            vector<T> &operator [] (ull i) {
                return vc[i];
            }
            matrix<T> operator * (matrix<T> & b) const {
                matrix<T> c(n);
                for (int i = 0; i < n;i++)
                {
                    for (int j = 0; j < n;j++)
                    {
                        for (int k = 0; k < n;k++)
                        {
                            c[i][j] = add(c[i][j], mul(vc[i][k], b[k][j]));
                        }
                    }
                }
                return c;
            }
            matrix<T> &operator *= (matrix<T> &b) {
                return *this = *this * b;
            }
            matrix<T> operator ^ (ull k) const {
                matrix<T> c(n);
                matrix<T> tmp = *this;
                for (int i = 0; i < n;i++) c[i][i] = 1;
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
                vc.clear();
            }
            matrix(int n):n(n){
                vc = vector<vector<T>>(n, vector<T>(n, 0));
            }
    };
}
using namespace MATRIX;

ll qp(ll a,ll k){
    ll sum = 1;
    while (k){
        if (k&1){
            sum = (sum * a) % MOD2;
        }
        a = a * a % MOD2;
        k /= 2;
    }
    return sum;
}
int main(){
    ll n, df1, df2, df3, d;
    scanf("%lld%lld%lld%lld%lld", &n, &df1, &df2, &df3, &d);


    matrix<ll> xc(5);
    xc[3][0] = 3;
    xc[4][0] = 1;
    matrix<ll> c(5);
    c[0][0] = c[0][1] = c[0][2] = 1;
    c[0][3] = 2;
    c[0][4] = -4 + MOD;//////////////////////////////////////////坑3
    c[1][0] = 1;
    c[2][1] = 1;
    c[3][3] = 1;
    c[3][4] = 1;
    c[4][4] = 1;

    c = c ^ (n - 3);
    xc = c * xc;
    d = qp(d, xc[0][0]);

    matrix<ll> xf1(3);
    xf1[2][0] = 1;
    matrix<ll> f1(3);
    f1[0][0] = f1[0][1] = f1[0][2] = f1[1][0] = f1[2][1] = 1;

    f1 = f1 ^ (n - 3);
    xf1 = f1 * xf1;
    df1 = qp(df1, xf1[0][0]);

    matrix<ll> xf2(3);
    xf2[1][0] = 1;
    matrix<ll> f2(3);
    f2[0][0] = f2[0][1] = f2[0][2] = f2[1][0] = f2[2][1] = 1;

    f2 = f2 ^ (n - 3);
    xf2 = f2 * xf2;
    df2 = qp(df2, xf2[0][0]);

    matrix<ll> xf3(3);
    xf3[0][0] = 1;
    matrix<ll> f3(3);
    f3[0][0] = f3[0][1] = f3[0][2] = f3[1][0] = f3[2][1] = 1;

    f3 = f3 ^ (n - 3);
    xf3 = f3 * xf3;
    df3 = qp(df3, xf3[0][0]);

    //printf("%lld %lld %lld %lld %lld\n", xc[0][0], xf1[0][0], xf2[0][0], xf3[0][0], ((d * df1 % MOD2) * df2 % MOD2) * df3 % MOD2);
    printf("%lld", ((d * df1 % MOD2) * df2 % MOD2) * df3 % MOD2);
    return 0;
}
