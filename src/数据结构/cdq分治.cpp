#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100010, maxm = 200010;
int n, k, ct, ans[maxn], res[maxn], cnt;
struct node{
    int a, b, c, id, sz;
    bool operator < (const node &t) const{
        if(a == t.a){
            if(b == t.b){
                return c < t.c;
            }else return b < t.b;
        }else return a < t.a;
    }
    bool operator == (const node &t)const{return a == t.a && b == t.b && c == t.c;}
}q[maxn], qq[maxn];
bool cmp(node a, node b){return a.b < b.b;}
 
int s[maxm];
int lowbit(int x){return x&(-x);}
void update(int x, int v){for(int i = x; i <= k; i += lowbit(i)) s[i] += v;}
int sum(int x){int res = 0; for(int i = x; i; i -= lowbit(i)) res += s[i]; return res;}
 
void Solve(int l, int r){
    if(l == r) return;
    int mid = (l+r) >> 1;
    Solve(l, mid), Solve(mid+1, r);
    int i = l, j = mid+1, last = 0;
    while(j <= r){
        while(i <= mid && q[i].b <= q[j].b) update(q[i].c, q[i].sz), last = i ++;
        ans[q[j].id] += sum(q[j].c), j ++;
    }
    for(int i = l; i <= last; i ++) update(q[i].c, -q[i].sz);
    merge(q+l, q+mid+1, q+mid+1, q+r+1, qq+l, cmp);
    for(int i = l; i <= r; i ++) q[i] = qq[i];
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
    }
    sort(q+1, q+1+n);
    node t = q[1]; qq[++ ct] = q[1], qq[ct].sz = 1;
    for(int i = 2; i <= n; i ++){
        if(q[i] == t) qq[ct].sz ++;
        else t = q[i], qq[++ ct] = q[i], qq[ct].sz = 1, qq[ct].id = ++ cnt;
    }
    for(int i = 1; i <= ct; i ++) q[i] = qq[i];
    Solve(1, ct);
    for(int i = 1; i <= ct; i ++) res[ans[q[i].id] + (q[i].sz-1)] += q[i].sz;
    for(int i = 0; i < n; i ++) printf("%d\n", res[i]);
    return 0;
}

