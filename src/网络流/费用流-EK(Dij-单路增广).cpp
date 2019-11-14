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

struct node{
    T v;
    int x;
    node(T v=0, int x=0) : v(v), x(x) {}
    bool operator < (const node &t) const {return v > t.v;}
};

struct cost_flow : public gra{
    int pr[maxn], s, t, mx;
    bool vis[maxn];
    T dis[maxn], mnf[maxn], h[maxn];
    priority_queue <node> q;
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, clear(mx);}
    bool dij(){
        for(int i = 0; i <= mx; i ++) dis[i] = inf, vis[i] = false;
        mnf[s] = inf, dis[s] = 0, q.push(node(0, s));
        while(!q.empty()){
            int x = q.top().x; q.pop();
            if(vis[x]) continue; vis[x] = 1;
            for(int i = head[x]; i; i = nxt[i]){
                int u = to[i]; if(f[i] == 0) continue;
                T V = v[i] + h[x] - h[u];
                if(!vis[u] && dis[u] > dis[x] + V){
                    dis[u] = dis[x] + V, pr[u] = i;
                    mnf[u] = min(mnf[x], f[i]);
                    q.push(node(dis[u], u));
                }
            }
        }
        return vis[t];
    }
    pair<T, T> ek(){
        T flow = 0, cost = 0;
        while(dij()){
            for(int i = 0; i <= mx; i ++) if(dis[i] < inf) h[i] += dis[i];
            cost += mnf[t] * h[t], flow += mnf[t];
            for(int x = t; x != s; x = to[pr[x] ^ 1])
                f[pr[x]] -= mnf[t], f[pr[x] ^ 1] += mnf[t];
        }
        return make_pair(flow, cost);
    }
};
