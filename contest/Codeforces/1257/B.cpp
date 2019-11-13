#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        string msg;
        if (a == 1)
        {
            msg = (b == 1 ? "YES" : "NO");
        }else if (a==2 || a==3){
            msg = (b == 3 || b == 2 || b == 1 ? "YES" : "NO");
        }else {
            msg = "YES";
        }
        puts(msg.c_str());
    }
 
    return 0;
}
