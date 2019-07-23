/*
  Author: IceRuler-wyb
*/
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
const int maxn=1E6;

struct Node{
    int index;
    double v;
    double s;
    double l;
} a[maxn];
int n;
double st[maxn];
double ve[maxn];

bool check(double t) {
    double mxm=-100;
    for (int i=1;i<=n;i++) {
        double en=st[i]-ve[i]*t;
        if (en>mxm) {
            mxm=en;
        }
    }
    if (mxm>0) {
        return false;
    } else {
        return true;
    }
}
int main() {
    while (~scanf("%d", &n)) {
        n++;
        for (int i=1;i<=n;i++) {
            double x;
            scanf("%lf", &x);
            a[i].l=x;
        }
        for (int i=1;i<=n;i++) {
            double x;
            scanf("%lf", &x);
            a[i].s=x;
        }
        for (int i=1;i<=n;i++) {
            double x;
            scanf("%lf", &x);
            a[i].v=x;
        }
        int sum=0;
        for (int i=1;i<=n;i++) {
            st[i]=a[i].s+sum;
            ve[i]=a[i].v;
            sum+=a[i+1].l;
        }
        
        double l=0;
        double r=1E9+1;
        while (fabs(r-l)>=1E-7) {
//            printf(":: %.7lf %.7lf\n", l, r);
            double mid=(l+r)/2;
            if (check(mid)) {
                r=mid;
            } else {
                l=mid;
            }
        }
        printf("%.7lf\n", l);
    }
    return 0;
}
