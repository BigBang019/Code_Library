#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
char s[N];
int s0[N], s1[N];
int main(){
    scanf("%d", &n);
    scanf(" %s", s + 1);
    for (int i = 1; i <= n;i++)
    {
        s1[i] = s1[i - 1] + (s[i] == '1');
        s0[i] = s0[i - 1] + (s[i] == '0');
    }
    if (s1[n]!=s0[n])
        printf("1\n%s\n", s + 1);
    else {
        printf("2\n");
        printf("%c ", s[1]);
        printf("%s", s + 2);
    }
    return 0;
}
