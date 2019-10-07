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