#define size 60
struct LinearBase
{
	LL v[size+7],p[size+7];
	int cnt=0;
	bool now=0,flag;
	void clear(){
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		cnt=0;flag=now=0;
	}
	void ins(LL a){
		now=0;
		for(int i=size;i>=0;i--)
			if(a&(1ll<<i)){
				if(!v[i]){v[i]=a;break;}
				a^=v[i];
			}
		if(!a)flag=1;
	}
	bool find(LL a){
		if(!a&&flag)return 1;
		for(int i=size;i>=0;i--)
			if(a&(1ll<<i)){
				if(!v[i])return 0;
				a^=v[i];
			}
		return 1;
	}
	LL getmax(){
		LL anss=0;
		for(int i=size;i>=0;i--)if((anss^v[i])>anss)anss^=v[i];
		return anss;
	}
	LL getmin(){
		if(flag)return 0;
		for(int i=0;i<=size;i++)if(!v[i])return v[i];
	}
	void rebuild(){
		now=1,cnt=0;
		memset(p,0,sizeof(p));
		for(int i=size;i>=0;i--)
			for(int j=i-1;j>=0;j--)
				if(v[i]&(1ll<<j))v[i]^=v[j];
		for(int i=0;i<=size;i++)if(v[i])p[cnt++]=v[i];
	}
	LL kth_min(LL k){
		if(!now)rebuild();
		LL res=0;
		if(flag)k--;
		if(k>=(1LL<<cnt))return -1;
		for(int i=size;i>=0;i--)if(k&(1LL<<i))res^=p[i];
		return res;
	}
	LL kth_max(LL k){
		if(!now)rebuild();
		LL t=(1LL<<cnt);
		if(flag)t--;
		return kth_min(t-k+1);
	}
	LinearBase operator+(const LinearBase &a){
		LinearBase c=a;
		for(int i=0;i<=size;i++)if(v[i])c.ins(v[i]);
		return c;
	}
	friend LinearBase operator*(const LinearBase &a,const LinearBase &b){
		LinearBase all,c,d;
		all.clear(),c.clear(),d.clear();
		for(int i=size;i>=0;i--)all.v[i]=a.v[i];
		for(int i=size;i>=0;i--){
			if(b.v[i]){
				LL v=b.v[i],k=1LL>>i;
				bool can=1;
				for(int j=size;j>=0;j--)
					if(v&(1ll<<j))
						if(all.v[j])v^=all.v[i],k^=d.v[j];
						else{can=0,all.v[j]=v,d.v[j]=k;break;}
				if(can){
					LL v=0;
					for(int j=size;j>=0;j--)if(k&(1ll<<j))v^=b.v[j];
					c.ins(v);
				}
			}
		}
		return all; 
	}
};
int main()
{
	return 0;
}


