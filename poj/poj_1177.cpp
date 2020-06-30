#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
struct LINE{
	int x1, x2, y, flag;
	LINE(int x1, int x2, int y, int flag) : x1(x1), x2(x2), y(y), flag(flag){}
	LINE(){}
	bool operator < (const LINE & b) const {
		return y < b.y;
	}
} line[N * 2];
struct NODE{
	int ac, v, l, r, le, re, numseg;//numseg记录的是竖线数的一半
	bool rc, lc;
	NODE(int l, int r, int le, int re, int ac, int v, int numseg, bool lc, bool rc) : l(l), r(r), le(le), re(re), ac(ac), v(v), numseg(numseg), lc(lc), rc(rc){}
	NODE(){}
} tree[N * 4];
int x[N * 2];
int n, m, tot;
void calc(int x){
	if (tree[x].ac>0){
		tree[x].v = tree[x].re - tree[x].le;
		tree[x].rc = tree[x].lc = 1;
		tree[x].numseg = 1;
		return;
	}
	if (tree[x].l+1==tree[x].r){
		tree[x].v = 0;
		tree[x].numseg = 0;
		tree[x].lc = tree[x].rc = 0;
	}else{
		tree[x].v = tree[x * 2].v + tree[x * 2 + 1].v;
		tree[x].lc = tree[x * 2].lc;
		tree[x].rc = tree[2 * x + 1].rc;
		tree[x].numseg = tree[x * 2].numseg + tree[x * 2 + 1].numseg;
		if (tree[x*2].rc && tree[x*2+1].lc)
			tree[x].numseg--;
	}
}
void build(int u,int l,int r){
	tree[u] = NODE(l, r, x[l], x[r], 0, 0, 0, 0, 0);
	if (l+1==r)
		return;
	int mid = l + r >> 1;
	build(2 * u, l, mid);
	build(2 * u + 1, mid, r);
}
void update(int x,int ql,int qr,int v){
	if (tree[x].le==ql && tree[x].re==qr){
		tree[x].ac += v;
		calc(x);
		return;
	}
	if (qr<=tree[x*2].re)
		update(2 * x, ql, qr, v);
	else if (ql>=tree[2*x+1].le)
		update(2 * x + 1, ql, qr, v);
	else {
		update(2 * x, ql, tree[2*x].re, v);
		update(2 * x + 1, tree[2 * x + 1].le, qr, v);
	}
	calc(x);
}
int main(){
	scanf("%d", &n);
	tot = 0;
	for (int i = 1; i <= n;i++)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x[++tot] = x1;
		line[tot] = LINE(x1, x2, y1, 1);
		x[++tot] = x2;
		line[tot] = LINE(x1, x2, y2, -1);
	}
	sort(x + 1, x + 1 + tot);
	sort(line + 1, line + tot + 1);
	m = unique(x + 1, x + 1 + tot) - x - 1;
	build(1, 1, m);
	int last = 0;
	int ans = 0;

	for (int i = 1; i < tot;i++)
	{
		int x1 = line[i].x1, x2 = line[i].x2, y = line[i].y, fl = line[i].flag;
		update(1, x1, x2, fl);
		ans += tree[1].numseg * 2 * (line[i + 1].y - y);
		ans += abs(tree[1].v - last);
		last = tree[1].v;
	}
	update(1, line[tot].x1, line[tot].x2, line[tot].flag);
	ans += abs(tree[1].v - last);
	printf("%d\n", ans);
	return 0;
}
