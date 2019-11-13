//本质不同回文串数量 cnt[i] - 2;

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
const int N = 300010;
struct Pam{
    int len;
    int nxt[30];
    int fail;
}st[N];
int n, tot, last;
int S[N], cnt[N], num[N];
inline int newnode(int x){
    memset(st[tot].nxt, 0, sizeof(st[tot].nxt));
    cnt[tot] = 0, st[tot].len = x, num[tot] = 0;
    return tot++;
}
inline void pam_init(){
    tot = n = last = 0, newnode(0), newnode(-1);
    S[0] = - 1, st[0].fail = 1;
}
inline int get_fail(int x){
    while(S[n-st[x].len-1] != S[n]) x = st[x].fail;
    return x;
}
inline int insert(int c){
    S[++n] = c;
    int cur = get_fail(last);
    if (!st[cur].nxt[c]){
        int now = newnode(st[cur].len + 2);
        st[now].fail = st[get_fail(st[cur].fail)].nxt[c];
        st[cur].nxt[c] = now;
        num[now] = num[st[now].fail] + 1;
    }
    last = st[cur].nxt[c];
    cnt[last]++;
    return num[last];
}
inline void count(){
    for (int i = tot - 1; i >= 0; --i) cnt[st[i].fail] += cnt[i];
}
char s[N];
int main()
{
    pam_init();
    scanf("%s", s+1);
    int len = strlen(s + 1);
    long long ans = 0;
    for (int i = 1; i <= len; ++i) insert(s[i] - 'a' + 1);
    count();
    for (int i = 1; i < tot; ++i) ans = max(ans, 1ll * st[i].len * cnt[i]);
    printf("%lld\n", ans);
}