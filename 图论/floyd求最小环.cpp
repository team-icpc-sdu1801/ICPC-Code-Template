#include<algorithm>
#include<iostream>
#include<cstdio>
#define INF 0x3f3f
#define MAXN 511
using namespace std;
int dis[MAXN][MAXN], mp[MAXN][MAXN], n, m;
int mincost_route(){
    int mincost = INF;
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i < k; i ++)
            for(int j = i+1; j < k; j ++)
                mincost = min(mincost, dis[i][j] + mp[i][k] + mp[k][j]);
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    return mincost;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            mp[i][j] = dis[i][j] = INF;
    for(int u, v, w, i = 1; i <= m; i ++){
        scanf("%d%d%d",&u, &v, &w);
        mp[u][v] = mp[v][u] = dis[u][v] = dis[v][u] = min(w, mp[u][v]);
    }
    cout << mincost_route() << endl;
}
