#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n;
ll c[N], a[N];
ll pos[N];
int lowbit(int x){
    return x & (-x);
}
void add(int x,ll v){
    for (int i = x; i <= n; i += lowbit(i))
    {
        c[i] += v;
    }
}
ll query(int x){
    ll sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}
inline ll getNum(){
    ll sum = 0;
    char ch;
    while((ch=getchar())==' '||ch=='\n'||ch=='\r')
        ;
    sum += ch - '0';
    while(isdigit(ch=getchar()))
        sum = sum * 10 + ch - '0';
    return sum;
}
inline void write(ll x)
{
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9) 
		write(x/10);
    putchar(x % 10 + '0');
}
int main(){
    int t;
    t = getNum();
    while(t--){
        n = getNum();
        for (int i = 1; i <= n;i++)
        {
            c[i] = 0;
            a[i] = getNum();
            pos[a[i]] = i;
        }
        ll tot = 0;
        ll ans = 0;
        for (int i = 1; i <= n;i++)
        {
            add(a[i], 1);
            int tmp = query(a[i]);
            tot += i - tmp;
        }
        ans = tot;
        for (int i = 1; i < n;i++)
        {
            tot -= pos[i] - 1;
            tot += n - pos[i];
            ans = min(ans, tot);
        }
        write(ans);
        printf("\n");
    }
    return 0;
}
