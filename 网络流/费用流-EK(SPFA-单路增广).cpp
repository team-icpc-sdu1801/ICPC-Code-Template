#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 15010;
//const int inf = 0x7fffffff;
const ll inf = 0x7fffffffffffffffLL;

template <class T>
struct gra{
    int mxn;
    int head[maxn], to[maxn<<1], nxt[maxn<<1], cnt;
    T f[maxn<<1], v[maxn << 1];
    void clear(int n=0){
        if(n) mxn = n;
        if(cnt != 1){
            for(int i = 0; i <= mxn; i ++) head[i] = 0;
            cnt = 1;
        }
    }
    void add(int a, int b, T c, T d){
        nxt[++ cnt] = head[a], head[a] = cnt, to[cnt] = b, f[cnt] = c, v[cnt] = d;
        nxt[++ cnt] = head[b], head[b] = cnt, to[cnt] = a, f[cnt] = 0, v[cnt] = -d;
    }
};

template <class T>
struct cost_flow{
    gra <T> e;
    int pr[maxn], q[maxn], s, t, mx;
    bool vis[maxn];
    T dis[maxn], mnf[maxn];
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, e.clear(mx);}
    bool spfa(){
        for(int i = 0; i <= mx; i ++) dis[i] = inf, vis[i] = 0;
        int l = 1, r = 0;
        mnf[s] = inf, vis[s] = 1, dis[s] = 0, q[++ r] = s;
        while(l <= r){
            int x = q[l ++];
            for(int i = e.head[x]; i; i = e.nxt[i]){
                int u = e.to[i];
                if(e.f[i] > 0 && dis[u] > dis[x] + e.v[i]){
                    dis[u] = dis[x] + e.v[i];
                    pr[u] = i, mnf[u] = min(mnf[x], e.f[i]);
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
            for(int x = t; x != s; x = e.to[pr[x] ^ 1]){
                e.f[pr[x]] -= mnf[t], e.f[pr[x]^1] += mnf[t];
            }
        }
        return make_pair(flow, cost);
    }
};

cost_flow <ll> flw;
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    flw.init(1, n, n);
    for(int i = 1; i <= m; i ++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        flw.e.add(a, b, c, d);
    }
    auto res = flw.ek();
    printf("%lld %lld\n", res.first, res.second);
    return 0;
}
