#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 2010
using namespace std;
struct Line{
	int f;//f记录上(f=-1)还是下(f=1)
	double l,r,h;
}line[10*maxn];
struct T{
	int ac;//ac记录当前节点是否全覆盖,cnt记录当前实实在在的覆盖长度
	double l,r,cnt1,cnt2;
	bool f;//f记录是否根节点 
}tree[100*maxn];
bool cmp(Line x,Line y){
	return x.h<y.h;
}
Line tmp;
double x[maxn],x1,x2,y1,y2;
int n,t,times;
double ans;
void build(int v,int l,int r){
	tree[v].ac=tree[v].cnt1=tree[v].cnt2=0;
	tree[v].l=x[l];
	tree[v].r=x[r];
	tree[v].f=0;
	if (l+1==r){
		tree[v].f=1;
		return;
	}
	int mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid,r);
}
void calc(int v){
	if (tree[v].ac>=2){
		tree[v].cnt1=tree[v].cnt2=tree[v].r-tree[v].l;
		return;
	}
	else if (tree[v].ac>=1){
		tree[v].cnt1=tree[v].r-tree[v].l;
		if (tree[v].f) tree[v].cnt2=0;//只被覆盖一次且没有左右孩子,覆盖两次的长度为0; 
		else tree[v].cnt2=tree[v*2].cnt1+tree[v*2+1].cnt1;//因为覆盖过一次,覆盖两次的长度为左右孩子覆盖一次的长度,且因为tree[v].cnt1>=tree[v].cnt2;
	}
	else {
		if (tree[v].f){
			tree[v].cnt1=tree[v].cnt2=0;
		}
		else {
			tree[v].cnt1=tree[v*2].cnt1+tree[2*v+1].cnt1;
			tree[v].cnt2=tree[v*2].cnt2+tree[2*v+1].cnt2;
		}
	}
}
void update(int v,Line e){
	if (e.l==tree[v].l&& e.r==tree[v].r){
		tree[v].ac+=e.f;
		calc(v);
		return;
	}
	if (e.r<=tree[v*2].r) update(v*2,e);
	else if (e.l>=tree[v*2].r) update(v*2+1,e);
	else{
		tmp=e;
		tmp.r=tree[2*v].r;
		update(v*2,tmp);
		tmp=e;
		tmp.l=tree[2*v].r;
		update(v*2+1,tmp);
	}
	calc(v);
}
int main(){
	scanf("%d",&times);
	while(times--){
		scanf("%d",&n);
		//memset(line,0,sizeof(line));
		//memset(x,0,sizeof(line));
		t=0;
		for (int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			t++;
			x[t]=x1;
			line[t].l=x1;
			line[t].r=x2;
			line[t].h=y1;
			line[t].f=1;
			t++;
			x[t]=x2;
			line[t].l=x1;
			line[t].r=x2;
			line[t].h=y2;
			line[t].f=-1;
		}
		sort(x+1,x+t+1);
		sort(line+1,line+t+1,cmp);
		build(1,1,t);
		update(1,line[1]);
		ans=0;
		for (int i=2;i<=t;i++){
			ans+=tree[1].cnt2*(line[i].h-line[i-1].h);
			update(1,line[i]);
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
