// 求字典序第k大子串，T为0则表示不同位置的相同子串算作一个。T=1则表示不同位置的相同子串算作多个
// T＝0时，跑一个后缀自动机上的dp，求不同子串个数，相当于求路径数目，然后然后在树上一个一个点的找就可以了。
// T＝1时，现求一个子串出现次数，做法是按照后缀链接跑树形dp，字符串上的点赋值为1，克隆出的点初值为0，跑完dp后在按照第一种方法做一下就可以
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1000010;
struct state{
    int len, link;
    int nxt[27];
}st[N];
int n, sz, T, last;
long long k;
char s[N];
int c[N], q[N];
long long dp[N], cnt[N];
inline void sam_init(){
    sz = last = 1;
}
inline void sam_extend(int c){
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    int p = last;
    while(p && !st[p].nxt[c]){
        st[p].nxt[c] = cur;
        p = st[p].link;
    }
    if (!p) st[cur].link = 1;
    else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len){
            st[cur].link = q;
        } else {
            int clone = ++sz;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
            st[clone].link = st[q].link;
            while(p && st[p].nxt[c] == q){
                st[p].nxt[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
inline void sam(){
    long long now = 0;
    int p = 1;
    while(1){
        for (int i = 1; i <= 26; ++i){
            if (now + dp[st[p].nxt[i]] < k)
                now += dp[st[p].nxt[i]];
            else {
                putchar('a' + i - 1);
                now += cnt[st[p].nxt[i]];
                if (now >= k) return;
                p = st[p].nxt[i];
                break;
            }
        }
    }
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    sam_init();
    for (int i = 1; i <= n; ++i)
        sam_extend(s[i] - 'a' + 1);
    for (int i = 1; i <= sz; ++i) c[st[i].len]++;
    for (int i = 1; i <= n; ++i) c[i] += c[i-1];
    for (int i = sz; i; i--) q[c[st[i].len]--] = i;
    scanf("%d%lld", &T, &k);
    if (!T){
        for (int i = 1; i <= sz; ++i) cnt[i] = 1;
    } else {
        int p = 1;
        for (int i = 1; i <= n; ++i){
            int x = s[i] - 'a' + 1;
            p = st[p].nxt[x];
            cnt[p] = 1;
        }
        for (int i = sz; i >= 1; --i){
            p = q[i];
            cnt[st[p].link] += cnt[p];
        }
    }
    for (int i = sz; i >= 1; --i){
        int p = q[i];
        if (p != 1) dp[p] = cnt[p];
        for (int j = 1; j <= 26; ++j)
            dp[p] += dp[st[p].nxt[j]];
    }
    if (k > dp[1])puts("-1");
    else sam();
}

