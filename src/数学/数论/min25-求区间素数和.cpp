#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
#define ld long double
#define mem(Arr,x) memset(Arr,x,sizeof(Arr))

const int maxN=1010000;
const int inf=2147483647;

ll nn,srt;
bool notprime[maxN];
int pcnt,P[maxN];
ll num,Num[maxN+maxN],Id[maxN+maxN];
ld G[maxN+maxN],Sum[maxN];

ld Calc(ll n);
void Init();
int GetId(ll x);

int main(){
	Init();
	ll L,R;scanf("%lld%lld",&L,&R);
	printf("%.0LF\n",Calc(R)-Calc(L-1));return 0;
}

ld Calc(ll n){
	if (n==0) return 0;
	srt=sqrt(n);nn=n;num=0;mem(Id,0);mem(G,0);mem(Num,0);
	for (ll i=1,j;i<=n;i=j+1){
		j=n/i;Num[++num]=j;G[num]=(j<=1)?(0):((ld)(j-1)*(ld)(j+2)/2.0);
		if (j<=srt) Id[j]=num;
		else Id[i+maxN]=num;
		j=n/j;
	}
	for (int j=1;j<=pcnt;j++){
		for (int i=1;(i<=num)&&(1ll*P[j]*P[j]<=Num[i]);i++){
			G[i]=G[i]-1ll*P[j]*(G[GetId(Num[i]/P[j])]-Sum[j-1]);
		}
	}
	return G[1];
}

void Init(){
	notprime[1]=1;
	for (int i=1;i<maxN;i++){
		if (notprime[i]==0) P[++pcnt]=i,Sum[pcnt]=Sum[pcnt-1]+i;
		for (int j=1;(j<=pcnt)&&(1ll*i*P[j]<maxN);j++){
			notprime[i*P[j]]=1;if (i%P[j]==0) break;
		}
	}
	return;
}

int GetId(ll x){
	if (x<=srt) return Id[x];
	else return Id[nn/x+maxN];
}
