inline int dcmp(double x){
    if(fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}

struct mr{
    const static int sz = 501;
    double d[sz][sz];
    int sx, sy;
    mr(int x, int y){memset(d, 0, sizeof(d)), sx = x, sy = y;}
    void init(int *a, int x, int y){
        if(x > sz || y > sz) exit(-1);
        else sx = x, sy = y;
        for(int i = 0; i < x*y; i ++) d[i/x][i%y] = a[i];
    }
    bool Gaussian(){
        for(int i = 0; i < sx; i ++){
            if(dcmp(d[i][i]) == 0){
                int j = i+1;
                while(j < sx && dcmp(d[j][i]) == 0) j ++;
                if(j >= sx) return false;
                else swap(d[i], d[j]);
            }
            for(int j = i+1; j < sx; j ++){
                double v = d[j][i]/d[i][i];
                for(int k = i; k < sy; k ++) d[j][k] -= v * d[i][k];
            }
        }
        for(int i = sx-1; i >= 0; i --){
            if(d[i][i] == 0) return false;
            d[i][sy-1] /= d[i][i], d[i][i] = 1;
            for(int j = i-1; j >= 0; j --) d[j][sy-1] -= d[j][i] * d[i][sy-1], d[j][i] = 0;
        }
        return true;
    }
};
