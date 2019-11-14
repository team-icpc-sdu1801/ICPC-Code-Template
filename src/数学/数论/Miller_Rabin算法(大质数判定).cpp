#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define ull unsigned long long
#define ld long double
#define inl inline
#define re register
#define MAXN 10100
using namespace std;
inl ll ksc(ull x,ull y, ll p){return (x*y-(ull)((ld)x/p*y)*p+p)%p;}
inl ll ksm(ll x,ll y,ll p)
{
	ll res=1;
	for(;y;y>>=1,x=ksc(x,x,p))if(y&1)res=ksc(res,x,p);
	return res;
}
inl bool mr(ll x,ll p)
{
	if(ksm(x,p-1,p)!=1)return 0;
	ll y=p-1,z;
	while(!(y&1))
	{
		y>>=1;z=ksm(x,y,p);
		if(z!=1&&z!=p-1)return 0;
		if(z==p-1)return 1;
	}
	return 1;
}
int te_pri[20]={0,2,3,5,7,43,61,24251},te_num=7;
inl bool isprime(ll x)
{
	if(x<2)return 0;
	for(int i=1;i<=te_num;i++)
		if(x==te_pri[i])return 1;
	for(int i=1;i<=te_num;i++)
		if(!(x%te_pri[i])||!mr(te_pri[i],x))return 0;
	return 1;
}
int main()
{
	return 0;
}

