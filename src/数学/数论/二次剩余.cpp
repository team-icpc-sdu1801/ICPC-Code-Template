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
LL mod=1e9+7,I_mul;
struct com
{
	LL a,b;
	com(LL a=0,LL b=0):a(a),b(b){}
	bool operator == (com y){return a==y.a&&b==y.b;}
	com operator * (com y){return com((a*y.a+I_mul*b%mod*y.b)%mod,(b*y.a+a*y.b)%mod);}
	com operator ^ (LL k)
	{
		com res(1,0);
		com x(a,b);
		for(;k;x=x*x,k>>=1)if(k&1)res=res*x;
		return res;
	} 
};
//判断一个数x是否有二次剩余 
bool check_if_residue(LL x,LL M){return !x||(com(x,0)^((M-1)>>1))==com(1,0);}
//二次剩余的两个解放在x0和x1中 
void solve(LL n,LL p,LL &x0,LL &x1)
{
	if(!n){x0=x1=0;return ;}
	mod=p;
	LL g=rand()%mod;
	while(!g||check_if_residue((g*g+mod-n)%mod,mod))g=rand()%mod;
	I_mul=(g*g+mod-n)%mod;
	x0=(LL)(com(g,1)^((mod+1)>>1)).a;
	x1=mod-x0;
}
LL ans1,ans2;
LL p;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&p,&mod);
		if(!check_if_residue(p,mod)){puts("Hola!");continue;}
		solve(p,mod,ans1,ans2);
		if(ans1==ans2)printf("%lld\n",ans1);
		else
		{
			if(ans1>ans2)swap(ans1,ans2);
			printf("%lld %lld\n",ans1,ans2);
		}
		
	}
}


