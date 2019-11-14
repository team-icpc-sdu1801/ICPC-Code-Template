class st2{
public:
    static const int szX = 302, szY = 302;
    static const int lgX = (int)log2(szX)+1, lgY = (int)log2(szY)+1;
    bool MnOMx; // 0 --> min  1 --> max
    int d[szX][szY][lgX][lgY], n, m;
    int oper(int x, int y){
        if(MnOMx) return x > y ? x : y;
        return x < y ? x : y;
    }
    void init(int sx, int sy, bool MinOrMax){
        n = sx, m = sy, MnOMx = MinOrMax;
        for(int i = 0; i < lgX; i ++)
            for(int j = 0; j < lgY; j ++){
                if(i + j == 0) continue;
                for(int x = 1; x + (1<<i) - 1 <= n; x ++)
                    for(int y = 1; y + (1<<j) - 1 <= m; y ++){
                        if(i == 0) d[x][y][i][j] = oper(d[x][y+(1<<(j-1))][i][j-1], d[x][y][i][j-1]);
                        else d[x][y][i][j] = oper(d[x+(1<<(i-1))][y][i-1][j], d[x][y][i-1][j]);
                    }
            }
    }
    // x1 <= x2 && y1 <= y2
    int ask(int x1, int y1, int x2, int y2){
        int lx = log2(x2-x1+1), ly = log2(y2-y1+1), xx = x2-(1<<lx)+1, yy = y2-(1<<ly)+1;
        return oper(oper(d[x1][y1][lx][ly], d[xx][y1][lx][ly]),
                oper(d[x1][yy][lx][ly], d[xx][yy][lx][ly]));
    }
    void clear(){memset(d, 0, sizeof(d));}
};

