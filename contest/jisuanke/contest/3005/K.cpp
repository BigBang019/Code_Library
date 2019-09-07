#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
pair<int,int> arr[1010];
map<pii,int> mp;
int main() {
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        pii ac;ac.first=2*x; ac.second=2*y;
        arr[i]=ac;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x=(arr[i].first+arr[j].first)/2;
            int y=(arr[i].second+arr[j].second)/2;
            pii tp; tp.first=x; tp.second=y;
            mp[tp]++;
        }
    }
    int maxt=0;
    for(auto it=mp.begin();it!=mp.end();++it){
        maxt=max(maxt,it->second);
    }
    printf("%d",n-maxt);
    return 0;
}
