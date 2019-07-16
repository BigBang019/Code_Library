#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int ne[N * 2];
int get_min(char *s)
{
    int len = strlen(s) / 2;            //当前s为扩展过的s
    int i = 0, j = 1;
    while (i < len && j < len)
    {
        int k = 0;
        while (s[i + k] == s[j + k] && k < len)
            k++;
        if (k == len)
            break;
        if (s[i + k] < s[j + k])
        {
            if (j + k > i)
                j += k + 1;
            else
                j = i + 1;
        }
        else
        {
            if (i + k > j)
                i += k + 1;
            else
                i = j + 1;
        }
    }
    return min(i, j);
}
int get_max(char *s)
{
    int len = strlen(s) / 2;            //当前s为扩展过的s
    int i = 0, j = 1;
    while (i < len && j < len)
    {
        int k = 0;
        while (s[i + k] == s[j + k])
            k++;
        if (k == len)
            break;
        if (s[i + k] > s[j + k])
        {
            if (j + k > i)
                j += k + 1;
            else
                j = i + 1;
        }
        else
        {
            if (i + k > j)
                i += k + 1;
            else
                i = j + 1;
        }
    }
    return min(i, j);
}


void get_next(char *s){
    ne[0] = -1;
    int k = -1;
    int j = 0;
    int len = strlen(s);
    while(j<len){
        if (k==-1 || s[j]==s[k]){
            j++;
            k++;
            if (s[j]==s[k])
                ne[j] = ne[ne[k]];
            else
                ne[j] = k;
        }else
            k = ne[k];
    }
}
char s[N * 2];
int main()
{
    while (scanf("%s", s)!=EOF)
    {
        int len = strlen(s);
        get_next(s);
        int ans = len - ne[len], cnt = 1;
        for (int i = len; i < 2 * len;i++)
        {
            s[i] = s[i - len];
        }
        if (len%ans==0)
            cnt = len / ans;
        printf("%d %d %d %d\n", get_min(s) + 1, cnt, get_max(s) + 1, cnt);
    }
    return 0;
}
