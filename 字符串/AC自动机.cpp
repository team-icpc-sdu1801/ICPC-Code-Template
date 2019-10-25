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
//有很多题需要判断是否是终点，在求fail结点的时候可以顺便求一下
if (tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], idx[tr[u][i]] |= idx[fail[tr[u][i]]], q.push(tr[u][i]);
//矩阵快速幂求出现过给定字符串的的所有长度的串
typedef unsigned long long ull;
struct rec{
	int sz;
	ull a[N][N];
	rec(){}
	void init(int _sz){
		sz = _sz;
		memset(a, 0, sizeof(a));
	}
	rec operator* (const rec &b) const {
		rec res;
		res.init(sz);
		for (int i = 0; i <= sz; ++i){
			for (int j = 0; j <= sz; ++j){
				for (int k = 0; k <= sz; ++k)
					res.a[i][j] += a[i][k] * b.a[k][j];
			}
		}
		return res;
	}
}e, ans, res;
inline rec qpow(rec a, long long q){
	rec res = e;
	for (;q; q >>= 1, a = a * a){
		if (q & 1) res = res * a;
	}
	return res;
}
//省略了init和insert
namespace AC{
	queue<int>q;
	void build(){
		for (int i = 0; i < 26; ++i)
			if (tr[0][i]) q.push(tr[0][i]);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; ++i){
				if (tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], idx[tr[u][i]] |= idx[fail[tr[u][i]]], q.push(tr[u][i]);
				else tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	inline rec chengzi(){
		res.init(tot + 1);
		for (int i = 0; i <= tot; ++i){
			if (idx[i]) res.a[i][tot + 1] = 1, res.a[i][i] = 26; 
			else for (int j = 0; j < 26; ++j){
				res.a[i][tr[i][j]]++;
			}
		}
		res.a[tot + 1][tot + 1] = 1;
		return res;
	}
};
