/*
  Author: IceRuler-wyb
          XiaoMing-zhm
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
long long dig[maxn];
int w[maxn];
 
struct Node{
    int index;
    int val;
    bool operator < (const Node &x) const {
        return val<x.val;
    }
} arr[maxn];
 
int cnt;
long long ans1,ans2;
 
void init() {
    dig[0]=1;
    for (int i=1;i<=61;i++) {
        dig[i]=dig[i-1]*2;
    }
    ans1=0;
    ans2=0;
}
 
void parse(long long x) {
    cnt=0;
    int k=1;
    while (x) {
        if (x%2==1) {
            w[cnt]=k;
        } else {
            w[cnt]=0;
        }
        x=x>>1;
        k=k*2%3;
        cnt++;
    }
    return ;
}
 
void solve(long long a) {
     
//  for (int i=0;i<cnt;i++) {
//      printf("%d ", w[i]);
//  }printf("\n");
     
    ans1=a;
    ans2=a;
    int sum=0;
    int tot=0;
    for (int i=0;i<cnt;i++) {
        if (w[i]>0) {
            arr[tot].index=i;
            arr[tot].val=w[i];
            tot++;
            sum=sum+w[i];
            sum=sum%3;
        }
    }
    sort(arr,arr+tot);
     
//  for (int i=0;i<tot;i++) {
//      printf("%d %d\n", arr[i].index, arr[i].val);
//  }printf("%d\n",sum);
     
    if (sum==1) {
        if (arr[0].val==1) {
            ans1=ans1-dig[arr[0].index];
            if (arr[1].val==1) {
                ans2=ans2-dig[arr[1].index];
            } else {
                ans2=ans2-dig[arr[1].index]-dig[arr[2].index];
            }
        } else {
            ans1=ans1-dig[arr[0].index]-dig[arr[1].index];
            ans2=ans2-dig[arr[2].index]-dig[arr[3].index];
        }
    } else {
        if (arr[tot-1].val==2) {
            ans1=ans1-dig[arr[tot-1].index];
            if (arr[tot-2].val==2) {
                ans2=ans2-dig[arr[tot-2].index];
            } else {
                ans2=ans2-dig[arr[tot-2].index]-dig[arr[tot-3].index];
            }
        } else {
            ans1=ans1-dig[arr[tot-1].index]-dig[arr[tot-2].index];
            ans2=ans2-dig[arr[tot-3].index]-dig[arr[tot-4].index];
        }
    }
}
 
int main() {
    long long a;
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        scanf("%lld", &a);
        if (a%3==0) {
            printf("1 %lld\n", a);
            continue;
        }
        parse(a);
        solve(a);
        printf("2 %lld %lld\n", ans1, ans2);
    }
    return 0;
}
