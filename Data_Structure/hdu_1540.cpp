#include<bits/stdc++.h>
const int N = 5e4 + 10;
const int M = 4e5 + 5;
const int BIGG = 105;
using namespace std;
struct STA{
	int a[N];
	int h;
	void init(){
		h=-1;
	}
	void push(int c){
		a[++h]=c;
	}
	int pop(){
		return a[h--];
	}
	int top(){
		return a[h];
	}
	bool empty(){
		return (h==-1);
	}
}sta;
struct node
{
    int l,r;
    int ls,rs,ms;//ls,????????,rs????????,ms?????????
} a[N<<2];
int n,m;
void up(int u){
    int lc=2*u,rc=2*u+1;
    a[u].ms=max(a[rc].ls+a[lc].rs,max(a[lc].ms,a[rc].ms));
    a[u].ls=a[lc].ls + (a[lc].ms==(a[lc].r-a[lc].l+1)? a[rc].ls:0); 
    a[u].rs=a[rc].rs + (a[rc].ms==(a[rc].r-a[rc].l+1)? a[lc].rs:0);
    
}
void build(int u,int l,int r){
	a[u].l=l; a[u].r=r;
	if (l==r){
		a[u].ms=a[u].ls=a[u].rs=1;
		return;
	}
	int mid=l+r>>1;
	build(2*u,l,mid);
	build(2*u+1,mid+1,r);
	up(u);
}

void insert(int i,int t,int x)
{
    if(a[i].l == a[i].r)
    {
        if(x==1)
            a[i].ls = a[i].rs = a[i].ms = 1;//??
        else
            a[i].ls = a[i].rs = a[i].ms = 0;//??
        return ;
    }
    int mid = (a[i].l+a[i].r)>>1;
    if(t<=mid)
        insert(2*i,t,x);
    else
        insert(2*i+1,t,x);
    up(i);
}
 
int query(int i,int t)
{
    if(a[i].l == a[i].r || a[i].ms == 0 || a[i].ms == a[i].r-a[i].l+1)
        return a[i].ms;
    int mid = (a[i].l+a[i].r)>>1;
    if(t<=mid)
    {
        if(t>=a[2*i].r-a[2*i].rs+1)
            return query(2*i,t)+query(2*i+1,mid+1);
        else
            return query(2*i,t);
    }
    else
    {
        if(t<=a[2*i+1].l+a[2*i+1].ls-1)//??
            return query(2*i+1,t)+query(2*i,mid);
        else
            return query(2*i+1,t);
    }
}
char ch[2];
void init(){
	sta.init();
}
int main(){
	int x;
    while(~scanf("%d%d",&n,&m)){
    	build(1,1,n);
    	for (int i=1;i<=m;i++){
    	    scanf(" %s",ch);
	        if (ch[0]=='D'){
	        	scanf("%d",&x);
	        	sta.push(x);
	        	insert(1,x,0);
	        }else if (ch[0]=='Q'){
	        	scanf("%d",&x);
	        	printf("%d\n",query(1,x));
	        }else{
	        		x=sta.pop();
	        		insert(1,x,1);
	        }
	    }
    }
}
