#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
const int N = 10010;
char s[N];
int nxt[N];
//求 t 在 s 中是否出现，需要t的nxt数组 
inline int check(char *s, int sl, char *t, int tl, int *nxt){
	int l = 0;
	for (int i = 1; i <= sl; ++i){
		while(l && s[i] != t[l + 1]) l = nxt[l];
		if (s[i] == t[l + 1]) l++;
		if (l == tl) return 1;
	}
	return 0;
}
int main(){
    scanf("%s", s + 1);
    int p = 0, n = strlen(s + 1);
    for (int i = 2; i <= n; ++i){
        while(p && s[p + 1] != s[i]) p = nxt[p];
        if (s[p + 1] == s[i]) p++;
        nxt[i] = p;
    }
    for (int i = 1; i <= n; ++i)
    printf("%d ", nxt[i]);
}
