#include <cmath>
#include <cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int phi[N], prime[N];
int pointer;
void Euler()
{
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            prime[pointer++] = i;
        }
        for (int j = 0; j < pointer && i * prime[j] < N; j++)
        {
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int a[100];
ll n;
int main(){
    Euler();
    while (~scanf("%lld", &n))
    {
        ll ans = 0;
        for (int i = 2; i <= 64;i++){
            a[i] = floor(pow(n, 1.0 / i)) - 1;
        }
        for (int i = 2; i <= 64;i++)
        {
            int num = 0;
            int x = i;
            bool fl = 1;
            for (int j = 0; j < pointer && x > 1; j++)
            {
                if (x%prime[j]==0){
                    num++;
                }
                int times = 0;
                while (x%prime[j]==0){
                    x /= prime[j];
                    times++;
                }
                if (times>1)
                    fl = 0;
            }
            if (fl)
                ans += (num & 1 ? 1 : -1) * a[i];
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}
