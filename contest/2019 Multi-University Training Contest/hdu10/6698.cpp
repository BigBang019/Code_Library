#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std;
typedef long long ll;
const int maxn=100005;
struct bigger{
    int add,id;
    bigger(int add,int id):add(add),id(id){}
    bool operator < (const bigger &a)const{
        return add<a.add;
    }
};
struct smaller{
    int sub,id;
    smaller(int sub,int id):sub(sub),id(id){}
    bool operator < (const smaller &a)const{
        return sub>a.sub;
    }
};
priority_queue<bigger> ze_to_one,ze_to_two,one_to_two;
priority_queue<smaller> one_to_ze,two_to_one;
int n,fi[maxn],se[maxn],ans,num[maxn];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        while(!ze_to_one.empty()) ze_to_one.pop();
        while(!ze_to_two.empty()) ze_to_two.pop();
        while(!one_to_two.empty()) one_to_two.pop();
        while(!one_to_ze.empty()) one_to_ze.pop();
        while(!two_to_one.empty()) two_to_one.pop();
        scanf("%d",&n);
        ans=0;
        rep(i,1,n){
            scanf("%d%d",&fi[i],&se[i]);
            ze_to_one.push(bigger(fi[i],i));
            ze_to_two.push(bigger(fi[i]+se[i],i));
            num[i]=0;
        }
        rep(i,1,2*n){
            int maxx=-1,ty=-1;
            while(!ze_to_one.empty()) {
                if(num[ze_to_one.top().id]!=0) {
                    ze_to_one.pop(); continue;
                }
                bigger tmp=ze_to_one.top();
                if(maxx<tmp.add){
                    maxx=tmp.add; ty=1; break;
                }
                break;
            }
            while(!one_to_two.empty()) {
                if(num[one_to_two.top().id]!=1) {
                    one_to_two.pop(); continue;
                }
                bigger tmp=one_to_two.top();
                if(maxx<tmp.add){
                    maxx=tmp.add; ty=2;
                }
                break;
            }
            while(!one_to_ze.empty()&&!ze_to_two.empty()){
                if(num[ze_to_two.top().id]!=0) {
                    ze_to_two.pop(); continue;
                }
                if(num[one_to_ze.top().id]!=1) {
                    one_to_ze.pop(); continue;
                }
                bigger tmp1=ze_to_two.top();
                smaller tmp2=one_to_ze.top();
                if(maxx<tmp1.add-tmp2.sub){
                    maxx=tmp1.add-tmp2.sub;
                    ty=3;
                }
                break;
            }
            while(!two_to_one.empty()&&!ze_to_two.empty()){
                if(num[two_to_one.top().id]!=2) {
                    two_to_one.pop(); continue;
                }
                if(num[ze_to_two.top().id]!=0) {
                    ze_to_two.pop(); continue;
                }
                bigger tmp1=ze_to_two.top();
                smaller tmp2=two_to_one.top();
                if(maxx<tmp1.add-tmp2.sub){
                    maxx=tmp1.add-tmp2.sub;
                    ty=4;
                }
                break;
            }
            if(ty==1){
                bigger tmp=ze_to_one.top(); ze_to_one.pop();
                ans+=tmp.add; num[tmp.id]=1;
                one_to_two.push(bigger(se[tmp.id],tmp.id));
                one_to_ze.push(smaller(fi[tmp.id],tmp.id));
            }
            if(ty==2){
                bigger tmp=one_to_two.top(); one_to_two.pop();
                ans+=tmp.add;  num[tmp.id]=2;
                two_to_one.push(smaller(se[tmp.id],tmp.id));
            }
            if(ty==3){
                bigger tmp1=ze_to_two.top(); ze_to_two.pop();
                smaller tmp2=one_to_ze.top(); one_to_ze.pop();
                int d1=tmp1.id,d2=tmp2.id;
                ans+=maxx; num[d1]=2; num[d2]=0;
                two_to_one.push(smaller(se[d1],d1));
                ze_to_one.push(bigger(fi[d2],d2));
                ze_to_two.push(bigger(fi[d2]+se[d2],d2));

            }
            if(ty==4){
                bigger tmp1=ze_to_two.top(); ze_to_two.pop();
                smaller tmp2=two_to_one.top(); two_to_one.pop();
                int d1=tmp1.id,d2=tmp2.id;
                ans+=maxx; num[d1]=2,num[d2]=1;
                one_to_two.push(bigger(se[d2],d2));
                one_to_ze.push(smaller(fi[d2],d2));
                two_to_one.push(smaller(se[d1],d1));
            }
            printf("%d%c",ans,i==2*n?'\n':' ');
        }
    }
    return 0;
}

