#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
const int N = 50010, L = 1e6 + 6;
int pos[N];
namespace AC{
    const int SZ = 100010;
    int tot;
    int vis[SZ], cnt[SZ], val[SZ];
    int fail[SZ];
    map<int, int> tr[SZ];
    void insert(int *s, int l, int id){
        int u = 0;
        for (int i = 1; i <= l; i++){
            if (!tr[u][s[i]]) tr[u][s[i]] = ++tot;
            u = tr[u][s[i]];    
            // cout<<u<<' ';
        }
        pos[id] = u;
        val[u]++;
        // cout<<endl;
    }   
    queue<int>q;
    inline void build(){
        for (auto i:tr[0]) q.push(i.second);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            // cout<<u<<endl;
            for (auto i:tr[u]){
                fail[i.second] = tr[fail[u]][i.first], q.push(i.second);
            }   
        }
    }
    inline int query(int id, vector<int>t1){
        int u = 0, res = 0;
        int l = t1.size();
        for (int i = 0; i < l; i++){
            while(u && !tr[u][t1[i]]) u = fail[u];
            u = tr[u][t1[i]];
            for (int j = u; j; j = fail[j]){
                if (vis[j] != id){
                    cnt[j]++, vis[j] = id;
                    if (val[j]) res += val[j]; 
                }
                else break;
            }    
        }
        return res;
    }
}
vector<int> q1[N], q2[N];
int t[N * 2], ans[N];
