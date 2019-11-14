#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define mid ((l+r)>>1)
const int maxn = 10010, MX = 1e9;
int n, m, cnt, sz1, sz2, val[maxn]; 
struct node{
    int val;
    node *ch[2];
}pool[maxn*900], *root[maxn], *null, *A[maxn], *B[maxn];
int lowbit(int x){return x&(-x);}
node *get(){
    node *now = &pool[++cnt];
    now->val = 0, now->ch[0] = now->ch[1] = null;
    return now;
}
void add(node *now, int l, int r, int pos, int v){
    if(l == r) return;
    int wh = 0; if(pos >= mid+1) wh = 1;
    if(now->ch[wh] == null) now->ch[wh] = get();
    now->ch[wh]->val += v;
    add(now->ch[wh], wh==0?l:mid+1, wh==0?mid:r, pos, v);
}
void update(int x, int val, int v){
    for( ; x <= n; x += lowbit(x)){
        if(root[x] == NULL) root[x] = get();
        add(root[x], 0, MX, val, v);
    }
    return;
}
void que(node *fi[], node *se[], int l, int r, int k){
    if(l == r){printf("%d\n", l); return;}
    int lv = 0;
    for(int i = 1; i <= sz1; i ++) lv -= fi[i]->ch[0]->val;
    for(int i = 1; i <= sz2; i ++) lv += se[i]->ch[0]->val;
    if(k <= lv){
        for(int i = 1; i <= sz1; i ++) fi[i] = fi[i]->ch[0];
        for(int i = 1; i <= sz2; i ++) se[i] = se[i]->ch[0];
        que(fi, se, l, mid, k);
    }else{
        for(int i = 1; i <= sz1; i ++) fi[i] = fi[i]->ch[1];
        for(int i = 1; i <= sz2; i ++) se[i] = se[i]->ch[1];
        que(fi, se, mid+1, r, k - lv);
    }
}
void GetRoot(int x, node *C[], int &sz){
    for( ; x >= 1; x -= lowbit(x)){
        C[++sz] = root[x];
    }
}
int main(){
    null = pool;
    null->val = 0, null->ch[0] = null->ch[1] = null;
    root[0] = get();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &val[i]);
        update(i, val[i], 1);
    }
    for(int i = 1, a, l, r, k; i <= m; i ++){
        char ch[5];
        scanf("%s", ch+1);
        if(ch[1] == 'Q'){
            sz1 = sz2 = 0;
            scanf("%d%d%d", &l, &r, &k);
            GetRoot(l-1, A, sz1);
            GetRoot(r, B, sz2);
            que(A, B, 0, MX, k);
        }else{
            scanf("%d%d", &a, &k);
            update(a, val[a], -1);
            update(a, k, 1);
            val[a] = k;
        }
    }
    return 0;
} 
