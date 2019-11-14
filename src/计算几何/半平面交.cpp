#include<cmath>
#include<cstring>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-6;
const int maxn=2e5+10;
const double Pi=acos(-1.00);
inline int dcmp(double x)
{
    if(x>eps)return 1;
    return x<-eps?-1:0;
}
struct Vector
{
    double x,y;
    Vector(double X=0,double Y=0)
    {
        x=X,y=Y;
    }
    bool operator == (const Vector &b)const 
    {
        return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;
    }
    double angle()
    {
        return atan2(y,x);//求出极角
    }
};
typedef Vector Point;
Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double b){return Vector(a.x*b,a.y*b);}
Vector operator / (Vector a,double b){return Vector(a.x/b,a.y/b);}
struct Line
{
    Point s,t;
    double ang;
    Line(Point X=Vector(),Point Y=Vector())
    {
        s=X,t=Y,ang=(Y-X).angle();
    }
};
typedef Line Segment;
double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
bool is_parallel(Line a,Line b)//判断a,b直线是否平行
{
    return dcmp(cross(a.t-a.s,b.t-b.s))==0;
}
Point intersection(Line a,Line b)//求出a,b的交点
{
    return a.s+(a.t-a.s)*(cross(b.t-b.s,a.s-b.s)/cross(a.t-a.s,b.t-b.s));
}
double area(Point *p,int n)//求出多边形的面积
{
    double res=0;
    p[n+1]=p[1];
    for(int i=1;i<=n;i++)res+=cross(p[i],p[i+1]);
    return fabs(res/2);
}
bool operator < (const Line &a,const Line &b)//极角排序，如果极角相同则，选择最靠左的直线
{
    double r=a.ang-b.ang;
    if(dcmp(r)!=0)return dcmp(r)==-1;
    return dcmp(cross(a.t-a.s,b.t-a.s))==-1;
}
bool OnRight(Line a,Point b)//检查b是否在a直线的右边
{
    return dcmp(cross(a.t-a.s,b-a.s))<0;
}
bool SI(Line *l,int n,Point *s,int &m)//增量法求半平面交
{
    static Line que[maxn];
    static Point que2[maxn];//两个双端队列
    int head=0,tail=0;
    sort(l+1,l+1+n);
    que[0]=l[1];
    for(int i=2;i<=n;i++)
    if(dcmp(l[i].ang-l[i-1].ang)!=0)//极角相等的直线，取一个
    {
        if(head<tail&&(is_parallel(que[head],que[head+1])||is_parallel(que[tail],que[tail-1])))return false;//如果两个直线共线，但是极角不同，则没有半平面交
        while(head<tail&&OnRight(l[i],que2[tail-1]))tail--;//如果在直线右边，删除点
        while(head<tail&&OnRight(l[i],que2[head]))head++;
        que[++tail]=l[i];
        if(head<tail)que2[tail-1]=intersection(que[tail],que[tail-1]);//加入新点
    }
    while(head<tail&&OnRight(que[head],que2[tail-1]))tail--;//删去多余点
    while(head<tail&&OnRight(que[tail],que2[head]))head++;
    if(tail-head<=1)return false;//只有一个点或零个点，没有半平面交
    que2[tail]=intersection(que[head],que[tail]);//加入最后一条边，和第一条边的交点
    m=0;
    for(int i=head;i<=tail;i++)s[++m]=que2[i];
    return true;
}
const double lim=10000;
int n,m;
Point p[maxn];
Line l[maxn];
double solve()
{
    Point a=Point(0,0);//加入最大限制，防止半平面交无限大
    Point b=Point(lim,0);
    Point c=Point(lim,lim);
    Point d=Point(0,lim);
    l[++n]=Line(a,b);
    l[++n]=Line(b,c);
    l[++n]=Line(c,d);
    l[++n]=Line(d,a);
    if(!SI(l,n,p,m))return 0;
    return area(p,m);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        Point a,b;
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        l[i]=Line(a,b);
    }
    printf("%.1f\n",solve());
}