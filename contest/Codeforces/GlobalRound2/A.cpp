#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int a[N];
int n;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if (a[1]!=a[n]){
        printf("%d\n",n-1);
    }else{
        int j,k;
        for (int i=1;i<=n;i++){
            if (a[1]!=a[i]){
                j=i;
                break;
            }
        }
        for (int i=n;i>=1;i--){
            if (a[1]!=a[i]){
                k=i;
                break;
            }
        }
        printf("%d\n",max(n-j,k-1));
    }
    return 0;
}
