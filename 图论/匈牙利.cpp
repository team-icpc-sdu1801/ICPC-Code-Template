//匈牙利求最小边覆盖（点数 － 最大匹配）
//最小点覆盖 ＝ 最大匹配
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int N=100010;
int matching[N],te,check[N],ans,head[N],n,m;
struct edge{
    int v,next;
}e[200010];
void add(int u,int v)
{
    e[++te].v=v;
    e[te].next=head[u];
    head[u]=te;
}
int dfs(int u)
{
    for (int i=head[u];i;i=e[i].next)
    {
        int v=e[i].v;
        if (!check[v])
        {
            check[v]=1;
            if (matching[v]==-1||dfs(matching[v]))
            {
                matching[u]=v;
                matching[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungarian()
{
    memset(matching,-1,sizeof(matching));
    for (int i=1;i<=n;i++)
    {
        if (matching[i]==-1)
        {
            memset(check,0,sizeof(check));
            if(dfs(i))++ans;
        }
    }
}
int main()
{
    ans=0;
    memset(head,0,sizeof(head));
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v+n);
    }
    hungarian();
    cout<<n-ans;
}
/*
(1)二分图的最大匹配
匈牙利算法
(2)二分图的最小点覆盖
二分图的最小点覆盖=二分图的最大匹配
求最小点覆盖：从右边所有没有匹配过的点出发，按照增广路的“交替出现”的要求DFS。最终右边没有访问过的点和左边访问过的点组成最小点覆盖。
证明见这里
(3)二分图的最少边覆盖
二分图的最少边覆盖=点数-二分图的最大匹配
证明：
先贪心选一组最大匹配的边放进集合，对于剩下的没有匹配的点，随便选一条与之关联的边放进集合，那么得到的集合就是最小边覆盖。
所以有：最小边覆盖=最大匹配+点数-2*最大匹配=点数-最大匹配
(4)二分图的最大独立集
二分图的最大独立集=点数-二分图的最大匹配
证明：
我们可以这样想，先把所有的点放进集合，然后删去最少的点和与之相关联的边，使得全部边都被删完，这就是最小点覆盖。所以有：最大独立集=点数-最小点覆盖
(5)有向无环图的最少不相交路径覆盖
我们把原图中的点VV拆成两个点VxVx和VyVy，对于原图中的边A−>BA−>B，我们在新图中连Ax−>ByAx−>By。那么最少不相交路径覆盖=原图的点数-新图的最大匹配
证明：
一开始每个点都独立为一条路径，在二分图中连边就是将路径合并，每连一条边路径数就减一。因为路径不能相交，所以不能有公共点，这恰好就是匹配的定义。所以有：最少不相交路径覆盖=原图的点数-新图的最大匹配
(6)有向无环图的最少可相交路径覆盖
先用floyd求出原图的传递闭包， 如果a到b有路， 那么就加边a->b。 然后就转化成了最少不相交路径覆盖问题。
(7)有向无环图中最少不相交路径覆盖和最大独立集的相互转化
用偏序集，一般可以抽象为有向无环图。建议先看看这篇博客
Dilworth定理：有向无环图的最大独立集=有向无环图最少不相交路径覆盖
*/