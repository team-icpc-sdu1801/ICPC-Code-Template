#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 600001;
const double pi = acos(-1);

struct com{
    double x, y;
    com(double x=0, double y=0) : x(x), y(y) {}
    com operator + (const com &t) const{return com(x+t.x, y+t.y);}
    com operator - (const com &t) const{return com(x-t.x, y-t.y);}
    com operator * (const com &t) const{return com(x*t.x-y*t.y, x*t.y+y*t.x);}
};

int R[maxn], B, lsn, mx;

void fft(com *a, int n, int inv){
    if(lsn != n && (lsn = n)) 
        for(int i = 0; i < n; i ++) R[i] = (R[i>>1]>>1) | ((i&1)<<(B-1));
    for(int i = 0; i < n; i ++) if(i < R[i]) swap(a[i], a[R[i]]);
    for(int i = 1; i < n; i <<= 1){
        com mi(cos(pi/i), sin(pi/i) * inv);
        for(int j = 0; j < n; j += (i << 1)){
            com x(1, 0);
            for(int k = 0; k < i; k ++, x = x * mi){
                com t1 = a[j+k], t2 = x * a[j+k+i];
                a[j+k] = t1 + t2, a[j+k+i] = t1 - t2;   
            }
        }
    }
    if(inv == -1) for(int i = 0; i < n; i ++) a[i].x /= n;
}

com a[maxn], b[maxn], Z;

int main(){

    for(mx = 1; mx < 2*n-1/*新多项式的长度*/; mx <<= 1, B ++);
    for(int j = 0; j < mx; j ++) a[j] = b[j] = Z;

    fft(a, mx, 1), fft(b, mx, 1);
    for(int j = 0; j < mx; j ++) a[j] = a[j] * b[j];
    fft(a, mx, -1);

    return 0;
}
