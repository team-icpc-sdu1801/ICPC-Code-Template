#define LL long long
using namespace std;
typedef long long ll;
const ll N = 5000000;
bool is[N + 10];
int prime[N + 10], cnt;
LL miu[N + 10], phi[N + 10];

void init() {
    phi[1] = miu[1] = 1;
    is[1] = is[0] = 1;
    for (int i = 2; i <= N; i++) {
        if (!is[i]) prime[++cnt] = i, miu[i] = -1, phi[i] = prime[cnt] - 1;
        for (int j = 1; j <= cnt; j++) {
            if (i * prime[j] >= N) break;
            is[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                miu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else miu[i * prime[j]] = -miu[i], phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for (int i = 1; i <= N; i++)miu[i] += miu[i - 1], phi[i] += phi[i - 1];
}
unordered_map<int, LL> ansmiu, ansphi;
LL S_phi(int n) {
    if (n <= N)return phi[n];
    if (ansphi[n])return ansphi[n];
    LL ans = 0;
    for (int l = 2, r; l <= n; l = r + 1)
        r = n / (n / l), ans += (r - l + 1) * S_phi(n / l);
    return ansphi[n] = 1ll * (LL) n * (n + 1) / 2 - ans;//杜教筛公式
}
LL S_miu(int n) {
    if (n <= N)return miu[n];
    if (ansmiu[n])return ansmiu[n];
    LL ans = 0;
    for (int l = 2, r; l <= n; l = r + 1)
        r = n / (n / l), ans += (r - l + 1) * S_miu(n / l);
    return ansmiu[n] = 1ll - ans;//杜教筛公式 
}
int n;
int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        printf("%lld %lld\n", S_phi(n), S_miu(n));
    }
    return 0;
}

