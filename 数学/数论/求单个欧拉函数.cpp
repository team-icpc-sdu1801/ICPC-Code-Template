typedef long long ll;
bool is[100010];
ll prime[100010], cnt;
ll n;
ll phi(ll x){
    ll ans = x, i;
    for(i = 1; prime[i] <= x && i <= cnt; i ++){
        if(x % prime[i] == 0) ans = ans/prime[i]*(prime[i]-1);
        while(x % prime[i] == 0) x /= prime[i];
    }
    if(x != 1) ans = ans/x*(x-1);
    return ans;
}
void init(){
    is[1] = is[0] = 1;
    for(int i = 2; i <= 100000; i ++){
        if(!is[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt; j ++){
            if(i*prime[j] >= 100000) break;
            is[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
