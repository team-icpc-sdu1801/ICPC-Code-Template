typedef int T;

struct gra{
    int head[maxn], to[maxn<<1], nxt[maxn<<1], cnt;
    T f[maxn<<1];
    void clear(int n) {fill(head, head+1+n, 0), cnt = 1;}
    void add(int a, int b, T c){
        nxt[++ cnt] = head[a], head[a] = cnt, to[cnt] = b, f[cnt] = c;
        nxt[++ cnt] = head[b], head[b] = cnt, to[cnt] = a, f[cnt] = 0;
    }
};

struct flow : public gra{
    int dep[maxn], q[maxn], cur[maxn], s, t, mx;
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, clear(mx);}
    bool bfs(){
        for(int i = 0; i <= mx; i ++) dep[i] = -1;
        int l = 1, r = 0;
        q[++ r] = s, dep[s] = 1;
        while(l <= r){
            int x = q[l ++];
            for(int i = head[x]; i; i = nxt[i]){
                int u = to[i];
                if(dep[u] == -1 && f[i] > 0)
                    q[++ r] = u, dep[u] = dep[x] + 1;
            }
        }
        return dep[t] != -1;
    }
    T dfs(int x, T mr){
        if(x == t || mr == 0) return mr;
        T c = 0, res = 0;
        for(int &i = cur[x]; i; i = nxt[i]){
            int u = to[i];
            if(dep[u] == dep[x] + 1 && (c = dfs(u, min(mr, f[i]))))
                f[i] -= c, f[i^1] += c, mr -= c, res += c;
            if(mr == 0) break;
        }
        return res;
    }
    T dinic(){
        T res = 0;
        while(bfs()){
            for(int i = 0; i <= mx; i ++) cur[i] = head[i];
            res += dfs(s, inf);
        }
        return res;
    }
};
