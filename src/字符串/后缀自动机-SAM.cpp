const int N = 40010;
struct state{
    int len, link;
    int next[180];
}st[N];
int sz, last;
int s[N], a[N], n;
int l[N], r[N], c[N], q[N];
void sam_init(){
    memset(st, 0, sizeof(st));
    sz = last = 1;
}
void sam_extend(int c){
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    int p = last;
    while(p && !st[p].next[c]){
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (!p){
        st[cur].link = 1;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = ++sz;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
            st[clone].link = st[q].link;
            while(p && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
