//欧拉函数 
typedef long long ll;
const ll N = 10000000;
bool is[N+10];
int prime[N+10], cnt;
int phi[N+10];
ll n, ans;
void init(){
    phi[1] = 1;
    is[1] = is[0] = 1;
    for(int i = 2; i <= N; i ++){
        if(!is[i]) prime[++cnt] = i, phi[i] = prime[cnt]-1;
        for(int j = 1; j <= cnt; j ++){
            if(i*prime[j] >= N) break;
            is[i*prime[j]] = 1;
            if(i % prime[j] == 0){
                phi[i*prime[j]] = phi[i] * prime[j];
                break;
            }else phi[i*prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

//约数个数
//d 约数个数     num 最小素因子的个数 
typedef long long ll;
const ll N = 10000000;
bool is[N+10];
int prime[N+10], cnt;
int d[N+10], num[N+10];
ll n, ans; 
void init(){
    phi[1] = 1;
    is[1] = is[0] = 1;
    for(int i = 2; i <= N; i ++){
        if(!is[i]) prime[++cnt] = i, d[i] = 2, num[i] = 1;
        for(int j = 1; j <= cnt; j ++){
            if(i*prime[j] >= N) break;
            is[i*prime[j]] = 1;
            if(i % prime[j] == 0){
            	num[i*prime[j]] = num[i] + 1;
                d[i*prime[j]] = d[i] / (num[i] + 1) * (num[i*prime[j]]+1);
                break;
            }else d[i*prime[j]] = d[i] * d[prime[j]], num[i*prime[j]] = 1;
        }
    }
}

//约数和 
//sd 约数和  sp     表示从1到最小素因子的最大幂次的和 
typedef long long ll;
const ll N = 10000000;
bool is[N+10];
int prime[N+10], cnt;
int sd[N+10], sp[N+10];
ll n, ans; 
void init(){
    phi[1] = 1;
    is[1] = is[0] = 1;
    for(int i = 2; i <= N; i ++){
        if(!is[i]) prime[++cnt] = i, sd[i] = i + 1, sp[i] = i + 1;
        for(int j = 1; j <= cnt; j ++){
            if(i*prime[j] >= N) break;
            is[i*prime[j]] = 1;
            if(i % prime[j] == 0){
            	sp[i*prim[j]] = sp[i] * prim[j] + 1;
                sd[i*prim[j]] = sd[i] / sp[i] * sp[i*prim[j]];
                break;
            }else sd[i*prim[j]] = sd[i] * sd[prim[j]], sp[i*prim[j]] = 1 + prim[j];
        }
    }
}
