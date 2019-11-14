struct lb2{
    static const int szX = 1010, szY = 1010;
    int n, m;
    int d[szX][szY];
    inline int lb(int x){return x&(-x);}
    void set_sz(int sizeX=szX-10, int sizeY=szY-10){n = sizeX, m = sizeY;}
    void mdf(int x, int y, int v){
        for(int i = x; i <= n; i += lb(i))
            for(int j = y; j <= m; j += lb(j))
                d[i][j] += v;
    }
    int ask(int x, int y){
        int res = 0;
        for(int i = x; i; i -= lb(i))
            for(int j = y; j; j -= lb(j))
                res += d[i][j];
        return res;
    }
    void clear(){memset(d, 0, sizeof(d));}
};
