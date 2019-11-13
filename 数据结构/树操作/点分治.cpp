#include <bits/stdc++.h>

#define mem(x, v) memset(x, v, sizeof(x))

using namespace std;

typedef long long ll;

const int maxn = 10010;
const int inf = ~0u >> 1u;
//const ll inf = ~0llu >> 1u;


struct gra {
    int head[maxn], to[maxn << 1], nxt[maxn << 1], f[maxn << 1], cnt;
    void clear(int n) { fill(head, head + 1 + n, 0), cnt = 0; }
    void add(int a, int b, int c) { nxt[++cnt] = head[a], to[head[a] = cnt] = b, f[cnt] = c; }
};

struct PointDivide : public gra{
    int sz[maxn], TS, SZmx, root;
    bool vis[maxn], res[maxn];

    void GetRoot(int x, int fa) {
        int SZ = 0;
        sz[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int u = to[i];
            if (vis[u] || u == fa) continue;
            GetRoot(u, x);
            sz[x] += sz[u];
            if (sz[u] > SZ) SZ = sz[u];
        }
        if (TS - sz[x] > SZ) SZ = TS - sz[x];
        if (SZmx > SZ) SZmx = SZ, root = x;
    }

    int GetSize(int x, int fa) {
        int siz = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int u = to[i];
            if (vis[u] || u == fa) continue;
            siz += GetSize(u, x);
        }
        return siz;
    }

    void calc(int x, int fa) {
        
        for (int i = head[x]; i; i = nxt[i]) {
            int u = to[i];
            if (vis[u] || u == fa) continue;
            calc(u, x);
        }
    }

    void sol(int x) {
        vis[x] = true;
        for (int i = head[x]; i; i = nxt[i]) {
            int u = to[i];
            if (vis[u]) continue;

            calc(u, x);
        }

        for (int i = head[x]; i; i = nxt[i]) {
            int u = to[i];
            if (!vis[u]) getAns(u, x);
        }
    }

    void getAns(int x, int fa){ SZmx = inf, TS = GetSize(x, fa), GetRoot(x, fa), sol(root); }
}S;



int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%d", &n), S.clear(n);
    for (int i = 1, a, b, c; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        S.add(a, b, c), S.add(b, a, c);
    }
    S.getAns(1, 0);
    
    return 0;
}
