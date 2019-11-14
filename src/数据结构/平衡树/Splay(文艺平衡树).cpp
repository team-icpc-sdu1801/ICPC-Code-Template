#include <cstdio>
const int maxn = 100010;
struct node{
    int val, num, size, tag;
    node *pre, *ch[2];
    void update(){size = ch[0]->size + ch[1]->size + 1;}
    void set_ch(int wh, node *child);
    int wh(){return pre->ch[0] == this ? 0 : 1;}
} Pool[maxn], *root, *null;
void node::set_ch(int wh, node *child){
    ch[wh] = child;
    if(child != null) child->pre = this;
    update();
}
void rotate(node *now){
    node *fa = now->pre, *gra = now->pre->pre;
    int wh = now->wh();  
    fa->set_ch(wh, now->ch[wh^1]);
    now->set_ch(wh^1, fa);
     
    now->pre = gra;
    if(gra != null) gra->ch[gra->ch[0] == fa ? 0:1] = now;
     
}
void splay(node *now, node *tar){
    for( ; now->pre != tar; rotate(now))
        if(now->pre->pre != tar)
            now->wh() == now->pre->wh() ? rotate(now->pre) : rotate(now);
    if(tar == null) root = now;
}
int cnt, ct, n, m;
node *one(int val, int num){
    node *one = &Pool[++cnt];
    one->ch[0] = one->ch[1] = one->pre = null;
    one->val = val, one->num = num;
    one->tag = 0, one->size = 1;
    return one;
}
void change(node *now){
    node *t = now->ch[0];
    now->ch[0] = now->ch[1];
    now->ch[1] = t;
}
void down(node *now){
    if(now->tag == 0) return;
    now->tag ^= 1;
    change(now->ch[0]);
    change(now->ch[1]);
    now->ch[0]->tag ^= 1;
    now->ch[1]->tag ^= 1;
     
}
void insert(int val){
    node *now = root, *last = null;
    while(now != null){
        last = now, down(now);
        if(val < now->val) now = now->ch[0];
        else now = now->ch[1];
    } 
    now = one(val, ++ ct);
    if(last == null) root = now;
    else{
        if(val < last->val) last->set_ch(0, now);
        else last->set_ch(1, now);
        splay(now, null);
    }
    return;
}
node *kth(int k){
    int left = k;
    node *now = root;
    while(now != null){
        down(now);
        if(now->ch[0]->size + 1 == left) return now;
        if(now->ch[0]->size + 1 > left) now = now->ch[0];
        else{
            left -= (now->ch[0]->size + 1);
            now = now->ch[1];
        }
    }
    return null;
}
 
void turn(int l, int r){
    node *ll, *rr, *now;
    *now->ch[0];
    *now->ch[1];
    if(l == 1 && r == n){now->tag ^= 1; return;}
    else if(l == 1){
        rr = kth(r+1);
        splay(rr, null);
        now = rr->ch[0];
        change(now), now->tag ^= 1;
    }else if(r == n){
        ll = kth(l-1);
        splay(ll, null);
        now = ll->ch[1];
        change(now);
        now->tag ^= 1;
    }else{
        ll = kth(l-1);
        rr = kth(r+1);
        splay(ll, null);
        splay(rr, ll);
        now = rr->ch[0];
        change(now), now->tag ^= 1;
    }
     
}
void print(node *now){
    down(now);
    if(now->ch[0] == null) printf("%d ", now->num);
    else print(now->ch[0]), printf("%d ", now->num);
    if(now->ch[1] != null) print(now->ch[1]);
}
int main(){
    null = Pool, null->num = null->size = null->tag = null->val = 0;
    null->pre = null->ch[0] = null->ch[1] = null, root = null;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        insert(i);
    for(int i = 1; i <= m; i ++){
        int l, r;
        scanf("%d%d", &l, &r);
        turn(l, r);
    }
    print(root);
}
?
