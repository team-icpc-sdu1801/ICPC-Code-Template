#include <bits/stdc++.h>

#define mem(x, v) memset(x, v, sizeof(x))

using namespace std;

typedef long long ll;
typedef long long T;
const int maxn = 250010;
const int inf = ~0u >> 1u;
//const ll inf = ~0llu >> 1u;

struct gra {
    int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt;
    T f[maxn << 1];
    void clear(int n) {fill(head, head+1+n, 0), cnt = 0;}
    void add(int a, int b, T c) {nxt[++cnt] = head[a], to[head[a] = cnt] = b, f[cnt] = c;}
};

const int LOGSZ = 18;

struct StLca : public gra{
    T d[maxn][LOGSZ+1], up[maxn][LOGSZ+1];
    int dep[maxn], n, R;
    static int dfn[maxn], dct; // 维护dfs序
    void init(int N, int root, const T *v = nullptr){
        n = N, dct = 0, R = root, mem(up[R], 0), dep[R] = 1, clear(n);
        if(v != nullptr) for(int i = 1; i <= n; i ++) d[i][0] = v[i];
    }
    void CalcLca(){ dfs(R);}
    void dfs(int x){
        dfn[x] = ++ dct;
        for(int i = 1; i <= LOGSZ; i ++){
            up[x][i] = up[up[x][i-1]][i-1];
            d[x][i] = min(d[x][i-1], d[up[x][i-1]][i-1]);
        }
        for(int i = head[x]; i; i = nxt[i]){
            int u = to[i]; if(u == up[x][0]) continue;
            dep[u] = dep[x] + 1, up[u][0] = x;
            d[u][0] = f[i], dfs(u);
        }
    }
    int lca(int x, int y){
        if(x == y) return x;
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = LOGSZ; i >= 0; i --)
            if(dep[up[x][i]] >= dep[y]) x = up[x][i];
        if(x == y) return x;
        for(int i = LOGSZ; i >= 0; i --)
            if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
        return up[x][0];
    }
    T get(int x, int y){
        T res = inf;
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = LOGSZ; i >= 0; i --)
            if(dep[up[x][i]] >= dep[y])
                res = min(res, d[x][i]), x = up[x][i];
        return res;
    }
};

int StLca::dfn[maxn] = {0}, StLca::dct = 0;

struct VirTree : public StLca{
    gra e;
    bool vis[maxn], use[maxn];
    int p[maxn], st[maxn], id[maxn], iid[maxn], sz, tp, idt;
    static bool cmp(int x, int y){ return dfn[x] < dfn[y];}
    void reset(){
        while(sz) use[p[sz--]] = false;
        e.clear(idt), idt = 0;
    }
    void push(int x){ p[++ sz] = x, use[x] = true; }
    void st_pop(){
        e.add(id[st[tp-1]], id[st[tp]], get(st[tp - 1], st[tp]));
        vis[st[tp --]] = false;
    }
    void st_push(int x){st[++ tp] = x, id[x] = ++idt, iid[idt] = x, vis[x] = true;}
    void build(){
        sort(p+1, p+1+sz, cmp),
                st_push(R);
        for(int i = 1; i <= sz; i ++){
            int LCA = lca(st[tp], p[i]);
            while(dep[st[tp-1]] >= dep[LCA]) st_pop();
            if(!vis[LCA]) st_push(LCA), swap(st[tp], st[tp-1]), st_pop();
            st_push(p[i]);
        }
        while(tp > 1) st_pop();
        vis[st[tp --]] = false;
    }
    T dp(int x){
        T res = 0;
        for(int i = e.head[x]; i; i = e.nxt[i]){
            int u = e.to[i];
            if(use[iid[u]]) res += e.f[i];
            else res += min(e.f[i], dp(u));
        }
        return res;
    }
    T dp(){ return dp(R);}
};


int n, m;
VirTree vt;

int main(){
    scanf("%d", &n), vt.init(n, 1);
    for(int i = 1, a, b, c; i < n; i ++){
        scanf("%d%d%d", &a, &b, &c);
        vt.add(a, b, c), vt.add(b, a, c);
    }
    // 预处理LCA
    vt.CalcLca(), scanf("%d", &m);
    for(int i = 1, nn; i <= m; i ++){
        // 每次执行完进行reset
        scanf("%d", &nn), vt.reset();
        for(int j = 1, a; j <= nn; j ++)
            scanf("%d", &a), vt.push(a); // 使用push压入节点信息
        vt.build(), printf("%lld\n", vt.dp()); // build构建，dp求解
    }
    return 0;
}