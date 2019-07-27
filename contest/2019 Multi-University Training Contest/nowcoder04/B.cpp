// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
const int N = 5e4 + 5;
const int B = 31;
struct Base{
    uint b[B + 3];
    Base() { init(); }
    uint &operator [] (uint i) {
        return b[i];
    }
    void init() { memset(b, 0, sizeof(b)); }
    void update(uint x){
        for (int i = B; ~i && x; i--) if (x&(uint(1)<<i)){
            if (!b[i]){
                b[i] = x;
                break;
            }
            x ^= b[i];
        }
    }
    bool check(uint x){
        for (int i = B; ~i && x; i--) if (x&(uint(1)<<i)){
            if (!b[i]){
                break;
            }
            x ^= b[i];
        }
        return (x == 0);
    }
    static Base Merge(Base a, Base b){
        Base c, tmp_b, tmp_k;
        for (int i = 0; i <= B; i++)
        {
            tmp_b[i] = tmp_k[i] = 0;
            if (a[i]) tmp_b[i] = a[i];
        }
        for (int i = 0; i <= B; i++) c[i] = 0;
        for (int i = 0; i <= B; i++) if (b[i])
        {
            int ok = 1;
            uint v = b[i], k = 0;
            for (int j = B; ~j; j--)
            {
                if (v & (uint(1) << j)){
                    if (tmp_b[j]){
                        v ^= tmp_b[j];
                        k ^= tmp_k[j];
                    }else{
                        tmp_b[j] = v;
                        tmp_k[j] = (uint(1) << i) ^ k;
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok){
                uint v = b[i];
                for (int j = 0; j <= B; j++)
                {
                    if (k & (uint(1) << j))
                    {
                        v ^= b[j];
                    }
                }
                for (int j = B; ~j; j--)
                {
                    if (v & (uint(1) << j)){
                        if (c[j]){
                            v ^= c[j];
                        }else{
                            c[j] = v;
                            break;
                        }
                    }
                }
            }
        }
        return c;
    }
} tree[N << 2];
void up(int x){
    tree[x] = Base::Merge(tree[x << 1], tree[x << 1 | 1]);
}
void build(int x,int l,int r){
    if (l==r){
        int sz;
        scanf("%d", &sz);
        while (sz--){
            uint v; scanf("%u", &v);
            tree[x].update(v);
        }
        return;
    }
    int mid = l + r >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    up(x);
}
bool query(int x,int l,int r,int ql,int qr,int v){
    if (ql>r || qr<l) return 1;
    if (ql<=l && qr>=r){
        return tree[x].check(v);
    }
    int mid = l + r >> 1;
    return query(2 * x, l, mid, ql, qr, v) && query(2 * x + 1, mid + 1, r, ql, qr, v);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--){
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        printf("%s\n", query(1, 1, n, l, r, v) ? "YES" : "NO");
    }
    return 0;
}
