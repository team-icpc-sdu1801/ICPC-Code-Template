#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int n;
const int N = 1000010;
int sa[N], x[N], c[N], y[N];
char s[N];
inline void SA()
{
    for (int i = 1; i <= n; ++i) x[i] = s[i];
    int m = 128;
    for (int i = 0; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) c[x[i]]++;
    for (int i = 1; i <= m; ++i) c[i] += c[i-1];
    for (int i = n; i; i--) sa[c[x[i]]--] = i;

    for (int k = 1, p; k <= n; k <<= 1){
        p = 0;
        for (int i = n; i > n - k; i--) y[++p] = i;
        for (int i = 1; i <= n; ++i)
            if(sa[i] > k) y[++p] = sa[i] - k;

        for (int i = 0; i <= m; ++i) c[i] = 0;
        for (int i = 1; i <= n; ++i) c[x[i]]++;
        for (int i = 1; i <= m; ++i) c[i] += c[i-1];
        for (int i = n; i; i--) sa[c[x[y[i]]]--] = y[i];

        p = y[sa[1]] = 1;
        for (int i = 2, a, b; i <= n; ++i){
            a = sa[i] + k > n? -1 : x[sa[i] + k];
            b = sa[i-1] + k > n?-1 : x[sa[i-1] + k];
            y[sa[i]] = (x[sa[i]] == x[sa[i-1]] && (a == b)? p : ++p);
        }
        swap(x, y);
        m = p;
        if (p == n)break;
    }
}
int height[N], rk[N], st[N][20];
inline void build_H(){
    int k = 0;
    for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (int i = 1; i <= n; ++i){
        if (rk[i] == 1) continue;
        if (k) --k;
        int j = sa[rk[i]-1];
        while(j + k <= n && i + k <= n && s[i+k]==s[j+k]) ++k;
        height[rk[i]] = k;
    }
}
inline void build_lcp(){
    for (int i = 1; i <= n; ++i)st[i][0] = height[i];
    for (int i = 1; i <= 17; ++i){
        for (int j = 1; j+(1<<i)-1 <= n; ++j)
            st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
    }
}
inline int query(int l, int r){
    int k = log2(r - l + 1);
    return max(st[l][k], st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    SA();
    build_H();
    for (int i = 1; i <= n; ++i)printf("%d ", sa[i]);
}
