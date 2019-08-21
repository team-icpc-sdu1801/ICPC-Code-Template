#include <cstdio>

const int inf = 0x7fffffff;

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
struct Splay{
    sn *root;
    Splay(){
        null = new sn(0);
        null->pre = null->ch[0] = null->ch[1] = null;
        null->size = null->cnt = 0;
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
    sn* get_kth(int k) {
        sn *now = root;
        int left = k;
        while(now != null){
            if(left <= now->ch[0]->size+now->cnt && left >= now->ch[0]->size+1){
                splay(now, null);
                return now;
            }
            if(left <= now->ch[0]->size) now = now->ch[0];
            else left -= now->ch[0]->size + now->cnt, now = now->ch[1];
        }
        return null;
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
}s;
int main(){

    int q; scanf("%d", &q);
    while(q--){
        int order, val;
        scanf("%d%d", &order, &val);
        switch(order){
            case 1: s.insert(val); break;
            case 2: s.del(val); break;
            case 3: printf("%d\n", s.get_rank(val)); break;
            case 4: printf("%d\n", s.get_kth(val)->val); break;
            case 5: printf("%d\n", s.pre(val)->val); break;
            case 6: printf("%d\n", s.nxt(val)->val); break;
        }
    }
    return 0;
}
