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
