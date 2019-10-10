//AC自动机求最大出现次数
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 156, L = 1e6 + 6;
namespace AC{
    const int SZ = N * 80;
    int tot, tr[SZ][26];
    int fail[SZ], idx[SZ], val[SZ];
    int cnt[N];
    void init(){
        memset(fail, 0, sizeof(fail));
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        memset(cnt, 0, sizeof(cnt));
        memset(idx, 0, sizeof(idx));
        tot = 0;
    }
    void insert(char *s, int id){
        int u = 0;
        for (int i = 1; s[i]; i++){
            if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
        u = tr[u][s[i] - 'a'];
        }
        idx[u] = id;
    }
    queue<int> q;
    void build(){
        for (int i = 0; i < 26; ++i)
            if (tr[0][i]) q.push(tr[0][i]);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i){
                if (tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
                else tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    inline int query(char *t){
        int u = 0, res = 0;
        for (int i = 1; t[i]; i++){
            u = tr[u][t[i] - 'a'];
            for (int j = u; j; j = fail[j]) val[j]++;
        }
        for (int i = 0; i <= tot; ++i)
            if (idx[i]) res = max(res, val[i]), cnt[idx[i]] = val[i];
        return res;
    }
}
int n;
char s[N][100], t[L];
int main()
{
    while(~scanf("%d", &n)){
        if (n == 0) break;
        AC::init();
        for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1), AC::insert(s[i], i);
        AC::build();
        scanf("%s", t + 1);
        int x = AC::query(t);
        printf("%d\n", x);
        for (int i = 1; i <= n; ++i)
            if (AC::cnt[i] == x) printf("%s\n", s[i] + 1);
    }
    return 0;
}