
const int maxn=200010;
struct gra {
	bool vis[maxn];
    int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt;
    int dis[maxn],c[maxn];
    int f[maxn << 1],N;
    void clear(int n) {N=n,fill(head, head+5+n, 0),cnt = 0;}
    void add(int a, int b, int c) {nxt[++cnt] = head[a], to[head[a] = cnt] = b, f[cnt] = c;}
    bool spfa(int i){
    	queue<int>q;
    	q.push(i),c[i]++;
    	dis[i]=0;
    	while(!q.empty()){
    		i=q.front(),q.pop();
    		vis[i]=0;
    		for(int j=head[i];j;j=nxt[j]){
    			if(dis[to[j]]>dis[i]+f[j]){
    				dis[to[j]]=dis[i]+f[j];
    				if(!vis[to[j]]){
						c[to[j]]++;
    					if(c[to[j]]>N)return 1;
						vis[to[j]]=1,q.push(to[j]);
					}
				}
			}
		}
		return 0;
	}
	bool ne_c(int n,int i){
    	fill(dis,dis+5+n,1000000000);
    	fill(vis,vis+5+n,0);
    	fill(c,c+5+n,0);
		return spfa(i);
	}
}G;
int n,m1,m2;
int edge1[maxn][4],edge2[maxn][4];
bool check(int p){
	G.clear(n+1);
	for(int i=1;i<=m1;i++)
		G.add(edge1[i][2],edge1[i][1]-1,-edge1[i][3]);
	for(int i=1;i<=m2;i++)
		G.add(edge2[i][1]-1,edge2[i][2],p-edge2[i][3]);
	for(int i=1;i<=n;i++)G.add(i,i-1,0),G.add(i-1,i,1);
	G.add(0,n,p),G.add(n,0,-p);
	return G.ne_c(n,0);
}
int main(){
	int T;cin>>T;
	while(T--){
		scanf("%d%d%d",&n,&m1,&m2);
		for(int i=1;i<=m1;i++)
			scanf("%d%d%d",&edge1[i][1],&edge1[i][2],&edge1[i][3]);
		for(int i=1;i<=m2;i++)
			scanf("%d%d%d",&edge2[i][1],&edge2[i][2],&edge2[i][3]);
		int l=0,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}

