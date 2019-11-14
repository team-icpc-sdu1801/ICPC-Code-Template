// 数函数调用init与work
struct Tarjan : public gra{
    int dfn[maxn], low[maxn], st[maxn], scc[maxn], sz[maxn];
    int tp, tim, num, n;
    gra e;
    void init(int N){clear(n = N), tim = 0, num = 0, tp = 0, mem(dfn, 0), mem(scc, 0);}
    int dfs(int x){
        dfn[x] = low[x] = ++ tim, st[++tp] = x;
        int stx = tp;
        for(int i = head[x]; i; i = nxt[i]){
            int u = to[i];
            if(!dfn[u]) dfs(u), low[x] = min(low[x], low[u]);
            else if(!scc[u]) low[x] = min(low[x], dfn[u]);
        }
        if(dfn[x] == low[x]){
            sz[++ num] = tp - stx + 1;
            while(tp >= stx) scc[st[tp --]] = num;
        }
    }
    void build(){
        unordered_set <int> has[n+1];
        for(int x = 1; x <= n; x ++){
            for(int i = head[x]; i; i = nxt[i]){
                int u = to[i], sx = scc[x], su = scc[u];
                if(has[sx].find(su) == has[sx].end() && sx != su)
                    e.add(sx, su), has[sx].insert(su);
            }
        }
    }
    void work(){
        for(int i = 1; i <= n; i ++) if(!dfn[i]) dfs(i);
        build();
        // 这里写操作
    }
};
