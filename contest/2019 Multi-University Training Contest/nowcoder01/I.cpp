#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
const int maxn=100005;

long long tree[maxn<<2];
long long lazy[maxn<<2];

void maintain(int k) {
	tree[k]=max(tree[k<<1],tree[k<<1|1]);
	return ;
}

void pushdown(int k) {
	if (lazy[k]==0) {return ;}
	tree[k<<1]+=lazy[k];
	tree[k<<1|1]+=lazy[k];
	lazy[k<<1]+=lazy[k];
	lazy[k<<1|1]+=lazy[k];
	lazy[k]=0;
	return ;
}

inline void build(int l,int r, int k) {
	lazy[k]=0;
	tree[k]=0;
	if (l>r) {
		return ;
	}
	if (l==r) {
		tree[k]=0;
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	maintain(k);
	return ;
}

inline void change(int l,int r,int cl,int cr,long long cv, int k) {
	if (l>r || r<cl || l>cr) {
		return ;
	}
	if (l>=cl && r<=cr) {
		tree[k]+=cv;
		lazy[k]+=cv;
		return ;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (mid>=cl) {
		change(l,mid,cl,cr,cv,k<<1);
	}
	if (mid+1<=cr) {
		change(mid+1, r,cl,cr,cv,k<<1|1);
	}
	maintain(k);
	return ;
}

inline void changeTo(int l,int r,int cl,long long cv, int k) {
	if (l>r) {
		return ;
	}
	if (l==r) {
		tree[k]=max(tree[k], cv);
		return ;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (cl<=mid) {
		changeTo(l,mid,cl,cv,k<<1);
	}else{
		changeTo(mid+1,r,cl,cv,k<<1|1);
	}
	maintain(k);
	return ;
}

long long query(int l,int r,int ql,int qr, int k ) {
	if (l>r || r<ql || l>qr) {
		return 0;
	}
	if (l>=ql && r<=qr) {
		return tree[k];
	}
	pushdown(k);
	int mid=(l+r)/2;
	long long res=0;
	if (mid>=ql) {
		long long tmp = query(l,mid,ql,qr,k<<1);
		res=max(tmp,res);
	}
	if (mid+1<=qr) {
		long long tmp = query(mid+1,r,ql,qr,k<<1|1);
		res=max(tmp,res);
	}
	return res;
}


struct Node {
	int x;
	int y;
	long long a;
	long long b;
} a[maxn];

bool cmp1(Node x,Node y) {
	return x.y<y.y;
}
bool cmp2(Node x,Node y) {
	if (x.x==y.x) {
		return x.y>y.y;
	}
	return x.x<y.x;
}

int normalize(int n) {
	sort(a+1,a+n+1,cmp1);
	int id=1;
	int pre=-1;
	for (int i=1;i<=n;i++) {
		if (i==1 || a[i].y!=pre) {
			id++;
			pre=a[i].y;
		}
		a[i].y=id;
	}
	sort(a+1,a+n+1,cmp2);
	return id+1;
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int i=1;i<=n;i++) {
			scanf("%d%d%lld%lld", &a[i].x, &a[i].y, &a[i].a, &a[i].b);
		}
		int tot = normalize(n);
		build(1,tot,1);
		for (int i=1;i<=n;i++) {
			long long res=query(1,tot,1,a[i].y,1)+a[i].b;
			changeTo(1,tot,a[i].y,res, 1);	
			change(1,tot,a[i].y+1,tot, a[i].b, 1);
			change(1,tot,1,a[i].y-1,a[i].a, 1);
		}
		
		printf("%lld\n", query(1,tot,1,tot,1));
	}
	return 0;
} 


/*
2
1 2 1 9
2 1 9 1
1
1 1 2 3
4
1 2 1 5
1 3 2 6
2 2 3 7
2 3 4 8

*/
