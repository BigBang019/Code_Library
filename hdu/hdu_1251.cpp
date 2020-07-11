#include<bits/stdc++.h>
namespace TRIE{
    using namespace std;
    typedef long long ll;
    const int N = 1e6 + 5;
    int tot;
    struct NODE{
        int ne[26], cnt;
        void init(){
            memset(ne, -1, sizeof(ne));
            cnt = 0;
        }
    } tr[N];
    void init(){
        tot = 0;
    }
    void insert(string s){
        int now = 0;
        for (int i = 0; i < s.size();i++)
        {
            int p = s[i] - 'a';
            if (~tr[now].ne[p]){
                now = tr[now].ne[p];
            }else{
                tr[now].ne[p] = ++tot;
                now = tot;
                tr[now].init();
            }
            tr[now].cnt++;
        }
    }
    int query(string s){
        int now = 0;
        for (int i = 0; i < s.size();i++){
            int p = s[i] - 'a';
            if (~tr[now].ne[p]){
                now = tr[now].ne[p];
            }else
                return 0;
        }
        return tr[now].cnt;
    }
}
using namespace TRIE;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	tr[0].init();
	while (getline(cin,s)){
		if (s.size()==0)
			break;
		insert(s);
	}
	while (getline(cin,s)){
		cout << query(s) << endl;
	}
	return 0;
}
