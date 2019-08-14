#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 120010;
//const int inf = 0x7fffffff;
const ll inf = 0x7fffffffffffffffLL;

template <class T>
struct gra{
    int mxn;
    int head[maxn], to[maxn<<1], nxt[maxn<<1], cnt;
    T f[maxn<<1];
    void clear(int n=0){
        if(n) mxn = n;
        if(cnt != 1){
            for(int i = 0; i <= mxn; i ++) head[i] = 0;
            cnt = 1;
        }
    }
    void add(int a, int b, T c){
        nxt[++ cnt] = head[a], head[a] = cnt, to[cnt] = b, f[cnt] = c;
        nxt[++ cnt] = head[b], head[b] = cnt, to[cnt] = a, f[cnt] = 0;
    }
};

template <class T>
struct flow{
    gra <T> e;
    int dep[maxn], vm[maxn], q[maxn], cur[maxn], s, t, mx;
    void init(int ss, int tt, int mxx){s = ss, t = tt, mx = mxx, e.clear(mx);}
    void bfs(){
        for(int i = 0; i <= mx; i ++) dep[i] = -1, vm[i] = 0;
        int l = 1, r = 0;
        q[++ r] = t, dep[t] = 1, vm[1] = 1;
        while(l <= r){
            int x = q[l ++];
            for(int i = e.head[x]; i; i = e.nxt[i]){
                int u = e.to[i];
                if(dep[u] == -1)
                    dep[u] = dep[x] + 1, vm[dep[u]] ++, q[++ r] = u;
            }
        }
    }
    T dfs(int x, T mr){
        if(x == t || mr == 0) return mr;
        T c = 0, res = 0;
        for(int &i = cur[x]; i; i = e.nxt[i]){
            int u = e.to[i];
            if(e.f[i] && dep[u] + 1 == dep[x] && (c = dfs(u, min(e.f[i], mr))))
                e.f[i] -= c, e.f[i^1] += c, mr -= c, res += c;
            if(mr == 0) return res;
        }
        if(-- vm[dep[x]] == 0) dep[s] = mx + 1;
        dep[x] ++, vm[dep[x]] ++;
        return res;
    }
    T isap(){
        T res = 0; bfs();
        while(dep[s] <= mx) {
            for(int i = 0; i <= mx; i ++) cur[i] = e.head[i];
            res += dfs(s, inf);
        }
        return res;
    }
};

int n, m, s, t;
flow<ll> flw;

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    flw.init(s, t, n);
    for(int i = 1, a, b, c; i <= m; i ++){
        scanf("%d%d%d", &a, &b, &c);
        flw.e.add(a, b, c);
    }
    printf("%lld\n", flw.isap());
    return 0;
}

