#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100;

ll m[maxn];
ll r[maxn];
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
ll CRT(ll *m, ll *r, ll n) {  //无解返回-1  前置模板：扩展欧几里得
    if (!n) return 0;
    ll M = m[0], R = r[0], x, y, d;
    for (int i =  1; i < n; i++) {
        d = ex_gcd(M, m[i], x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R >= 0 ? R : R + M;
}
ll fibo[100];
int main() {
    fibo[0]=2; fibo[1]=3;
    int p=71;
    for(int i=2;i<=71;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    // for(int i=1;i<=12;i++) printf("%lld ",fibo[i]);
    ll k; scanf("%lld",&k);
    for(int i=0;i<=k-1;i++){
        scanf("%lld",&m[i]);
        scanf("%lld",&r[i]);
    }
    ll ans=CRT(m,r,k);
    // ll ans;scanf("%lld",&ans);
    if(ans==-1||ans>1E15) {printf("Tankernb!"); return 0 ;}
    else{
        if(ans==1){
            printf("Zgxnb!");
        }else{
            for(int i=0;i<p;i++){
                if(ans==fibo[i]) {printf("Lbnb!"); return 0 ;}
            }
            printf("Zgxnb!");
        }
    }
    return 0;
}
