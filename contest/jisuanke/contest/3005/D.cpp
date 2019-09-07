#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000000;

char ch1[maxn];
char ch2[maxn];
int len1;
int len2;
int next1[maxn];
int next2[maxn];

inline void getAdvancedNext1() {
    int i=0;
    int j=-1;
    next1[0]=-1;
    while (i<len1) {
        if (j==-1 || ch1[i]==ch1[j]) {
            i++;
            j++;
            if (ch1[i]==ch1[j]) {
                next1[i]=next1[j];
            } else {
                next1[i]=j;
            }
        } else {
            j=next1[j];
        }
    }
}

inline void getAdvancedNext2() {
    int i=0;
    int j=-1;
    next2[0]=-1;
    while (i<len2) {
        if (j==-1 || ch2[i]==ch2[j]) {
            i++;
            j++;
            if (ch2[i]==ch2[j]) {
                next2[i]=next2[j];
            } else {
                next2[i]=j;
            }
        } else {
            j=next2[j];
        }
    }
}

bool kmp1() { //1 shorter 
	int i=0;
	int j=0;
	while (i<len2 && j<len1) {
		if (j==-1 || ch2[i]==ch1[j]) {
			j++;
			i++;
		} else {
			j=next1[j];
		}
	}
	if (j==len1) {
		return true;
	} else {
		return false;
	}
}

bool kmp2() { //2 shorter 
	int i=0;
	int j=0;
	while (i<len1 && j<len2) {
		if (j==-1 || ch1[i]==ch2[j]) {
			j++;
			i++;
		} else {
			j=next2[j];
		}
	}
	if (j==len2) {
		return true;
	} else {
		return false;
	}
}

int main() {
	scanf("%s", &ch1);
	len1=strlen(ch1);
	int q;
	scanf("%d", &q);
	getAdvancedNext1();
	while (q--) {
		memset(ch2,0,sizeof(ch2));
		scanf("%s", ch2);
		len2=strlen(ch2);
		if (len1>len2) {
			getAdvancedNext2();
			if (kmp2()) {
				printf("my child!\n");
			} else {
				printf("oh, child!\n");
			}
		} else if (len1<len2) {
			if (kmp1()) {
				printf("my teacher!\n");
			} else {
				printf("senior!\n");
			}
		} else {
			bool pd=true;
			for (int i=0;i<len1;i++) {
				if (ch1[i]!=ch2[i]) {
					pd=false;
					break;
				}
			}
			if (pd) {
				printf("jntm!\n");
			} else {
				printf("friend!\n");
			}
		}
	}
	return 0;
}
