#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define inl inline
#define re register
#define MAXN 10100
using namespace std;
const int maxn=200010;
struct gra {
	bool ins[maxn];
    int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt,flag;
    int dis[maxn],f[maxn << 1];
    void clear(int n) {fill(head, head+5+n, 0),flag=cnt = 0;}
    void add(int a, int b, int c) {nxt[++cnt] = head[a], to[head[a] = cnt] = b, f[cnt] = c;}
    void spfa(int h)
    {
    	ins[h]=1;
    	for(int i=head[h];i;i=nxt[i])
			if(dis[to[i]]>dis[h]+f[i])
    		{
     		    if(ins[to[i]]||flag){flag=1;break;}
        		dis[to[i]]=dis[h]+f[i];
				spfa(to[i]);
    		}
    	ins[h]=0;
	}
	bool ne_c(int n)
    {
    	fill(dis,dis+5+n,0);
    	fill(ins, ins+5+n, 0);
    	flag=0;
    	for(int i=0;i<=n&&!flag;i++)spfa(i);
		return flag;
	}
}G;
int n,m1,m2;
int edge1[maxn][4],edge2[maxn][4];
bool check(int p)
{
	G.clear(n+1);
	for(int i=1;i<=m1;i++)
		G.add(edge1[i][2],edge1[i][1]-1,-edge1[i][3]);
	for(int i=1;i<=m2;i++)
		G.add(edge2[i][1]-1,edge2[i][2],p-edge2[i][3]);
	for(int i=1;i<=n;i++)G.add(i,i-1,0),G.add(i-1,i,1);
	G.add(0,n,p),G.add(n,0,-p);
	return G.ne_c(n);
}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		scanf("%d%d%d",&n,&m1,&m2);
		for(int i=1;i<=m1;i++)
			scanf("%d%d%d",&edge1[i][1],&edge1[i][2],&edge1[i][3]);
		for(int i=1;i<=m2;i++)
			scanf("%d%d%d",&edge2[i][1],&edge2[i][2],&edge2[i][3]);
		int l=0,r=n,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	
	return 0;
}
/*
1
5 1 1
2 3 1
4 5 2
*/
