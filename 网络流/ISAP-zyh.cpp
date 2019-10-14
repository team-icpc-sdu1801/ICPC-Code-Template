//注意：te初值为1， mx为总点数， head记得清空
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

const int N = 510, M = 100010;
const int inf = 0x3f3f3f3f;
int te;
int head[N];
struct edge{
    int u, v, f, nxt;    
}e[M];
inline void add(int u, int v, int cap){
    e[++te] = (edge){u, v, cap, head[u]};
    head[u] = te;
}
int dep[N], vm[N], q[N], cur[N], s, t, mx;
void bfs(){
    for (int i = 0; i <= mx; ++i) dep[i] = -1, vm[i] = 0;
    int l = 1, r = 0;
    q[++r] = t, dep[t] = 1, vm[1] = 1;
    while(l <= r){
        int x = q[l++];
        for (int i = head[x]; i; i = e[i].nxt){
            int v = e[i].v;
            if (dep[v] == -1)
                dep[v] = dep[x] + 1, vm[dep[v]]++, q[++r] = v;
        }
    }
}
inline int dfs(int x, int mr){
    if (x == t || mr == 0) return mr;
    int c = 0, res = 0;
    for (int &i = cur[x]; i; i = e[i].nxt){
        int v = e[i].v;
        if (e[i].f && dep[v] + 1 == dep[x] && (c = dfs(v, min(e[i].f, mr))))
            e[i].f -= c, e[i ^ 1].f += c, mr -= c, res += c;
        if (mr == 0) return res;
    }
    if (-- vm[dep[x]] == 0) dep[s] = mx + 1;
    dep[x]++, vm[dep[x]]++;
    return res;
}
int res;
void isap(){
    bfs();
    while(dep[s] <= mx){
        for (int i = 0; i <= mx; ++i) cur[i] = head[i];
        res += dfs(s, inf);
        // cout<<11111<<' '; cout<<res<<endl;
    }
}
int n;
