#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const double eps = 1e-9;
const double inf = 1e18;
const int N = 101000;
inline int dcmp(double x){
    if (fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}
int n;
double r;

struct point{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator + (const point &t) const {return point(x + t.x, y + t.y);}
    point operator - (const point &t) const {return point(x - t.x, y - t.y);}
    double operator * (const point &t) const {return x * t.x + y * t.y;}
    point operator * (const double &k) {return point(k*x, k*y);}
    point operator / (const double &k) {return point(x/k, y/k);}
    double operator ^ (const point &t) const {return x * t.y - y * t.x;}
    double dis() {return sqrt(x * x + y * y);}
    double dis2() {return x*x + y*y;}
}a[N], O;

//最小圆覆盖
bool in_circle(point a){return (a - O).dis() <= r? 1:0;}

inline int calc1(double a, double b, double c, double d, double e, double f){
    O.x = (b*f - d*e) / (b*c - a*d);
    O.y = (c*e - a*f) / (b*c - a*d);
}
inline void min_cover_circle(){
    random_shuffle(a+1, a+n+1);
    for (int i = 1; i <= n; ++i)
        if (!in_circle(a[i])){
            O = a[i], r = 0;
            for (int j = 1; j < i; ++j)
                if (!in_circle(a[j])){
                    O = (a[i] + a[j]) / 2.0;
                    r = (a[i] - O).dis();
                    for (int k = 1; k < j; ++k)
                        if (!in_circle(a[k])) {
                            calc1(a[i].x - a[j].x, a[i].y - a[j].y,a[i].x - a[k].x, a[i].y - a[k].y,
                                  (a[i].dis2() - a[j].dis2())/2.0,(a[i].dis2() - a[k].dis2())/2.0);
                            r = (a[i] - O).dis();
                        }
                }
        }
    printf("%.3f\n", r);
};


//求凸包
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
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    min_cover_circle();
    return 0;
}