// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
list<pair<string, int>> ls;
map<string, list<pair<string, int>>::iterator > fn;
map<string, list<pair<string, int>>::iterator >::iterator mit;
list<pair<string, int>>::iterator it;
int q, m;
char s[N];
int query(string s,int v){
    mit = fn.find(s);
    if (mit==fn.end()){
        return -11;
    }else{
        it = mit->second;
        if (v==0){
            return it->second;
        }else if (v==1){
            return ((++it == ls.end()) ? -11 : it->second);
        }else{
            return (it == ls.begin() ? -11 : (--it)->second);
        }
    }
}
int update(string s,int v){
    mit = fn.find(s);
    if (mit==fn.end()){
        if (ls.size()==m){
            it = ls.begin();
            fn.erase(fn.find(it->first));
            ls.erase(it);
        }
        ls.push_back(make_pair(s, v));
        it = ls.end();
        it--;
        fn[s] = it;
        return v;
    }else{
        it = mit->second;
        v = it->second;
        ls.push_back(make_pair(it->first, it->second));
        ls.erase(it);
        it = ls.end();
        it--;
        fn[s] = it;
        return v;
    }
}
void work(){
    ls.clear();
    fn.clear();
    scanf("%d%d", &q, &m);
    for (int i = 1; i <= q;i++)
    {
        int op, v;
        scanf("%d %s %d", &op, s, &v);
        if (op==0){
            printf("%d\n", update(s, v));
        }else{
            int tmp = query(s, v);
            if (tmp!=-11)
                printf("%d\n", tmp);
            else
                printf("Invalid\n");
        }
    }
}
int main(){
    int t;
    for (scanf("%d", &t); t;t--)
    {
        work();
    }
    return 0;
}
