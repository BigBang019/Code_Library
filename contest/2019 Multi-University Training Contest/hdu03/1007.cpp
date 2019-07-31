#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10;
int a[N][N];
vector<int> b;
void work(){
    b.clear();
    int dis = 0;
    for (int i = 1; i <= 4;i++)
    {
        for (int j = 1; j <= 4;j++)
        {
            scanf("%d", &a[i][j]);
            b.push_back(a[i][j] == 0 ? 16 : a[i][j]);
            if (a[i][j]==0){
                dis = abs(4 - i) + abs(4 - j);
            }
        }
    }
    int inv = 0;
    for (int i = 0; i < b.size();i++)
    {
        for (int j = i + 1; j < b.size();j++)
        {
            if (b[i]>b[j]){
                inv++;
            }
        }
    }
    if ((inv&1)==(dis&1)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        work();
    }
    return 0;
}
