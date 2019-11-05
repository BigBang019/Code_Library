#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<queue>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
const int MOD = 100000;
int a[N], pos[N];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n;++i)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int now = 1;
        for (int i = 1; i <= n && now<n; ++i)
        {
            if (pos[i]>now){
                int ind = pos[i];
                while (ind>now){
                    swap(a[ind - 1], a[ind]);
                    pos[a[ind]] = ind;
                    --ind;
                }   
                now = pos[i];
            }else if (pos[i]==now){
                now = pos[i] + 1;
            }
        }
        for (int i = 1; i <= n;++i)
        {
            printf("%d%c", a[i], " \n"[i == n]);
        }
    }
    return 0;
}

