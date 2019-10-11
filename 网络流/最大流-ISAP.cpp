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
    int dep[maxn], vm[maxn], q[maxn], cur[maxn], s, t, mx;
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, clear(mx);}
    void bfs(){
        for(int i = 0; i <= mx; i ++) dep[i] = -1, vm[i] = 0;
        int l = 1, r = 0;
        q[++ r] = t, dep[t] = 1, vm[1] = 1;
        while(l <= r){
            int x = q[l ++];
            for(int i = head[x]; i; i = nxt[i]){
                int u = to[i];
                if(dep[u] == -1)
                    dep[u] = dep[x] + 1, vm[dep[u]] ++, q[++ r] = u;
            }
        }
    }
    T dfs(int x, T mr){
        if(x == t || mr == 0) return mr;
        T c = 0, res = 0;
        for(int &i = cur[x]; i; i = nxt[i]){
            int u = to[i];
            if(f[i] && dep[u] + 1 == dep[x] && (c = dfs(u, min(f[i], mr))))
                f[i] -= c, f[i^1] += c, mr -= c, res += c;
            if(mr == 0) return res;
        }
        if(-- vm[dep[x]] == 0) dep[s] = mx + 1;
        dep[x] ++, vm[dep[x]] ++;
        return res;
    }
    T isap(){
        T res = 0; bfs();
        while(dep[s] <= mx) {
            for(int i = 0; i <= mx; i ++) cur[i] = head[i];
            res += dfs(s, inf);
        }
        return res;
    }
};
