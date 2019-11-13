const ll mi = 1e9;
const ll mii[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

struct Bigint {
    ll d[501];
    bool op; // op == 0为正 1为负
    int sz;
    Bigint(ll x = 0) : sz(0) {
        mem(d, 0), op = x < 0, x = abs(x);
        if (x == 0) sz = 1, op = false;
        else while (x) d[sz++] = x % mi, x /= mi;
    }
    Bigint(const string &s) : sz(0) {
        int lw = 0;
        mem(d, 0), lw += op = (s[0] == '-');
        for (int i = s.length() - 1, j = 0; i >= lw; i--, j++) {
            d[sz] += mii[j] * (s[i] - '0');
            if (j == 8) sz++, j = -1;
        }
        if (sz == 0 || d[sz] != 0) sz++;
        if (sz == 1 && d[0] == 0) op = false;
    }

    inline void up(int p) { d[p + 1] += d[p] / mi, d[p] %= mi; }
    inline void refresh() {
        int i;
        for (i = 0; i < sz || d[i] != 0; i++) up(i);
        sz = i;
    }
    bool NumCmp(const Bigint &t) const {
        if (sz != t.sz) return sz < t.sz;
        for (int i = sz - 1; i >= 0; i--)
            if (d[i] != t.d[i]) return d[i] < t.d[i];
        return false;
    }
    Bigint NumSub(const Bigint &x) const {
        Bigint res = *this;
        for (int i = 0; i < x.sz; i++) res.d[i] -= x.d[i];
        for (int i = 0; i < res.sz || res.d[i] != 0; i++)
            if (res.d[i] < 0) res.d[i] += mi, res.d[i + 1]--;
        while (res.sz > 1 && res.d[res.sz - 1] == 0) res.sz--;
        return res;
    }
    Bigint NumAdd(const Bigint &x) const {
        Bigint res = *this;
        res.sz = max(sz, x.sz);
        int i;
        for (i = 0; i < x.sz; i++) res.d[i] += x.d[i];
        res.refresh();
        return res;
    }
    Bigint NumMul(const Bigint &x) const {
        Bigint res;
        res.sz = sz + x.sz - 1, res.op = op ^ x.op;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < x.sz; j++) {
                res.d[i + j] += d[i] * x.d[j];
                res.up(i + j);
            }
        }
        res.refresh();
        return res;
    }
    Bigint flip() const {
        Bigint tmp = *this;
        tmp.op = true;
        return tmp;
    }
    Bigint operator+(const Bigint &x) const {
        if (!(op ^ x.op)) return NumAdd(x);
        if (op == 1 && x.op == 0) {
            if (NumCmp(x)) return x.NumSub(*this);
            else return NumSub(x);
        }
        return x + *this;
    }
    Bigint operator*(const Bigint &x) const { return NumMul(x); }
    Bigint operator-(const Bigint &x) const { return *this + x.flip(); }
    bool operator<(const Bigint &x) const {
        if (op != x.op) return op > x.op;
        return op == 0 == NumCmp(x);
    }
    bool operator>(const Bigint &x) const { return x < *this; }
    void print() {
        if (op) putchar('-');
        printf("%lld", d[sz - 1]);
        for (int i = sz - 2; i >= 0; i--) printf("%09lld", d[i]);
    }
};