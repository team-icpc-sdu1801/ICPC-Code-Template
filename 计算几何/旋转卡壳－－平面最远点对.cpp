//旋转卡壳，平面最远点对
inline int caliper(polygon P) {
    int res = 0;
    if (n == 2){
        res = (p[0] - p[1]).dis2();
    } else if (n == 3) {
        res = max((p[0] - p[1]).dis2(), (p[0] - p[2]).dis2());
        res = max(res, (p[1] - p[2]).dis2());
    } else {
        P.push_back(point(0, 0));
        int m = P.size() - 1;
        int j = 2;
        for (int i = 0; i < m; ++i) {
            while (abs((P[i] - P[i + 1]) ^ (P[j] - P[i + 1])) < abs((P[i] - P[i + 1]) ^ (P[j + 1] - P[i + 1])))
                j = (j + 1) % m;
            res = max(res, (P[i] - P[j]).dis2());
        }
    }
    return res;
}
