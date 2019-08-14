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
//求最长不重叠子串
    const int N = 40010;
struct state{
    int len, link;
    int next[180];
}st[N];
int sz, last;
int s[N], a[N], n;
int l[N], r[N], c[N], q[N];
void sam_init(){
    memset(l, 63, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(q, 0, sizeof(q));
    memset(st, 0, sizeof(st));
    sz = last = 1;
}
void sam_extend(int c){
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    l[cur] = r[cur] = st[cur].len;
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
int main()
{
    while(scanf("%d", &n)){
        if (!n)break;
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            scanf("%d", &s[i]);
            a[i] = s[i] - s[i - 1];
        }
        sam_init();
        for (int i = 2; i <= n; ++i){
            sam_extend(a[i] + 88);
        }
        for (int i = 1; i <= sz; ++i)c[st[i].len]++;
        for (int i = 1; i < n; ++i) c[i] += c[i-1];
        for (int i = sz; i; i--)q[c[st[i].len]--] = i;
        for (int i = sz; i; i--){
            int p = q[i];
            l[st[p].link] = min(l[st[p].link], l[p]);
            r[st[p].link] = max(r[st[p].link], r[p]);
        }
        for (int i = 1; i <= sz; ++i)
            ans = max(ans, min(st[i].len, r[i] - l[i]));
        if (ans < 4)puts("0");
        else printf("%d\n", ans + 1);
    }
}
