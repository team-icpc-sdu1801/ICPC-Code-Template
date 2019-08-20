struct gra {
    int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt;
    T f[maxn << 1];
    void clear(int n) {fill(head, head+1+n, 0), cnt = 0;}
    void add(int a, int b, T c) {nxt[++cnt] = head[a], to[head[a] = cnt] = b, f[cnt] = c;}
};

const int LOGSZ = 19;

struct StLca : public gra{
    T d[maxn][LOGSZ+1], up[maxn][LOGSZ+1];
    int dep[maxn], n, R;
    void init(int N, int root, const T *v = nullptr){
        n = N, R = root, mem(up[R], 0), dep[R] = 1, clear(n);
        if(v != nullptr) for(int i = 1; i <= n; i ++) d[i][0] = v[i];
    }
    void CalcLca(){ dfs(R);}
    void dfs(int x){
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
    T que(int x, int y){
        int LCA = lca(x, y);
        return min(get(x, LCA), get(y, LCA));
    }
};
