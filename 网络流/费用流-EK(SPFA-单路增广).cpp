typedef int T;

struct gra{
    int head[maxn], to[maxn<<1], nxt[maxn<<1], cnt;
    T f[maxn<<1], v[maxn << 1];
    void clear(int n) {fill(head, head+1+n, 0), cnt = 1;}
    void add(int a, int b, T c, T d){
        nxt[++ cnt] = head[a], head[a] = cnt, to[cnt] = b, f[cnt] = c, v[cnt] = d;
        nxt[++ cnt] = head[b], head[b] = cnt, to[cnt] = a, f[cnt] = 0, v[cnt] = -d;
    }
};

struct cost_flow : public gra{
    int pr[maxn], q[maxn], s, t, mx;
    bool vis[maxn];
    T dis[maxn], mnf[maxn];
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, clear(mx);}
    bool spfa(){
        for(int i = 0; i <= mx; i ++) dis[i] = inf, vis[i] = 0;
        int l = 1, r = 0;
        mnf[s] = inf, vis[s] = 1, dis[s] = 0, q[++ r] = s;
        while(l <= r){
            int x = q[l ++];
            for(int i = head[x]; i; i = nxt[i]){
                int u = to[i];
                if(f[i] > 0 && dis[u] > dis[x] + v[i]){
                    dis[u] = dis[x] + v[i];
                    pr[u] = i, mnf[u] = min(mnf[x], f[i]);
                    if(vis[u] == 0) vis[u] = 1, q[++ r] = u;
                }
            }
            vis[x] = 0;
        }
        return dis[t] != inf;
    }
    pair<T, T> ek(){
        T flow = 0, cost = 0;
        while(spfa()){
            cost += mnf[t]*dis[t], flow += mnf[t];
            for(int x = t; x != s; x = to[pr[x] ^ 1]){
                f[pr[x]] -= mnf[t], f[pr[x]^1] += mnf[t];
            }
        }
        return make_pair(flow, cost);
    }
};
