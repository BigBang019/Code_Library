// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second;
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
int n, I;
int a[N];
vector<int> b;
void Init_Hash(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int has(int x){
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
int sum[N];
int main(){
    // freopen("E:\\vscode\\c++\\in.txt", "r", stdin);
    // freopen("E:\\vscode\\c++\\out.txt", "w", stdout);
    cin >> n >> I;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }
    Init_Hash();
    int kind = b.size();
    for (int i = 1; i <= n; i++)
    {
        sum[has(a[i])]++;
    }
    for (int i = 1; i <= kind;i++)
    {
        sum[i] += sum[i - 1];
    }
    int k = 0;
    while (n * (k + 1) <= 8 * I)
    {
        if ((1 << (k + 1)) >= kind){
            cout << 0 << endl;
            return 0;
        }
        k++;
    }
    int len = (1 << k);
    int ans = n;
    for (int l = 1; l <= kind;l++)
    {
        int r = l + len - 1;
        if (r>kind)
            break;
        int now = sum[r] - sum[l - 1];
        ans = min(ans, n - now);
    }
    // cout << "!!" << endl;
    cout << ans << endl;
    // fclose(stdout);
    // fclose(stdin);
    return 0;
}
