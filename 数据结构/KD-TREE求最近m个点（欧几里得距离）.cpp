//非动态开点
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#define sqr(x) (x) * (x)
const int N = 50010;
int n, k, idx;

struct Node{
	int f[5];
	bool operator < (const Node &u) const {
		return f[idx] < u.f[idx];
	}
}_data[N];

priority_queue<pair<double, Node> > Q;

struct KDT{
	Node val[4 * N];
	int flag[4 * N];
	void Build(int, int, int, int); //data[] 数组表示KDT的所有节点数据
	void Query(Node, int, int, int); // 用于标记某个节点是否存在， 1表示存在， -1表示不存在
}kd;

void KDT::Build(int l, int r, int x, int dept){// dept 表示深度
	if (l > r) return;
	flag[x] = 1;
	flag[x << 1] = flag[x << 1 | 1] = -1;
	idx = dept % k;
	int mid = (l + r) >> 1;
	nth_element(_data + l, _data + mid, _data + r + 1); 

	val[x] = _data[mid];
	Build(l, mid - 1, x << 1, dept + 1);
	Build(mid + 1, r, x << 1 | 1, dept + 1);
}

void KDT::Query(Node p, int m, int x, int dept){// 寻找离p最近的m个特征属性
	if (flag[x] == -1) return;
	pair<double, Node> cur(0, val[x]);
	for (int i = 0; i < k; ++i)
		cur.first += sqr(cur.second.f[i] - p.f[i]);
	int dim = dept % k; // 保证相同节点dim值不变
	bool fg = 0;	//标记是否需要遍历右子树
	int lson = x << 1;
	int rson = x << 1 | 1;
	if (p.f[dim] >= val[x].f[dim]) swap(lson, rson); //p点dim大于当前数据，则进入右子树
	if (~flag[lson]) Query(p, m, lson, dept + 1);	//节点lson存在，则进入子树进行遍历

	if (Q.size() < m) Q.push(cur), fg = 1; //若队列未满，放入
	else {
		if (cur.first < Q.top().first) Q.pop(), Q.push(cur);//若找到更小的距离，替换最大距离点数据
		if (sqr(p.f[dim] - val[x].f[dim]) < Q.top().first) fg = 1;
	}
	if (~flag[rson] && fg) Query(p, m, rson, dept + 1);
}
int main()
{
	while(scanf("%d%d", &n, &k) != EOF){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < k; ++j)
				scanf("%d", &_data[i].f[j]);
		kd.Build(0, n - 1, 1, 0);
		int t, m;
		scanf("%d", &t);
		while(t--){
			Node p;
			for (int i = 0; i < k; ++i) scanf("%d", &p.f[i]);
			scanf("%d", &m);
			while(!Q.empty()) Q.pop();
			kd.Query(p, m, 1, 0);
			printf("the closest %d points are:\n", m);
			Node tmp[25];
			for (int i = 0; !Q.empty(); ++i){
				tmp[i] = Q.top().second;
				Q.pop();
			}
			for (int i = m - 1; i >= 0; --i){
				for (int j = 0; j < k; ++j)
					printf("%d%c", tmp[i].f[j], j == k - 1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}