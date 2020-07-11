//角排序
#include<bits/stdc++.h>
using namespace std;
const int MAXN=305;
struct Point{
    double x,y;
    Point(double _x=0.0,double _y=0.0):x(_x),y(_y){};
    Point operator-(const Point& p)const{return Point(x-p.x,y-p.y);};
    double operator*(const Point& p)const{return x*p.x+y*p.y;};
    Point unit()const{return Point(x/hypot(x,y),y/hypot(x,y));};
}p[MAXN],t[MAXN],P;
int n;
bool cmp(Point a,Point b){
    return a*P<b*P;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        t[i]=p[i];
    }
    double res=0.0;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            P=(p[j]-p[i]).unit();
            sort(t+1,t+n+1,cmp);
            res=max(res,t[n/2+1]*P-t[n/2]*P);
            swap(P.x,P.y);
            P.y*=-1.0;
            sort(t+1,t+n+1,cmp);
            res=max(res,t[n/2+1]*P-t[n/2]*P);
        }
    }
    printf("%.10f\n",res/2.0);
    return 0;
}
