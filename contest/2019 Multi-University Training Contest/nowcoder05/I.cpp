// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
const int N = 5e3 + 5;
const double eps = 9e-7;
int w, h, a, b, c;
pair<double, double> p[3];
bool check(int a, int b, int c)
{
    double beta = acos((double)(a * a + c * c - b * b) / (2 * a * c));
    double alpha = max(a > w ? acos((double)(w) / a) : 0.0, c > w ? acos((double)(w) / c) - beta : 0.0);
    p[0].fi = a * cos(alpha), p[0].sc = a * sin(alpha);
    p[1].fi = p[1].sc = 0.0;
    p[2].fi = c * cos(alpha + beta), p[2].sc = c * sin(alpha + beta);
    return (p[2].fi >= -eps && p[2].sc <= h + eps && p[0].fi >= -eps && p[0].sc <= h + eps);
}
int main(){
    int _;
    for (scanf("%d", &_); _; _--)
    {
        scanf("%d%d%d%d%d", &w, &h, &a, &b, &c);
        int fl;
        for (fl = 0; fl < 2;fl++)
        {
            if (check(a, b, c)){
                break;
            }
            if (check(a, c, b)){
                swap(p[0], p[1]);
                break;
            }
            if (check(b, a, c)){
                swap(p[1], p[2]);
                break;
            }
            if (check(b, c, a)){
                pair<double, double> tmp = p[0];
                p[0] = p[1];
                p[1] = p[2];
                p[2] = tmp;
                break;
            }
            if (check(c, a, b)){
                pair<double, double> tmp = p[1];
                p[1] = p[0];
                p[0] = p[2];
                p[2] = tmp;
                break;
            }
            if (check(c, b, a)){
                swap(p[0], p[2]);
                break;
            }
            swap(w, h);
        }
        if (fl){
            for (int i = 0; i < 3;i++)
            {
                swap(p[i].fi, p[i].sc);
            }
        }
        for (int i = 0; i < 3;i++)
        {
            printf("%.9f %.9f%c", p[i].fi, p[i].sc, i == 2 ? '\n' : ' ');
        }
    }
    return 0;
}
