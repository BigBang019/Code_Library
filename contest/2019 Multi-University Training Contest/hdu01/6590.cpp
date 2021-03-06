#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
#define pb push_back
#define ll long long
using namespace std;
const double eps = 1e-8;
int sgn(double k) { return fabs(k) < eps ? 0 : (k > 0 ? 1 : -1); }

//1. 点： 加 减 乘 叉积   
struct P
{
    ll x,y;
    P(){}
    P(ll _x,ll _y)
    {
        x = _x;y = _y;
    }//向量相加
    P operator +(const P &b)const
    {
        return P(x + b.x,y + b.y);
    }//向量减
    P operator -(const P &b)const
    {
        return P(x - b.x,y - b.y);
    }
    //向量点积
    ll operator ^(const P &b)const
    {
        return x*b.x + y*b.y;
    }
    //向量叉积 
    ll operator *(const P &b)const
    {
        return x*b.y - y*b.x;
    }
};

// 点叉积  
long long det(P a, P b, P c) {
    return (b - a) * (c - a);
}


//直线：  位置关系  交点求解   
struct L{
    P a,b;
    L(){}
    L(P _s,P _e)
    {
        a = _s;b = _e;
    }
    pair<P,int> operator &(const L &_b)const
    {
        P res = a;
        if(sgn((a-b)^(_b.a-_b.b)) == 0)
        {
            if(sgn((_b.a-a)^(_b.b-a)) == 0)
                return make_pair(res,0);//两直线重合
            else return make_pair(res,1);//两直线平行
        }
        ll t = ((a-_b.a)^(_b.a-_b.b))/((a-b)^(_b.a-_b.b));
        res.x += (b.x - a.x)*t;
        res.y += (b.y - a.y)*t;
        return make_pair(res,2);//有交点res
    }
};
//点在线段上
bool onSeg(P p, L s) {
    return sgn(det(p, s.a, s.b)) == 0 && sgn((s.a - p) ^ (s.b - p)) <= 0;
}
//线段相交
bool SegmentIntersection(L l1, L l2) {
    long long c1 = det(l1.a, l1.b, l2.a), c2 = det(l1.a, l1.b, l2.b);
    long long c3 = det(l2.a, l2.b, l1.a), c4 = det(l2.a, l2.b, l1.b);
    if (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0) return true;
    if (sgn(c1) == 0 && onSeg(l2.a, l1)) return true;
    if (sgn(c2) == 0 && onSeg(l2.b, l1)) return true;
    if (sgn(c3) == 0 && onSeg(l1.a, l2)) return true;
    if (sgn(c4) == 0 && onSeg(l1.b, l2)) return true;
    return false;
}

//凸包求解
vector<P> convex(vector<P> p) {
    vector<P> ans, S;
    for (int i = 0; i < p.size(); i++) {
        while (S.size() >= 2
                && sgn(det(S[S.size() - 2], S.back(), p[i])) <= 0)
                    S.pop_back();
        S.push_back(p[i]);
    }
    ans = S;
    S.clear();
    for (int i = (int)p.size() - 1; i >= 0; i--) {
        while (S.size() >= 2
                && sgn(det(S[S.size() - 2], S.back(), p[i])) <= 0)
                    S.pop_back();
        S.push_back(p[i]);
    }
    for (int i = 1; i + 1 < S.size(); i++)
        ans.push_back(S[i]);
    return ans;
}

//点在多边形内部    前置：onSeg
bool PointInPolygon(P p, vector<P> poly) {
    int cnt = 0;
    for (int i = 0; i < poly.size(); i++) {
        if (onSeg(p, L(poly[i], poly[(i + 1) % poly.size()]))) return true;
        int k = sgn(det(poly[i], poly[(i + 1) % poly.size()], p));
        int d1 = sgn(poly[i].y - p.y);
        int d2 = sgn(poly[(i + 1) % poly.size()].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0) cnt++;
        if (k < 0 && d2 <= 0 && d1 > 0) cnt--;
    }
    if (cnt != 0) return true;
    return false;
}

//凸包相交
bool ConvexHullDivide(vector<P> p1, vector<P> p2) {
    for (int i = 0; i < p1.size(); i++)
        if (PointInPolygon(p1[i], p2))
            return false;
    for (int i = 0; i < p2.size(); i++)
        if (PointInPolygon(p2[i], p1))
            return false;
    for (int i = 0; i < p1.size(); i++)
        for (int j = 0; j < p2.size(); j++)
            if (SegmentIntersection(L(p1[i], p1[(i + 1) % p1.size()]), L(p2[j], p2[(j + 1) % p2.size()])))
                return false;
    return true;
}
vector<P> p1,p2;
vector<P> c1,c2;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        p1.clear();p2.clear();c1.clear();c2.clear();
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            if(c==1){
                p1.pb(P(x,y));
            }else{
                p2.pb(P(x,y));
            }
        }
        c1=convex(p1);
        c2=convex(p2);
        if(ConvexHullDivide(c1,c2)){
            printf("Successful!\n");
        }else{
            printf("Infinite loop!\n");
        }

    }
}
