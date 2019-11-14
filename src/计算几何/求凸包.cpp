typedef vector<point> polygon;
inline int cmp(const point &a, const point &b){
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int st[N], ct;
polygon ConvexHull(point *P, int sz){
    polygon res;
    sort(P, P + sz, cmp), ct = 0;
    st[++ct] = 0, st[++ct] = 1;
    for (int i = 2; i < sz; ++i){
        while(ct > 1 && dcmp((P[st[ct]] - P[st[ct-1]]) ^ (P[i] - P[st[ct]])) <= 0)
            ct--;
        st[++ct] = i;
    }
    for (int i = 1; i <= ct; ++i) res.push_back(P[st[i]]);
    ct = 0, st[++ct] = sz - 1, st[++ct] = sz - 2;
    for (int i = sz - 3; i >= 0; --i){
        while(ct > 1 && dcmp((P[st[ct]] - P[st[ct-1]]) ^ (P[i] - P[st[ct]])) <= 0)
            ct--;
        st[++ct] = i;
    }
    for (int i = 2; i < ct; ++i) res.push_back(P[st[i]]);
    return res;
}