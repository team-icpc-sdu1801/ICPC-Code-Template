#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 50010;
const int inf = ~0u >> 1u;
//const ll inf = ~0llu >> 1u;

template <class T>
struct gra{
    int head[maxn], to[maxn<<1], nxt[maxn<<1], cnt;
    T f[maxn<<1], v[maxn << 1];
    void clear(int n) {fill(head, head+1+n, 0), cnt = 1;}
    void add(int a, int b, T c, T d){
        nxt[++ cnt] = head[a], head[a] = cnt, to[cnt] = b, f[cnt] = c, v[cnt] = d;
        nxt[++ cnt] = head[b], head[b] = cnt, to[cnt] = a, f[cnt] = 0, v[cnt] = -d;
    }
};

template <class T>
struct node{
    T v;
    int x;
    node(T v=0, int x=0) : v(v), x(x) {}
    bool operator < (const node &t) const {return v > t.v;}
};

template <class T>
struct cost_flow{
    gra <T> e;
    int pr[maxn], s, t, mx;
    bool vis[maxn];
    T dis[maxn], mnf[maxn], h[maxn];
    priority_queue <node <T> > q;
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, e.clear(mx), fill(h, h+1+mx, 0);}
    bool dij(){
        for(int i = 0; i <= mx; i ++) dis[i] = inf, vis[i] = false;
        mnf[s] = inf, dis[s] = 0, q.push(node<T>(0, s));
        while(!q.empty()){
            int x = q.top().x; q.pop();
            if(vis[x]) continue; vis[x] = 1;
            for(int i = e.head[x]; i; i = e.nxt[i]){
                int u = e.to[i]; if(e.f[i] == 0) continue;
                T v = e.v[i] + h[x] - h[u];
                if(!vis[u] && dis[u] > dis[x] + v){
                    dis[u] = dis[x] + v, pr[u] = i;
                    mnf[u] = min(mnf[x], e.f[i]);
                    q.push(node<T>(dis[u], u));
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
            for(int x = t; x != s; x = e.to[pr[x] ^ 1])
                e.f[pr[x]] -= mnf[t], e.f[pr[x] ^ 1] += mnf[t];
        }
        return make_pair(flow, cost);
    }
};

cost_flow <int> flw;
int n, m, s, t;

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    flw.init(s, t, n);
    for(int i = 1; i <= m; i ++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        flw.e.add(a, b, c, d);
    }
    auto res = flw.ek();
    printf("%d %d\n", res.first, res.second);
    return 0;
}
