#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
const int N = 10010;
char s[N];
int nxt[N];
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
