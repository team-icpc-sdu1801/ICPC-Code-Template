#include <cstdio>
#include <algorithm>

const int inf = 0x7fffffff;
const int maxn = 50010;

using namespace std;

struct sn{
    int val, cnt, size;
    sn *ch[2], *pre;
    sn(int v = 0);
    void set_ch(int wh, sn *child);
    int wh(){return pre->ch[0] == this ? 0 : 1;}
}*null;

sn::sn(int v){ val = v, size = cnt = 1, pre = ch[0] = ch[1] = null; }
void sn::set_ch(int wh, sn *child) {
    ch[wh] = child;
    if(child != null) child->pre = this;
    size = ch[0]->size + ch[1]->size + cnt;
}
bool is_init;
struct Splay{
    sn *root;
    Splay(){
        if(!is_init){
            is_init = true;
            null = new sn(0);
            null->pre = null->ch[0] = null->ch[1] = null;
            null->size = null->cnt = 0;
        }
        root = null;
    }
    void rotate(sn *now){
        int wh = now->wh();
        sn *fa = now->pre, *gra = now->pre->pre;
        fa->set_ch(wh, now->ch[wh^1]);
        now->set_ch(wh^1, fa), now->pre = gra;
        if(gra != null) gra->ch[gra->ch[0] == fa ? 0 : 1] = now;
    }
    void splay(sn *now, sn *tar){
        for( ; now->pre != tar; rotate(now))
            if(now->pre->pre != tar)
                now->wh() == now->pre->wh() ? rotate(now->pre) : rotate(now);
        if(tar == null) root = now;
    }
    void insert(int x){
        sn *now = root, *ins = new sn(x);
        while(now != null){
            if(now->val == ins->val) {
                now->size ++, now->cnt ++;
                splay(now, null);
                return;
            } else{
                x = ins->val < now->val ? 0 : 1;
                if(now->ch[x] == null) now->set_ch(x, ins), now = null;
                else now = now->ch[x];
            }
        }
        if(root == null) root = ins;
        else splay(ins, null);
    }
    sn *find(int x){
        sn *now = root;
        while(now != null){
            if(now->val == x) break;
            now = now->val < x ? now->ch[1] : now->ch[0];
        }
        if(now != null) splay(now, null);
        return now;
    }
    void del(int x){
        sn *now = find(x);
        if(now == null) return;
        if(now->cnt > 1){now->cnt --, now->size --;return;}
        if(now->ch[0] == null && now->ch[1] == null) {root = null;}
        else if(now->ch[0] == null) root = now->ch[1], now->ch[1]->pre = null;
        else if(now->ch[1] == null) root = now->ch[0], now->ch[0]->pre = null;
        else{
            sn *t = now->ch[0];
            while(t->ch[1] != null) t = t->ch[1];
            splay(t, now);
            t->set_ch(1, now->ch[1]);
            t->pre = null, root = t;
        }
        delete now;
    }
    int get_rank(int x){
        sn *now = find(x);
        if(now == null) return -1;
        return now->ch[0]->size + 1;
    }
    sn* pre(int val)const {
        sn *now = root, *ans = null;
        while(now != null){
            if(val <= now->val) now = now->ch[0];
            else {
                if(ans == null || ans->val < now->val) ans = now;
                now = now->ch[1];
            }
        }
        return ans;
    }
    sn* nxt(int val)const {
        sn *now = root, *ans = null;
        while(now != null){
            if(val >= now->val) now = now->ch[1];
            else {
                if(ans == null || ans->val > now->val) ans = now;
                now = now->ch[0];
            }
        }
        return ans;
    }
}s[maxn*6];

#define mid ((l+r)>>1)
#define lch (now<<1)
#define rch ((now<<1)+1)

int n, m;
int val[maxn];

void build(int now, int l, int r){
    for(int i = l; i <= r; i ++) s[now].insert(val[i]);
    if(l == r) return;
    build(lch, l, mid);
    build(rch, mid+1, r);
}
int que_rank(int now, int l, int r, int pos1, int pos2, int k){
    if(l == pos1 && r == pos2){return s[now].get_rank(k) - 1;}
    if(pos2 <= mid) return que_rank(lch, l, mid, pos1, pos2, k);
    else if(pos1 >= mid+1) return que_rank(rch, mid+1, r, pos1, pos2, k);
    else return que_rank(lch, l, mid, pos1, mid, k) + que_rank(rch, mid+1, r, mid+1, pos2, k);
}
int que_pre(int now, int l, int r, int pos1, int pos2, int k){
    if(l == pos1 && r == pos2){return s[now].pre(k)->val;}
    if(pos2 <= mid) return que_pre(lch, l, mid, pos1, pos2, k);
    else if(pos1 >= mid+1) return que_pre(rch, mid+1, r, pos1, pos2, k);
    else return max(que_pre(lch, l, mid, pos1, mid, k), que_pre(rch, mid+1, r, mid+1, pos2, k));
}
int que_nxt(int now, int l, int r, int pos1, int pos2, int k){
    if(l == pos1 && r == pos2){return s[now].nxt(k)->val;}
    if(pos2 <= mid) return que_nxt(lch, l, mid, pos1, pos2, k);
    else if(pos1 >= mid+1) return que_nxt(rch, mid+1, r, pos1, pos2, k);
    else return std::min(que_nxt(lch, l, mid, pos1, mid, k), que_nxt(rch, mid+1, r, mid+1, pos2, k));
}
int que_kth(int pos1, int pos2, int k){
    int l = 0, r = 1e8, res = -1;
    while(l <= r){
        int v = que_rank(1, 1, n, pos1, pos2, mid)+1;
        if(v > k) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return que_pre(1, 1, n, pos1, pos2, res);
}
void modify(int now, int l, int r, int pos, int k){
    s[now].insert(k);
    s[now].del(val[pos]);
    if(l == r) return;
    if(pos <= mid) modify(lch, l, mid, pos, k);
    else modify(rch, mid+1, r, pos, k);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &val[i]);
    build(1, 1, n);
    for(int i = 1; i <= m; i ++){
        int a, b, c, d;
        scanf("%d", &a);
        switch(a){
            case 1:
                scanf("%d%d%d", &b, &c, &d);
                printf("%d\n", que_rank(1, 1, n, b, c, d)+1);
                break;
            case 2:
                scanf("%d%d%d", &b, &c, &d);
                printf("%d\n", que_kth(b, c, d));
                break;
            case 3:
                scanf("%d%d", &b, &c);
                modify(1, 1, n, b, c);
                val[b] = c;
                break;
            case 4:
                scanf("%d%d%d", &b, &c, &d);
                printf("%d\n", que_pre(1, 1, n, b, c, d));
                break;
            case 5:
                scanf("%d%d%d", &b, &c, &d);
                printf("%d\n", que_nxt(1, 1, n, b, c, d));
                break;
        }
    }
    return 0;
}
