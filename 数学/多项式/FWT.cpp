#include<iostream>
#define LL long long
using namespace std;
const int MOD=998244353;
const int inv2=(MOD+1)/2;//逆元 
void FWT_or(LL *a,int N,int opt)//数组(from 0) 数组长度  1 or -1 
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
                if(opt==1)a[i+j+k]=(a[j+k]+a[i+j+k])%MOD;
                else a[i+j+k]=(a[i+j+k]+MOD-a[j+k])%MOD;
}
void FWT_and(LL *a,int N,int opt)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
                if(opt==1)a[j+k]=(a[j+k]+a[i+j+k])%MOD;
                else a[j+k]=(a[j+k]+MOD-a[i+j+k])%MOD;
}
void FWT_xor(LL *a,int N,int opt)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                LL X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%MOD;a[i+j+k]=(X+MOD-Y)%MOD;
                if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%MOD,a[i+j+k]=1ll*a[i+j+k]*inv2%MOD;
            }
}
LL A[(1<<17)|1],B[(1<<17)|1];
LL a[(1<<17)|1],b[(1<<17)|1];
int main()
{
	int n;cin>>n;
	int N=(1<<n);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	for(int i=0;i<N;i++)scanf("%lld",&B[i]);
	
	for(int i=0;i<N;i++)a[i]=A[i],b[i]=B[i];
	FWT_or(a,N,1),FWT_or(b,N,1);
	for(int i=0;i<N;i++)a[i]=a[i]*b[i]%MOD;
	FWT_or(a,N,-1); 
	for(int i=0;i<N;i++)printf("%lld%c",a[i]," \n"[i+1==N]);
	
	for(int i=0;i<N;i++)a[i]=A[i],b[i]=B[i];
	FWT_and(a,N,1),FWT_and(b,N,1);
	for(int i=0;i<N;i++)a[i]=a[i]*b[i]%MOD;
	FWT_and(a,N,-1); 
	for(int i=0;i<N;i++)printf("%lld%c",a[i]," \n"[i+1==N]);
	
	for(int i=0;i<N;i++)a[i]=A[i],b[i]=B[i];
	FWT_xor(a,N,1),FWT_xor(b,N,1);
	for(int i=0;i<N;i++)a[i]=a[i]*b[i]%MOD;
	FWT_xor(a,N,-1); 
	for(int i=0;i<N;i++)printf("%lld%c",a[i]," \n"[i+1==N]);
	return 0;
}


