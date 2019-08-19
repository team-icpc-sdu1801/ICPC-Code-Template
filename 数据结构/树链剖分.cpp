template <class T>
struct TreeHeavy{
    gra e;
    SegmentTree <T> SeTree;
    int sz[maxn], dep[maxn], fa[maxn], son[maxn], top[maxn];
    int pos[maxn], q[maxn], st[maxn], n, R;
    T *val;
    // 传入“点数”与“根节点编号”
    void init(int N, int root){e.clear(n=N), R = root;}
    // 传入节点初值
    void work(T *v) {
        val = v, fill(son+1, son+1+n, 0);
        int l = 1, r = 0, tp = 0, tim = 0;
        q[++r] = R, dep[R] = 1;
        while (l <= r) {
            int x = q[l++]; sz[x] = 1;
            for (int i = e.head[x]; i; i = e.nxt[i]) {
                int u = e.to[i]; if (u == fa[x]) continue;
                dep[u] = dep[x] + 1, fa[u] = x, q[++r] = u;
            }
        }
        for (int i = n; i >= 1; i--) {
            int x = q[i]; if (!fa[x]) continue;
            sz[fa[x]] += sz[x];
            if (sz[son[fa[x]]] < sz[x]) son[fa[x]] = x;
        }
        st[++tp] = R, top[R] = R;
        while (tp > 0) {
            int x = st[tp--];
            pos[x] = ++tim, q[tim] = val[x];
            for (int i = e.head[x]; i; i = e.nxt[i]) {
                int u = e.to[i]; if (u == fa[x] || u == son[x]) continue;
                st[++tp] = u, top[u] = u;
            }
            if (son[x]) st[++tp] = son[x], top[son[x]] = top[x];
        }
        for(int i = 1; i <= n; i ++) val[i] = q[i];
        SeTree.init(n, val);
    }
    // 链操作 $O(n \log^2 n)$
    T ask(int x, int y) {
        T res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            res = SeTree.merge(res, SeTree.que(pos[top[x]], pos[x]));
            x = fa[top[x]];
        }
        if (dep[x] < dep[y]) swap(x, y);
        res = SeTree.merge(res, SeTree.que(pos[y], pos[x]));
        return res;
    }
    void mdy(int x, int y, T v) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            SeTree.upd(pos[top[x]], pos[x], v);
            x = fa[top[x]];
        }
        if (dep[x] < dep[y]) swap(x, y);
        SeTree.upd(pos[y], pos[x], v);
    }
    // 子树操作 $O(n \log n)$
    T ask(int x) { return SeTree.que(pos[x], pos[x] + sz[x] - 1); }
    void mdy(int x, T v) { SeTree.upd(pos[x], pos[x] + sz[x] - 1, v); }
};
