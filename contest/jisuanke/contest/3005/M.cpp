#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2000010;

char ch1[maxn];
char ch2[maxn];
int next[maxn];
int p[30];

inline void init() {
	int n=strlen(ch1);
	for (int i=0;i<=25;i++) {
		p[i]=-1;
	}
	for (int i=n-1;i>=0;i--) {
		next[i]=p[ch1[i]-'a'];
		p[ch1[i]-'a']=i;
	}
	
//	for (int i=0;i<=3;i++) {
//		printf("%d ", next[i]);
//	}printf("\n");
	
	return ;
}

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	scanf("%s", ch1);
	scanf("%s", ch2);
	init();
	int ans=-1;
	int l=-1;
	ch2[m]='a'-1;
	for (int i=0;i<=m;i++) {
		int now=ch2[i]-'a';
		for (int j=now+1;j<=25;j++) {
			while (p[j]!=-1 && p[j]<=l) {
				p[j]=next[p[j]];
			}
			if (p[j]==-1) {
				continue;
			}
			if (ans<i+n-p[j]) {
//				printf(":: i %d j %d pj %d l %d\n", i,j, p[j],l);
				ans=i+n-p[j];
			}
		}
//		for (int i=0;i<=3;i++) {
//			printf("%d ", p[i]);
//		}printf("\n");
		while (p[now]!=-1 && p[now]<=l) {
			p[now]=next[p[now]];
		}
		l=p[now];
		if (l==-1) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
