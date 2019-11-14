#include<bits/stdc++.h>

#define mem(x, v) memset(x, v, sizeof(x))

using namespace std;

typedef long long ll;

const int inf = ~0u >> 1u;
//const ll inf = ~0llu >> 1u;

const int N = 2097152;

ll n, rk[N], val[N];

struct SNode {
    int l, r;
    ll cnt, len;
};

struct SegmentTree {
#define ls (rt << 1)
#define rs (rt << 1 | 1)
    SNode t[N];

    void pushup(int rt) {
        if (t[rt].cnt) t[rt].len = val[t[rt].r + 1] - val[t[rt].l];
        else t[rt].len = t[ls].len + t[rs].len;
    }

    void build(int rt, int l, int r) {
        t[rt].l = l, t[rt].r = r;
        if (l == r) return;
        int mid = (t[rt].l + t[rt].r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
    }

    void add(int rt, int l, int r, int v) {
        if (l <= t[rt].l && t[rt].r <= r) {
            t[rt].cnt += v;
            pushup(rt);
            return;
        }
        int mid = (t[rt].l + t[rt].r) >> 1;
        if (l <= mid) add(ls, l, r, v);
        if (mid < r) add(rs, l, r, v);
        pushup(rt);
    }
} S;


struct node {
    int x, yh, yl, flag;

    bool operator<(const node &t) const {
        if (x != t.x) return x < t.x;
        return flag > t.flag;
    }
} e[N];


// x坐标是直接算的，y坐标是离散化的。

int main() {
    cin >> n;
    ll ans = 0;
    int n2 = n * 2, cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll x1, y1, x2, y2, i2 = i * 2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

        e[i2 - 1].x = x1, e[i2].x = x2;
        e[i2 - 1].yh = e[i2].yh = y2;
        e[i2 - 1].yl = e[i2].yl = y1;
        e[i2 - 1].flag = 1, e[i2].flag = -1;

        rk[++cnt] = y1;
        rk[++cnt] = y2;
    }

    sort(rk + 1, rk + n2 + 1);
    cnt = unique(rk + 1, rk + n2 + 1) - rk - 1;

    for (int i = 1; i <= n2; i++) {

        ll pos1 = lower_bound(rk + 1, rk + cnt + 1, e[i].yh) - rk;
        ll pos2 = lower_bound(rk + 1, rk + cnt + 1, e[i].yl) - rk;

        val[pos1] = e[i].yh;
        val[pos2] = e[i].yl;
        e[i].yh = pos1;
        e[i].yl = pos2;
    }

    sort(e + 1, e + n2 + 1);
    S.build(1, 1, n2);

    for (int i = 1; i <= n2; i++) {
        S.add(1, e[i].yl, e[i].yh - 1, e[i].flag);
        ans += S.t[1].len * (e[i + 1].x - e[i].x);
    }
    cout << ans << endl;
    return 0;
}
