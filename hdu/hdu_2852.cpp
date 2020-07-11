#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Q{
    int p, a, k;
    Q(){}
    Q(int p, int a, int k) : p(p), a(a), k(k){}
} qu[N];
int c[N], b[N];
int n, m, cnt;

void init(){
    cnt = 0;
    memset(c, 0, sizeof(c));
}
void Init_Hash(){
    sort(b + 1, b + 1 + cnt);
    m = unique(b + 1, b + 1 + cnt) - b - 1;
}
int lowbit(int x){
    return x & (-x);
}
void add(int x,int v){
    for (int i = x; i <= m;i+=lowbit(i))
    {
        c[i] += v;
    }
}
int query(int x){
    int sum = 0;
    for (int i = x; i > 0;i-=lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}
int has(int x){
    return lower_bound(b + 1, b + 1 + m, x) - b;
}
int main(){
    while (~scanf("%d",&n)){
        init();
        for (int i = 1; i <= n;i++)
        {
            int p, e, k=-1;
            scanf("%d%d", &p, &e);
            if (p == 2)
            {
                scanf("%d", &k);
            }
            qu[i] = Q(p, e, k);
            b[++cnt] = e;
        }
        Init_Hash();
        for (int i = 1; i <= n;i++)
        {
            int p = qu[i].p;
            int a = has(qu[i].a);
            int k = qu[i].k;
            if (p==0){
                add(a, 1);
            }else if (p==1){
                int tmp = query(a) - query(a - 1);
                if (tmp==0)
                    printf("No Elment!\n");
                else
                    add(a, -1);
            }else{
                int l = 1, r = m;
                bool flag = 0;
                while (l<=r){
                    int mid = l + r >> 1;
                    int tmp = query(mid) - query(a);
                    int len = query(mid) - query(mid - 1);
                    if (tmp-len<k && tmp>=k && len) {
                        printf("%d\n", b[mid]);
                        flag = 1;
                        break;
                    }
                    if (tmp<k){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
                if (!flag)
                    printf("Not Find!\n");
            }
        }
    }
    return 0;
}
