// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
#define inf 999999999
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
const int N = 2e5 + 5;
const int B = 31;
int nx = 0, ny = 0, k;
ll linky[N],lx[N],ly[N],slack[N];
int visx[N], visy[N];
ll w[10][N];
ll min(ll a,ll b){return (a<b)?a:b;}
int find(int x){
    visx[x]=1;
    for(int y=1;y<=ny;y++){
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0){visy[y]=1;
            if(linky[y]==-1||find(linky[y])){
                linky[y]=x;return 1;
            }
        }
        else if(slack[y]>t) slack[y]=t;
    }
    return 0;
}
ll km(){
    memset(linky,-1,sizeof(linky));
    memset(ly,0,sizeof(ly));
    for(int i=1;i<=nx;i++) lx[i]=-inf;
    for(int i=1;i<=nx;i++)for(int j=1;j<=ny;j++)if(w[i][j]>lx[i])lx[i]=w[i][j];
    for(int x=1;x<=nx;x++){
        for(int i=1;i<=ny;i++)
            slack[i]=inf;
        while(1){
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(x)) break;
            int d=inf;
            for(int i=1;i<=ny;i++) if(!visy[i]&&d>slack[i]) d=slack[i];
            for(int i=1;i<=nx;i++) if(visx[i]) lx[i]-=d;
            for(int i=1;i<=ny;i++) if(visy[i]) ly[i]+=d; else slack[i]-=d;
        }
    }
    ll result=0;
    for(int i=1;i<=ny;i++)
    if(linky[i]>-1) result+=w[linky[i]][i];
    return result;
}
int main(){
    scanf("%d", &ny);
    nx = 5;
    for (int i = 1; i <= ny;i++)
    {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        w[1][i] = a;
        w[2][i] = b;
        w[3][i] = c;
        w[4][i] = d;
        w[5][i] = e;
    }
    printf("%lld\n", km());
    return 0;
}
