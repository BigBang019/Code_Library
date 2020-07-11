#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = -1e9 - 7;
 
int phi[N], prime[N];
int pointer = 0;
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
 
ll n;
 
int main(){
    Euler();
    cin >> n;
    if (n==1){
        puts("1");
        return 0;
    }
    int who=0;
    bool ok = 1;
    for (int i = 0; i < pointer && n>1;++i)
    {
        if (n%prime[i]==0){
            while (n%prime[i]==0){
                n /= prime[i];
            }
            who = prime[i];
            if (n!=1){
                ok = 0;
            }
        }
    }
    if (!ok){
        puts("1");
    }else if (who){
        printf("%d\n", who);
    }else{
        printf("%lld\n", n);
    }
    return 0;
}
