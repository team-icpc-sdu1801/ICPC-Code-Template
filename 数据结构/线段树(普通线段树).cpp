template <class T>
struct SegmentTree {
#define lch (now << 1)
#define rch ((now<<1)|1)
#define mid ((l+r)>>1)
#define gol lch,l,mid
#define gor rch,mid+1,r
#define upd(l,r,x) que(l,r,1,x)
    T tr[maxn << 2], lz[maxn << 2], I, *val, v;
    int n, len[maxn << 2], p1, p2, tp;
    void init(int num, T *v) {n = num, I = 0, val = v, build(1, 1, n);}
    // 标记+更新当前节点 
    inline void up(int now, T v) {
        tr[now] = (tr[now] + v * len[now] % mod) % mod;
        lz[now] = (lz[now] + v) % mod;
    }
    // 区间合并 
    inline T merge(T x, T y) { return (x + y) % mod;}
    // 标记下放
    inline void down(int now) {
        if (lz[now] != I) up(lch, lz[now]), up(rch, lz[now]);
        lz[now] = I;
    }
    void build(int now, int l, int r) {
        len[now] = r - l + 1;
        if (l == r) {tr[now] = val[l]; return;}
        build(gol), build(gor), tr[now] = merge(tr[lch], tr[rch]);
    }
    T nx(int now, int l, int r) {
        if (l >= p1 && r <= p2)  return tp ? (up(now, v), 0) : tr[now];
        down(now); T lv = I, rv = I;
        if(p1 <= mid) lv = nx(gol);
        if(p2 > mid) rv = nx(gor);
        return tp ? (tr[now] = merge(tr[lch], tr[rch]), 0) : merge(lv, rv);
    }
    T que(int l, int r, int TP=0, T V=0){return p1 = l, p2 = r, tp = TP, v = V, nx(1, 1, n);}
};
