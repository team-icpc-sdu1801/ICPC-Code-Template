#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll p = 998244353, g = 3;

ll pow(ll x, int y){
    ll res = 1;
    for( ; y; y >>= 1, x = x * x % p) if(y&1) res = res * x % p;
    return res;
}
ll ni(ll x, int inv){return inv == 1 ? x : pow(x, p-2);}

int R[maxn], B, las, mx;

void ntt(ll *a, int n, int inv){
    if(las != n && (las = n)) 
        for(int i = 0; i < n; i ++) R[i] = (R[i>>1]>>1) | ((i&1)<<(B-1));
    for(int i = 0; i < n; i ++) if(i < R[i]) swap(a[i], a[R[i]]);
    for(int i = 1; i < n; i <<= 1){
        ll mi = ni(pow(g, (p-1)/(2*i)), inv);
        for(int j = 0; j < n; j += (i<<1)){
            for(int k = 0, x = 1; k < i; k ++, x = x * mi % p){
                ll t1 = a[j+k], t2 = x * a[j+k+i] % p;
                a[j+k] = (t1 + t2) % p, a[j+k+i] = (t1 - t2) % p;
            }
        }
    }
    if(inv == -1) for(int i = 0; i < n; i ++) {
        a[i] = a[i] * ni(n, inv) % p;
        if(a[i] < 0) a[i] += p;
    }
}

ll a[maxn], b[maxn];

int main(){

    for(mx = 1; mx < /*新多项式的长度*/; mx <<= 1, B ++);
    for(int i = 0; i < mx; i ++) a[i] = b[i] = 0;

    ntt(a, mx, 1), ntt(b, mx, 1);
    for(int i = 0; i < mx; i ++) a[i] = a[i] * b[i] % p;
    ntt(a, mx, -1);

    return 0;
}
