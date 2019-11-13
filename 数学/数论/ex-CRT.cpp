#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL MAXN = 1e6 + 10;
LL K, C[MAXN], M[MAXN], x, y;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    LL r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
LL inv(LL a, LL b) {
    LL r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}
//x%m=c
//×îºóX%M[n]=C[n] 
int main() {
    for (LL i = 1; i <= K; i++) scanf("%lld%lld", &M[i], &C[i]);
    bool flag = 1;
    for (LL i = 2; i <= K; i++) {
        LL M1 = M[i - 1], M2 = M[i], C2 = C[i], C1 = C[i - 1], T = gcd(M1, M2);
        if ((C2 - C1) % T != 0) {flag = 0; break;}
        M[i] = (M1 * M2) / T;
        C[i] = ( inv( M1 / T , M2 / T ) * (C2 - C1) / T ) % (M2 / T) * M1 + C1;
        C[i] = (C[i] % M[i] + M[i]) % M[i];
    }
    printf("%lld\n", flag ? C[K] : -1);
    return 0;
}
