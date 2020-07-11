#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef long long LL;
LL R,ans;
bool is_q(LL x){ return ((LL)sqrt(x))*((LL)sqrt(x))==x; }
LL gcd(LL x,LL y){ return y==0?x:gcd(y,x%y); }

struct P
{
    LL x,y;
    P(){}
    P(LL _x,LL _y)
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
    LL operator *(const P &b)const
    {
        return x*b.x + y*b.y;
    }
    //向量叉积 
    LL operator ^(const P &b)const
    {
        return x*b.y - y*b.x;
    }
};LL dis(P p1,P p2) {   return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
} 

vector<P> pa;
vector<P> pb;
P getP(ll A,ll B,ll R){
    ll d = (2*R)/(A+B);
    ll x = sqrt(A*B*d*d);
    ll y = sqrt(R*R-x*x);
    return P(x,y);
}
bool cmp(P a, P b){
    if(a.x<b.x) return true;
    else if(a.x==b.x && a.y < b.y) return true;
    else return false;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        pa.clear(); pb.clear();
        LL a,b,c;
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        LL R = a;
        for(LL i=1;i*i<=2*R;i++) if((2*R)%i==0){
            LL d=i;
            for(LL a=1;a*a<=2*R/d/2;a++) if(is_q(2*R/d-a*a)){
                LL A=a*a, B=2*R/d-a*a;
                if(gcd(A,B)==1&&A!=B){
                    P num1 = getP(A,B,R);
                    LL x1 = num1.x;
                    LL y1  =num1.y;
                    pa.push_back(num1);
                    pa.push_back(P(x1,-y1));
                    pa.push_back(P(-x1,y1));
                    pa.push_back(P(-x1,-y1));
                }
            }
            if(d*d==2*R) continue;
            d=2*R/d;
            for(LL a=1;a*a<=2*R/d/2;a++) if(is_q(2*R/d-a*a)){
                LL A=a*a, B=2*R/d-a*a;
                if(gcd(A,B)==1&&A!=B) {
                    P num1 = getP(A,B,R);
                    LL x1 = num1.x;
                    LL y1  =num1.y;
                    pa.push_back(num1);
                    pa.push_back(P(x1,-y1));
                    pa.push_back(P(-x1,y1));
                    pa.push_back(P(-x1,-y1));
                }
            }       
        }
        R=b;
        for(LL i=1;i*i<=2*R;i++) if((2*R)%i==0){
            LL d=i;
            for(LL a=1;a*a<=2*R/d/2;a++) if(is_q(2*R/d-a*a)){
                LL A=a*a, B=2*R/d-a*a;
                if(gcd(A,B)==1&&A!=B){
                    P num1 = getP(A,B,R);
                    LL x1 = num1.x;
                    LL y1  =num1.y;
                    pb.push_back(num1);
                    pb.push_back(P(x1,-y1));
                    pb.push_back(P(-x1,y1));
                    pb.push_back(P(-x1,-y1));
                }
            }
            if(d*d==2*R) continue;
            d=2*R/d;
            for(LL a=1;a*a<=2*R/d/2;a++) if(is_q(2*R/d-a*a)){
                LL A=a*a, B=2*R/d-a*a;
                if(gcd(A,B)==1&&A!=B){
                    P num1 = getP(A,B,R);
                    LL x1 = num1.x;
                    LL y1  =num1.y;
                    pb.push_back(num1);
                    pb.push_back(P(x1,-y1));
                    pb.push_back(P(-x1,y1));
                    pb.push_back(P(-x1,-y1));
                }
            }       
        }
        pa.push_back(P(0,a)); pa.push_back(P(a,0)); pa.push_back(P(-a,0)); pa.push_back(P(0,-a));
        pb.push_back(P(0,b)); pb.push_back(P(b,0)); pb.push_back(P(-b,0)); pb.push_back(P(0,-b));

        sort(pa.begin(),pa.end(),cmp);
        sort(pb.begin(),pb.end(),cmp);

        // for(int i=0;i<pa.size();i++) printf("%.0f %.0f\n",pa[i].x,pa[i].y);
        // for(int i=0;i<pb.size();i++) printf("%.0f %.0f\n",pb[i].x,pb[i].y);

        vector<int> ap,bp; ans=0;
        for(int i = 0;i<pa.size();i++){
            for(int j=0;j<pb.size();j++){
                if(dis(pa[i],pb[j])==c*c){
                    ans+=1;
                    ap.push_back(i);
                    bp.push_back(j);
                }
            }
        }
        printf("%lld\n",ans);
        for(int i=0;i<ap.size();i++){
                printf("%lld %lld %lld %lld\n",pa[ap[i]].x,pa[ap[i]].y,pb[bp[i]].x,pb[bp[i]].y);
        }
    }
    

    return 0;
}
