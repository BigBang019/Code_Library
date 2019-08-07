//Pohlig Hellman 解离散对数
//离散对数问题 本题p为1e18 因此BSGS的O(根号p)不可接受
//但性质：题目保证p-1的因数只有2和/或3 
//新算法：  PH算法(Pohlig Hellman)
//该算法适用于 p-1有质因数分解相关的性质时
//Author: IceRuler
//算法原理：
//对于一个素数p，先求n=p-1并将其分解为x个素数因子，对于每一个因子q及其指数c，应用Pohlig-Helliman算法求解（a0,a1,a3............ac-1）
//根据a=(for i=0 to c-1:ai*q^i)+s*q^(s为某一整数) 求得  x个同余式，最后利用中国剩余定理求解离散对数的解



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//O(1)快速乘 防爆
ll mul(ll u, ll v, ll p) {
    return (u * v - ll((long double) u * v / p) * p + p) % p;
}
//快速幂：当相乘会爆ll 时需要配合快速乘使用  将乘法替换为快速乘  p大于等于3e9的时候就要开mul
inline ll bin(ll base, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * base % p;
        base = base * base % p;
        n >>= 1;
    }
    return res;
}inline ll get_inv(ll x, ll p) {  return bin(x, p - 2, p);  }

//分解质因数 分解p-1
ll factor[30], f_sz, factor_exp[30];
void get_factor(ll x)
{
    f_sz = 0;
    memset(factor, 0, sizeof(factor));
    memset(factor_exp, 0, sizeof(factor_exp));

    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            factor[f_sz] = i;
            factor_exp[f_sz] = 0;
            while (x % i == 0)
            {
                x /= i;
                factor_exp[f_sz]++;
            }
            f_sz++;
        }
    if (x > 1)
    {
        factor[f_sz] = x;
        factor_exp[f_sz] = 1;
        f_sz++;
    }
}

//扩展欧几里得
//若a 和 b 互素，那么 x 是 a 在模 b 下的逆元
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}

//中国剩余定理
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


ll find_smallest_primitive_root(ll p) {
    static map<ll,ll> root;
    if(root.count(p)) return root[p];
    get_factor(p - 1);
    for (int i = 2; i < p; i++) {
        bool flag = true;
        for (int j = 0; j < f_sz; j++)
            if (bin(i, (p - 1) / factor[j], p) == 1) {
                flag = false;
                break;
            }
        if (flag) return root[p] = i;
    }
    assert(0); return -1;
}

ll get_pow(ll rt, ll x, ll p) {
    ll n = p - 1;
    ll now = rt;
    ll res = 0, ker = 1;
    for(int i = 0; i < f_sz; i++) {
        for(int j = 0; j < factor_exp[i]; j++) {
            ll fac = factor[i];
            n /= fac;
            if(bin(x, n, p) != 1) {
                x = mul(x, now, p);
                res += ker;
            }
            ker *= fac;
            now = mul(now, now, p);
        }
    }
    res = (p - 1 - res) % (p - 1); 
    return res;
}
// a*x+b*y=z
struct gcd_t {long long x,y,z;};  
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}

// bool flag;
// ll go(ll id, ll up, ll now, ll a, ll b, ll p)
// {
//     if (now == up)
//         return 0;
//     ll tower = (p - 1) / bin(id, now + 1, p);
//     ll bi = bin(b, tower, p);

//     for (int i = 0; i < id; i++)
//     {
//         ll c = i * (p - 1) / id;
//         if (bin(a, c, p) == bi)
//         {
//             ll tmp = i * bin(id, now, p);
//             ll nextb = mul(b , bin(a, (p - 1 - i * bin(id, now, p)) % (p - 1), p), p);
//             return tmp + go(id, up, now + 1, a, nextb, p);
//         }
//     }
//     flag = false;
//     return -1;
// }
// ll solve(ll a, ll b, ll p)
// {
//     ll m[f_sz], r[f_sz];
//     ll cnt = 0;
//     for (int i = 0; i < f_sz; i ++)
//     {
//         r[cnt] = go(factor[i], factor_exp[i], 0ll, a, b, p);
//         m[cnt] = bin(factor[i], factor_exp[i], p);
//         cnt++;
//     }
//     ll ans = CRT(m, r, f_sz);
//     return ans;
// }
ll p,a,b;
int main() {
    int T; scanf("%d",&T);
    while(T--){
        scanf("%lld %lld %lld",&p, &a, &b);
        ll _a = a, _b = b;
        int rt;   //p的原根
        rt = find_smallest_primitive_root(p); //找原根的同时已经分解好p-1了
        // printf("%lld %lld\n",f_sz,factor_exp[f_sz-1]);
        ll pa = get_pow(rt, a, p); //分别对a,b进行get_power处理
        ll pb = get_pow(rt, b, p);
        // printf("%lld %lld\n",pa,pb);
        if(pa == 0){
            if(pb == 0){
                printf("1\n");  //1就可以
            }else{
                printf("-1\n"); //无解
            }
        // }else if (pb % pa == 0)
        // {
        //     printf("%lld\n", ll(pb / pa));
        // }
        // else{
        //     ll x, y;
        //     ll g = ex_gcd(pa, p - 1, x, y);
        //     if (pb % g) {
        //         printf("-1\n"); //无解
        //     }else {
        //         pa /= g;
        //         pb /= g;
        //         ll mmod = (p - 1) / g;
        //         ex_gcd(pa, mmod, x, y);
        //         printf("%lld\n", mul(pb , (x + mmod) , mmod));
        //     }
        // }
        }
        else {
            gcd_t gg=gcd(a,p-1);
            if(pb%gg.z) printf("-1\n");
            else {
                if(gg.x<0)gg.x+=p-1;
                ll res = mul(gg.x, pb / gg.z, (p - 1)/gg.z);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}
