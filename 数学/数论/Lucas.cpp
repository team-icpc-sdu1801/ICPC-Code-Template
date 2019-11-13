#include<iostream>
#define LL long long
using namespace std;
LL n,m;
LL fac[100100],mod;
LL inv(LL i)
{
	LL res=1,j=mod-2;
	for(;j;j>>=1,i=i*i%mod)if(j&1)res=res*i%mod;
	return res;
}
LL C(LL a,LL b){return a>b?0:fac[b]*inv(fac[a]*fac[b-a]%mod)%mod;}
//b个里面选a个 
LL lucas(LL a,LL b){return a?C(a%mod,b%mod)*lucas(a/mod,b/mod)%mod:1;}
int main()
{
	int T;cin>>T;
	fac[0]=1;
	while(T--)
	{
		cin>>n>>m>>mod;
		for(int i=1;i<mod;i++)fac[i]=fac[i-1]*i%mod;
		cout<<lucas(m,n+m)<<endl;
	}
	return 0;
}
