#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll Rm, R, r, x, y, vx, vy;
    while (~scanf("%lld%lld%lld%lld%lld%lld%lld", &Rm, &R, &r, &x, &y, &vx, &vy))
    {
        if (vx * x + vy * y > 0)
        {
            printf("0.000\n");
            continue;
        }
        // else if (vx == 0 && vy == 0)
        // {
        //     printf("0.000\n");
        //     continue;
        // }
        else
        {
            ll chang = x * x + y * y;
            ll a = vx * vx + vy * vy;
            ll b = 2 * x * vx + 2 * y * vy;
            ll c = chang - (r + Rm) * (r + Rm);
            double ans = 0;
            ll cp = chang - (R + r) * (R + r);
            if (b * b - 4 * a * c < 0)
            {
                if (b * b - 4 * a * cp < 0)
                {
                    printf("0.000\n");
                    continue;
                }
                else
                    ans = sqrt(b * b - 4 * a * cp) / (double)a;
            }
            else
            {
                double fs = (-sqrt(b * b - 4 * a * cp) - b) / (2.0 * (double)a);
                double ts = (-sqrt(b * b - 4 * a * c) - b) / (2.0 * (double)a);
                ans = 2.0 * (ts - fs);
            }
            printf("%.3lf\n", ans);
        }
    }
    return 0;
}
