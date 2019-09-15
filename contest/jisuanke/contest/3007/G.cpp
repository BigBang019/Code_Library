#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define db double

double arr[1000001];
char n[1000002];
double a;
int main() {
    int T; scanf("%d",&T);
    arr[0]=0;
    while(T--){
        scanf("%s %lf",&n,&a);
        if(strlen(n)>=6){
            for(int i=1;i<=1000000;i++){
                arr[i]=1.0/3.0+1.0/(3.0+1.0/(1.0+1.0/3.0+arr[i-1]));
            }
            printf("%.10f\n",1.0/arr[1000000]*a);
        }else{
            int ns = atoi(n);
            for(int i=1;i<=ns;i++){
                arr[i]=1.0/3.0+1.0/(3.0+1.0/(1.0+1.0/3.0+arr[i-1]));
            }
            printf("%.10f\n",1.0/arr[ns]*a);
        }

    }
    return 0;
}
