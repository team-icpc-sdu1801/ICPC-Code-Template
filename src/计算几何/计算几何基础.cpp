#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const double inf = 1e18;
const double eps = 1e-9;
inline int dcmp(double x){
    if (fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}
struct point{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator == (const point &t) const {return x == t.x && y == t.y;}
    point operator + (const point &t) const {return point(x + t.x, y + t.y);}
    point operator - (const point &t) const {return point(x - t.x, y - t.y);}
    double operator * (const point &t) const {return x * t.x + y * t.y;}
    point operator * (const double &k) {return point(k*x, k*y);}
    double operator ^ (const point &t) const {return x * t.y - y * t.x;}
    double dis() {return sqrt(x * x + y * y);}
    double dis2() {return x * x + y * y;}
};
typedef point Vector;
//两向量夹角
double angle(Vector a, Vector b){
    return acos(a * b / a.dis() / b.dis());
}
//向量旋转（逆时针 弧度）
Vector rotate(Vector A, double rad){
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}
//逆时针九十度的法向量
Vector Normal(Vector A){
    double L = A.dis();
    return Vector(-A.y/L, A.x/L);
}
struct Line{
    point v, p;
    Line(point v, point p):v(v), p(p) {}
    //返回点P = V + (P - V) * T;
    point Point(double t){
        return v + (p - v) * t;
    }
};
//两直线交点，需保证两直线不相交（叉积不为0）P to AB
// v ^ w != 0
point Inter(point p, Vector v, point q, Vector w){
    Vector u = p - q;
    double t = (w ^ u) / (v ^ w);
    return p + v * t;
}
//点到直线距离, 绝对值为有向距离
double DisToLine(point P, point A, point B){
    Vector v1 = B - A, v2 = P - A;
    return fabs((v1 ^ v2) / v1.dis());
}
//点到线段距离 P to AB
double DisToSeg(point P, point A, point B){
    if (A == B) return (P - A).dis();
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(v1 * v2) < 0)
        return v2.dis();
    if (dcmp(v1 * v3) > 0)
        return v3.dis();
    return DisToLine(P, A, B);
}
//P在AB上的投影点
point GetPro(point P, point A, point B){
    Vector v = B - A;
    return A + v * (v * (P - A) / (v * v));
}
//p是否在线段a1a2上
bool OnSeg(point p, point a1, point a2){
    return dcmp((a1 - p) ^ (a2 - p)) == 0 && dcmp((a1 - p) * (a2 - p)) < 0;
}
//判断两线段相交
bool SegInter(point a1, point a2, point b1, point b2){
    double c1 = (a2 - a1) ^ (b1 - a1), c2 = (a2 - a1) ^ (b2 - a1);
    double c3 = (b2 - b1) ^ (a1 - b1), c4 = (b2 - b1) ^ (a2 - b1);
    if (!dcmp(c1) || !dcmp(c2) || !dcmp(c3) || !dcmp(c4)){
        bool f1 = OnSeg(b1, a1, a2);
        bool f2 = OnSeg(b2, a1, a2);
        bool f3 = OnSeg(a1, b1, b2);
        bool f4 = OnSeg(a2, b1, b2);
        bool f = (f1 | f2 | f3 | f4);
        return f;
    }
    return (dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0);
}

// pick定理 2S = 2A + B - 2， A为多边形内部的格点数， B为边上的格点数， 边上的格点数 ： GCD(X, Y).