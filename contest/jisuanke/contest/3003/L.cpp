#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
int a[50];
ll dp[50][4][11][2];

struct Node{
	ll fi;
	ll se;
};

Node dfs(int pos,int pre,int sta,bool limit, int bi)//µ×ÏÂÕâ¸öÊÇÇóÃ»ÓÐ38ºÍ49×ÓÐòÁÐµÄ¸öÊýµÄ 
{
    if(pos==-1) {
    	Node tmp;
		tmp.fi =0;
		tmp.se =1;
		return tmp;
	}
    if(!limit && dp[pos][sta][bi][0]!=-1) {
		Node tmp;
		tmp.fi = dp[pos][sta][bi][0];
		tmp.se = dp[pos][sta][bi][1];
		return tmp;
	}
    int up=limit ? a[pos] : (bi-1);
    ll tmp1=0;
    ll tmp2=0;
    for(int i=0;i<=up;i++) {
        Node res = dfs(pos-1,i,sta,limit && i==a[pos], bi);
        tmp1+=i*res.se+res.fi;
        tmp2+=res.se;
    }
    
    if(!limit) {
		dp[pos][sta][bi][0]=tmp1;
		dp[pos][sta][bi][1]=tmp2;
	}
	Node res;
	res.fi = tmp1;
	res.se = tmp2;
    return res;
}
ll solve(ll x, ll bi) {
    ll pos=0;
    while(x) {
        a[pos++]=x%bi;
        x/=bi;
    }
    Node res = dfs(pos-1,-1,0,true,bi);
    return res.fi;
}


//ll fuck(ll x, ll bi) {
//	ll res=0;
//	for (ll y =1; y<=x; y++) {
//		ll sum=y;
//		for (int i=1;i<=60;i++) {
//			res+=sum%bi;
//			sum=sum/bi;
//		}
//	}
//	return res;
//}
//
//void debug() {
//	
//	if (solve(436234,5)!=fuck(436234,5)) {
//		printf("SHIT\n");
//	}
//}

int main()
{
    int T;int ri;int bi;
    scanf("%d",&T); 
    memset(dp,-1,sizeof dp);
    int rd=0;
    while(T--) {
    	rd++;
        scanf("%d%d",&ri, &bi);
        printf("Case #%d: %lld\n",rd,solve(ri, bi));
    }
    return 0;
}
