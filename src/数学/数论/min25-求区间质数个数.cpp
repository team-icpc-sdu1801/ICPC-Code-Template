#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
#define mem(Arr,x) memset(Arr,x,sizeof(Arr))

const int maxN=1001000;
const int inf=2147483647;

ll n,srt;
ll G[maxN];
ll num,Num[maxN+maxN],Id[maxN+maxN];
bool notprime[maxN];
int pcnt,P[maxN];

void Init(){
	notprime[1]=1;
	for (int i=2;i<maxN;i++){
		if (notprime[i]==0) P[++pcnt]=i;
		for (int j=1;(j<=pcnt)&&(1ll*i*P[j]<maxN);j++){
			notprime[i*P[j]]=1;
			if (i%P[j]==0) break;
		}
	}
	return;
}
int GetId(ll x){
	if (x<=srt) return Id[x];
	else return Id[n/x+maxN];
}
ll S(ll n,int j);

int main(){
	Init();
	scanf("%lld",&n);srt=sqrt(n);
	for (ll i=1,j;i<=n;i=j+1){
		j=n/(n/i);Num[++num]=n/i;G[num]=n/i-1;
		if (n/i<=srt) Id[n/i]=num;
		else Id[i+maxN]=num;
	}
	for (int j=1;j<=pcnt;j++)
		for (int i=1;(i<=num)&&(1ll*P[j]*P[j]<=Num[i]);i++)
			G[i]=G[i]-G[GetId(Num[i]/P[j])]+(j-1);
	printf("%lld\n",G[1]);
}




