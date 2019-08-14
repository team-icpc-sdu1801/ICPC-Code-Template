int d[maxn], st[maxn][20];

void st_init(){
    for(int i = 1; i <= n; i ++) st[i][0] = d[i];
    for(int i = 1; i <= 17; i ++){
        for(int j = 1; j+(1<<i)-1 <= n; j ++){
            st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
}
int st_que(int l, int r){
    int k = log2(r - l + 1);
    return max(st[l][k], st[r-(1<<k)+1][k]);
}
