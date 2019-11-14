
LL a[MAXN][MAXN];
const LL mod=1e9;
void add(int u,int v){//加边 双向 
	a[u][u]++,a[v][v]++;
	a[u][v]--,a[v][u]--; 
}
int Gauss(int n){//高斯消元 
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			while(a[k][i]){
				int d=a[i][i]/a[k][i];
				for(int j=i;j<=n;j++)a[i][j]=(a[i][j]-1ll*d*a[k][j]%mod+mod)%mod;
				swap(a[i],a[k]),ans=-ans;
			}
		}
		ans=1ll*ans*a[i][i]%mod,ans=(ans%mod+mod)%mod;
	}
	return ans;
}
int n,m,id[MAXN][MAXN];
char s[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int idx=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')id[i][j]=++idx;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(id[i][j]){
				if(id[i-1][j])add(id[i][j],id[i-1][j]);
				if(id[i][j-1])add(id[i][j],id[i][j-1]); 
			}
	cout<<Gauss(idx-1);
	return 0;
}


