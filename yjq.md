[TOC]

### 对拍

创建文件夹，以/duipai为例。文件夹中放4个cpp文件。
A/A.cpp和B/B.cpp分别为标程（暴力）和源文件。
data/data.cpp为数据生成文件。
duipai/duipai.cpp表示对拍文件。
A和B的源代码中都应打开data.out作为读入文件，分别以std.out和test.out作为输出文件。注意linux下文件路径应为绝对路径。
duipai.cpp中代码如下

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int i;
	for(i = 1;;i++){
		printf("Data %d",i);
		system("./data");
		system("./A");
		system("./B");
		if(system("diff std.out test.out")){
			printf("WA\n");
			return 0;
		}
		else printf("AC\n");
	}
	return 0;
}
```
在命令行中（注意要到该文件夹的目录下）编译4份源代码：
```cpp
g++ A.cpp -o A
g++ B.cpp -o B
g++ data.cpp -o data
g++ duipai.cpp -o duipai
```
运行duipai
```cpp
./duipai
```



### *0.Java & C++*
##### *0.1Java快速I/O*
###### *0.1.1个人常用模板*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;
 
public class Main {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
 
    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }
 
    static double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }
 
    static long nextLong() throws IOException {
        in.nextToken();
        return (long) in.nval;
    }
 
    static String next() throws IOException {
        in.nextToken();
        return in.sval;
    }
 
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
 
    public static void main(String[] args) throws IOException {
        /*
        
         */
        out.flush();
    }
}
```

###### *0.1.2 CF上的快速I/O（速度最快？？？）*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
	  /*
	   写代码
	  */
        out.flush();
        out.close();
    }
 
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);
 
    static class FastReader {
        private InputStream mIs;
        private byte[] buf = new byte[1024];
        private int curChar, numChars;
 
        public FastReader() {
            this(System.in);
        }
 
        public FastReader(InputStream is) {
            mIs = is;
        }
 
        public int read() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = mIs.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }
 
        public String nextLine() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }
 
        public String next() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
 
        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
 
        public void scanIntArr(int[] arr) {
            for (int li = 0; li < arr.length; ++li) {
                arr[li] = nextInt();
            }
        }
 
        public void scanLongArr(long[] arr) {
            for (int i = 0; i < arr.length; ++i) {
                arr[i] = nextLong();
            }
        }
 
        public void shuffle(int[] arr) {
            for (int i = arr.length; i > 0; --i) {
                int r = (int) (Math.random() * i);
                int temp = arr[i - 1];
                arr[i - 1] = arr[r];
                arr[r] = temp;
            }
        }
    }
}
```
###### *0.1.3Petr的快速IO*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;
 
public class Main {
    static InputReader in = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) throws IOException {
        /*
         * */
        out.close();
    }
 
    static class InputReader {
        BufferedReader br;
 
        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }
 
        public int nextInt() throws IOException {
            int c = br.read();
            while (c <= 32) {
                c = br.read();
            }
            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = br.read();
            }
            int x = 0;
            while (c > 32) {
                x = x * 10 + c - '0';
                c = br.read();
            }
            return negative ? -x : x;
        }
 
        public long nextLong() throws IOException {
            int c = br.read();
            while (c <= 32) {
                c = br.read();
            }
            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = br.read();
            }
            long x = 0;
            while (c > 32) {
                x = x * 10 + c - '0';
                c = br.read();
            }
            return negative ? -x : x;
        }
 
        public String next() throws IOException {
            int c = br.read();
            while (c <= 32) {
                c = br.read();
            }
            StringBuilder sb = new StringBuilder();
            while (c > 32) {
                sb.append((char) c);
                c = br.read();
            }
            return sb.toString();
        }
 
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
```
###### *0.1.4 常用快速IO*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;
 
public class Main {
 
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tok;
 
    static boolean hasNext() {
        while (tok == null || !tok.hasMoreTokens())
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return false;
            }
        return true;
    }
 
    static String next() {
        hasNext();
        return tok.nextToken();
    }
 
    static String nextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            return null;
        }
    }
 
    static long nextLong() {
        return Long.parseLong(next());
    }
 
    static int nextInt() {
        return Integer.parseInt(next());
    }
 
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
 
 
    public static void main(String[] args) throws IOException {
        /*
         * */
        out.flush();
    }
}
```
##### *0.2 C++ STL*
###### *0.2.1 lower_bound&upper_bound*

```cpp
/*
    lower_bound()    返回键值>=给定元素的第一个位置
    upper_bound()     返回键值>给定元素的第一个位置
*/
//函数版a[1,...,n]中查找元素x
    int pos = lower_bound(a + 1, a + 1 + n, x) - a;
//pos为第一个大于x的数所在的地址
//若x大于a中所有数，则pos>n;若x小于所有数则pos<=1

//vector版
    int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
//若x不存在，则返回v.begin()或v.end()
//二者得到的pos相减即可得出x在数组中出现的次数
```
###### *0.2.2 priority_queue*

```cpp
//优先队列定义越小的优先级越大的
//注意：后面的两个'>'之间要加空格
priority_queue<int, vector<int>, greater<int> > q;
```
###### *0.2.3 set*

```cpp
//访问set中的元素（迭代器）
    set<int> s;
//...
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << ' ';

```
###### *0.2.4 map*

```	cpp
/*
    map中的成员函数：
        clear()清空
        count(x)返回x的出现次数
        empty()返回是否为空
        size()返回元素个数
*/
/*
假设映射为m[x]=y
    find(x)返回该映射的迭代器
    同样支持lower_bound和upper_bound
    erease(it)删除迭代器it所指向的映射
*/
    map<int, int>::iterator it = m.find(x);
    m.erase(it);//清除m[x]=y
    //用迭代器访问m中的所有元素
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << ' ' << it->second << endl;
    //it->first表示x，it->second表示y

```
###### *0.2.5 sort&permutation*

```cpp
/*
        next_permutation 下一个排列
        prev_permutation 前一个排列
*/
 
 
/*
        stable_sort() 对给定区间所有元素进行稳定排序
        vector set等均可通过sort进行排序，其默认优先级为：
                [例]
                {-3,-2}
                {-3,-2,-1}
                {1,2,3,4,6}
                {1,2,6,9}
                {2,3,6,7,8}
*/
```
##### *0.3 C++快速读入*

```cpp
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline bool _read(ll &sum) {
    char ch = nc();
    if (ch == EOF)
        return 0;
    sum = 0;
    while (!(ch >= '0' && ch <= '9'))ch = nc();
    while (ch >= '0' && ch <= '9')sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
```

##### *0.4 Java示例*

###### *0.4.1 Java Kruskal示例*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;

public class D {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tok;

    static boolean hasNext() {
        while (tok == null || !tok.hasMoreTokens())
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return false;
            }
        return true;
    }

    static String next() {
        hasNext();
        return tok.nextToken();
    }

    static String nextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static final int maxn = 2005;
    static int n;
    static int x[] = new int[maxn];
    static int y[] = new int[maxn];
    static int p[] = new int[maxn];
    static long c[] = new long[maxn];
    static long k[] = new long[maxn];

    static class Edge {
        public int u, v;
        public long w;

        Edge(int x, int y, long z) {
            u = x;
            v = y;
            w = z;
        }
    }

    static int find(int x) {
        return (p[x] == x) ? x : (p[x] = find(p[x]));
    }

    public static void main(String[] args) throws IOException {
        n = nextInt();
        for (int i = 1; i <= n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        for (int i = 1; i <= n; ++i) c[i] = nextInt();
        for (int i = 1; i <= n; ++i) k[i] = nextInt();
        for (int i = 1; i <= n; ++i) p[i] = i;
        ArrayList<Edge> E = new ArrayList<>();
        for (int i = 1; i <= n; ++i) E.add(new Edge(0, i, c[i]));
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                E.add(new Edge(i, j, (k[i] + k[j]) * (Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]))));
            }
        }
        Collections.sort(E, (o1, o2) -> (Long.signum(o1.w - o2.w)));
        ArrayList<Integer> v1 = new ArrayList<>();
        ArrayList<int[]> v2 = new ArrayList<>();
        long ct = 0;
        for (Edge i : E) {
            int x = find(i.u), y = find(i.v);
            if (x != y) {
                ct += i.w;
                p[x] = y;
                if (i.u == 0) v1.add(i.v);
                else v2.add(new int[]{i.u, i.v});
            }
        }
        out.println(ct);
        out.println(v1.size());
        for (Integer i : v1) out.print(i + " ");
        out.println();
        out.println(v2.size());
        for (int[] i : v2) out.print(i[0] + " " + i[1] + "\n");
        out.flush();
    }
}

```

###### *0.4.2 Java Prim示例*

```java
import java.io.*;
import java.lang.*;
import java.rmi.*;
import java.security.*;
import java.util.*;
import java.math.*;

public class Main {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tok;

    static boolean hasNext() {
        while (tok == null || !tok.hasMoreTokens())
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return false;
            }
        return true;
    }

    static String next() {
        hasNext();
        return tok.nextToken();
    }

    static String nextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static final int maxn = 2005;
    static int n;
    static int x[] = new int[maxn];
    static int y[] = new int[maxn];
    static long c[] = new long[maxn];
    static long k[] = new long[maxn];
    static boolean vis[] = new boolean[maxn];

    public static void main(String[] args) throws IOException {
        n = nextInt();
        for (int i = 1; i <= n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        for (int i = 1; i <= n; ++i) c[i] = nextInt();
        for (int i = 1; i <= n; ++i) k[i] = nextInt();
        PriorityQueue<long[]> Q = new PriorityQueue<>(new Comparator<long[]>() {
            public int compare(long[] o1, long[] o2) {
                return Long.signum(o1[0] - o2[0]);
            }
        });
        for (int i = 1; i <= n; ++i) Q.add(new long[]{c[i], (long) 0, (long) i});
        ArrayList<Integer> v1 = new ArrayList<>();
        ArrayList<int[]> v2 = new ArrayList<>();
        long ct = 0;
        vis[0] = true;
        while (!Q.isEmpty()) {
            long[] u = Q.poll();
            if (vis[(int) u[2]]) continue;
            ct += u[0];
            if (u[1] == 0) v1.add((int) u[2]);
            else v2.add(new int[]{(int) u[1], (int) u[2]});
            vis[(int) u[2]] = true;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    long d = (k[(int) u[2]] + k[i]) * (Math.abs(x[(int) u[2]] - x[i]) + Math.abs(y[(int) u[2]] - y[i]));
                    if (d < c[i]) {
                        c[i] = d;
                        Q.add(new long[]{d, u[2], i});
                    }
                }
            }
        }
        out.println(ct);
        out.println(v1.size());
        for (Integer i : v1) out.print(i + " ");
        out.println();
        out.println(v2.size());
        for (int[] i : v2) out.print(i[0] + " " + i[1] + "\n");
        out.flush();
    }
}

```

### *1.数学*
##### *1.1矩阵*
###### *1.1.1高斯消元*

代码：

```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
 
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
const int inf = 1e9;
const double eps = 1e-10;
 
int n;
double a[110][110];
 
int main() {
    __;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int r = i;
        for (int j = i + 1; j <= n; ++j)
            if (fabs(a[j][i]) - fabs(a[r][i]) >= eps)r = j;
        for (int j = 1; j <= n + 1; ++j)
            swap(a[i][j], a[r][j]);
        if (fabs(a[r][r]) <= eps) {
            cout << "No Solution" << endl;
            return 0;
        }
        for (int j = i + 1; j <= n + 1; ++j) {
            a[i][j] /= a[i][i];
        }
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                for (int k = i + 1; k <= n + 1; ++k) {
                    a[j][k] -= a[j][i] * a[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)cout << fixed << setprecision(2) << a[i][n + 1] << endl;
    return 0;
}
```

###### *1.1.2矩阵快速幂*

```cpp
struct matrix {
    ll num[5][5];
    int m, mod;//需要赋初值或设为全局变量

    matrix() { memset(num, 0, sizeof num); }

    matrix operator*(const matrix &x) {
        matrix c;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= m; ++k) {
                    c.num[i][j] = (c.num[i][j] + num[i][k] * x.num[k][j] + mod) % mod;
                }
            }
        }
        return c;
    }

    matrix &operator=(const matrix &x) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                num[i][j] = x.num[i][j];
            }
        }
        return *this;
    }
};

matrix pow_mod(matrix &x, ll k) {
    matrix ans;
    for (int i = 1; i <= x.m; ++i) {
        ans.num[i][i] = 1;
    }
    while (k) {
        if (k & 1)ans = ans * x;
        x = x * x;
        k >>= 1;
    }
    return ans;
}
```

##### *1.2整除与剩余*
###### *1.2.1欧几里得算法*

```cpp
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
```
###### *1.2.2扩展欧几里得算法*
求取ax + by = gcd(a, b)

代码：

```cpp
void e_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    e_gcd(b, a % b, y, x);
    y -= (a / b) * x;
}
 
/*
    解得ax+by=gcd(a,b)的值，特解:
        x0 = x * c / gcd(a, b);
        y0 = y * c / gcd(a, b);
    所有解即为:
        x = x0 + k * b / gcd(a, b);
        y = y0 - k * a / gcd(a, b);
*/
```
###### *1.2.3*线性乘法逆元

```cpp
/*1 - n的乘法逆元,m为模数*/
    ni[1] = 1;
    for (int i = 2; i <= n; ++i) {
        ni[i] = (m - m / i) * ni[m % i] % m;
    }
```

##### 1.3素数*

###### *1.3.1素数筛法*
线性筛素数O(n)：

```cpp
bool vis[maxn];
int ans[maxn], tot;
 
void get_prime(int n) {
    memset(vis, 1, sizeof(vis));
    vis[0] = vis[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (vis[i]) {
            ++tot;
            ans[tot] = i;
        }
        for (int j = 1; ((j <= tot) && (i * ans[j] <= n)); ++j) {
            vis[i * ans[j]] = 0;
            if (i % ans[j] == 0)break;
        }
    }
}
```
###### *1.3.2素数判定*
素数测试（Miller-Rabin算法）：

```cpp
ll mult_mod(ll a, ll b, ll c) {
    a %= c;
    b %= c;
    ll ret = 0;
    ll tmp = a;
    while (b) {
        if (b & 1) {
            ret += tmp;
            if (ret > c) ret -= c;
        }
        tmp <<= 1;
        if (tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret;
}

ll pow_mod(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

bool check(ll a, ll n, ll x, ll t) {
    ll ret = pow_mod(a, x, n);
    ll last = ret;
    for (int i = 1; i <= t; i++) {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1) return true;
        last = ret;
    }
    if (ret != 1) return true;
    else return false;
}

const int S = 20;//测试次数

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    ll x = n - 1;
    ll t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    srand(time(NULL));
    for (int i = 0; i < S; i++) {
        ll a = rand() % (n - 1) + 1;
        if (check(a, n, x, t)) return false;
    }
    return true;
}
```
###### *1.3.3质因数分解*

```cpp
/*
	质因数分解：
		n表示待分解的整数
		&tot表示不同质因数的个数
		p[i]表示第i个质因数的值
		q[i]表示第i个质因数的指数
    调用方式 factor(n,p,q,tot);
*/
void factor(ll n, ll *p, ll *q, int &tot) {
    ll temp, now;
    temp = (int) sqrt(n);
    tot = 0;
    now = n;
    for (int i = 2; i <= temp; ++i) {
        if (now % i == 0) {
            p[++tot] = i;
            q[tot] = 0;
            while (now % i == 0) {
                ++q[tot];
                now /= i;
            }
        }
    }
    if (now != 1) {
        p[++tot] = now;
        q[tot] = 1;
    }
}
```
##### *1.4欧拉函数*
###### *1.4.1计算欧拉函数*

```cpp
int euler_phi(int n) {
    int m = (int) sqrt(n + 0.5);
    int ans = n;
    for (int i = 2; i <= m; ++i)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)n /= i;
        }
    if (n > 1)ans = ans / n * (n - 1);
    return ans;
}
```
###### *1.4.2筛法构造欧拉函数表*

```cpp
int phi[maxn];
 
void phi_table(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {
            for (int j = i; j <= n; j += i) {
                if (!phi[j])phi[j] = j;
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}
```
##### *1.5其他*
###### *1.5.1快速幂*

```cpp
#define ll long long
ll pow_mod(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
```

###### *1.5.2 卢卡斯定理*
卢卡斯定理求C(n,m)%p的值
注意：*p*一定为一个不大的素数
**先调用init(*p*);计算所有阶乘的值**
然后lucas(n,m,*p*)即为所求

```cpp
const int maxn = 1e6 + 10;
ll f[maxn];

void init(ll p) {
    f[0] = 1;
    for (int i = 1; i <= p; ++i)
        f[i] = f[i - 1] * i % p;
}

ll pow_mod(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll lucas(ll n, ll m, ll p) {
    ll ans = 1;
    while (n && m) {
        ll a = n % p, b = m % p;
        if (a < b)return 0;
        ans = ans * f[a] % p * pow_mod(f[b] * f[a - b] % p, p - 2, p) % p;
        n /= p;
        m /= p;
    }
    return ans;
}
```

###### *1.5.3 高精度整数（Java）*

```java
import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        BigInteger a, b;
        //以文件EOF结束
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
 
            System.out.println(a.add(b)); //大整数加法
            System.out.println(a.subtract(b)); //大整数减法
            System.out.println(a.multiply(b)); //大整数乘法
            System.out.println(a.divide(b)); //大整数除法(取整)
            System.out.println(a.remainder(b)); //大整数取模
 
            //大整数的比较
            if (a.compareTo(b) == 0) System.out.println("a == b"); //大整数a==b
            else if (a.compareTo(b) > 0) System.out.println("a > b"); //大整数a>b
            else if (a.compareTo(b) < 0) System.out.println("a < b"); //大整数a<b
 
            //大整数绝对值
            System.out.println(a.abs()); //大整数a的绝对值
 
            //大整数的幂
            int exponent = 10;
            System.out.println(a.pow(exponent)); //大整数a的exponent次幂
 
            //返回大整数十进制的字符串表示
            System.out.println(a.toString());
 
            //返回大整数p进制的字符串表示
            int p = 8;
            System.out.println(a.toString(p));
        }
    }
}
```

###### *1.5.4 斐波那契数列求循环节*

```cpp
//先调用getprime()

#define ll unsigned long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

struct Matrix {
    ll mat[2][2];

    Matrix() { memset(mat, 0, sizeof mat); }
};

Matrix mul_M(Matrix a, Matrix b, ll mod) {
    Matrix ans;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j] % mod;
                if (ans.mat[i][j] >= mod)ans.mat[i][j] -= mod;
            }
        }
    }
    return ans;
}

Matrix pow_M(Matrix a, ll n, ll mod) {
    Matrix ans;
    for (int i = 0; i < 2; ++i) ans.mat[i][i] = 1;
    Matrix tmp = a;
    while (n) {
        if (n & 1)ans = mul_M(ans, tmp, mod);
        tmp = mul_M(tmp, tmp, mod);
        n >>= 1;
    }
    return ans;
}

ll pow_m(ll a, ll n, ll mod) {
    ll ans = 1, tmp = a % mod;
    while (n) {
        if (n & 1)ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        n >>= 1;
    }
    return ans;
}

const int maxn = 1e6 + 10;

int prime[maxn];

void getprime() {
    memset(prime, 0, sizeof prime);
    for (int i = 2; i <= maxn; ++i) {
        if (!prime[i])prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= maxn; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)break;
        }
    }
}

ll factor[100][2];
int fatcnt;

int getfactors(ll x) {
    fatcnt = 0;
    ll tmp = x;
    for (int i = 1; prime[i] * prime[i] <= tmp; ++i) {
        factor[fatcnt][1] = 0;
        if (tmp % prime[i] == 0) {
            factor[fatcnt][0] = prime[i];
            while (tmp % prime[i] == 0) {
                factor[fatcnt][1]++;
                tmp /= prime[i];
            }
            fatcnt++;
        }
    }
    if (tmp != 1) {
        factor[fatcnt][0] = tmp;
        factor[fatcnt++][1] = 1;
    }
    return fatcnt;
}

int legendre(ll a, ll p) {
    if (pow_m(a, (p - 1) >> 1, p) == 1)return 1;
    else return -1;
}

int f0 = 1;
int f1 = 1;

ll getfib(ll n, ll mod) {
    if (mod == 1)return 0;
    Matrix A;
    A.mat[0][0] = 0;
    A.mat[1][0] = 1;
    A.mat[0][1] = 1;
    A.mat[1][1] = 1;
    Matrix B = pow_M(A, n, mod);
    ll ans = f0 * B.mat[0][0] + f1 * B.mat[1][0];
    return ans % mod;
}

ll fac[maxn];

ll G(ll p) {
    ll num;
    if (legendre(5, p) == 1)num = p - 1;
    else num = 2 * (p + 1);
    int cnt = 0;
    for (ll i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            fac[cnt++] = i;
            if (i * i != num) {
                fac[cnt++] = num / i;
            }
        }
    }
    sort(fac, fac + cnt);
    ll ans;
    for (int i = 0; i < cnt; ++i) {
        if (getfib(fac[i], p) == f0 && getfib(fac[i] + 1, p) == f1) {
            ans = fac[i];
            break;
        }
    }
    return ans;
}

ll find_loop(ll n) {
    getfactors(n);
    ll ans = 1;
    for (int i = 0; i < fatcnt; ++i) {
        ll record = 1;
        if (factor[i][0] == 2)record = 3;
        else if (factor[i][0] == 3)record = 8;
        else if (factor[i][0] == 5)record = 20;
        else record = G(factor[i][0]);
        for (int j = 1; j < factor[i][1]; ++j) {
            record *= factor[i][0];
        }
        ans = lcm(ans, record);
    }
    return ans;
}

```
###### *1.5.5 FFT*
stl complex<double>实现：
```cpp
const int maxn = 5e5 + 10;
const ld PI = acos(-1.0);

#define cp complex<double>
int rev[maxn], ans[maxn];
cp A[maxn], B[maxn];

void FFT(cp *a, int n, int inv) {
    int bit = 0;
    while ((1 << bit) < n)++bit;
    for (int i = 0; i <= n - 1; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if (i < rev[i])swap(a[i], a[rev[i]]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int mid = len >> 1;
        cp unit(cos(PI / mid), inv * sin(PI / mid));
        for (int i = 0; i < n; i += len) {
            cp omega(1, 0);
            for (int j = 0; j < mid; ++j, omega *= unit) {
                cp x = a[i + j], y = omega * a[i + j + mid];
                a[i + j] = x + y;
                a[i + j + mid] = x - y;
            }
        }
    }
    if (inv == -1) {
        for (int i = 0; i <= n; ++i)a[i] /= n;
    }
}

// use FFT
// Array A[0...n-1]
// Array B[0...m-1]
void mul() {
    int bitn = 1;
    while (bitn < n + m)bitn <<= 1;
    FFT(A, bitn, 1);
    FFT(B, bitn, 1);
    for (int i = 0; i < bitn; ++i) {
        A[i] = A[i] * B[i];
    }
    FFT(A, bitn, -1);
    for (int i = 0; i < n + m - 1; ++i) {
        ans[i] += (int) (A[i].real() + 0.5);
    }
}
```

手写complex：

```cpp
const int maxn = 2e6 + 10;
const double PI = acos(-1.0);

struct Complex {
    double x, y;

    Complex(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }

    Complex operator-(const Complex &b) const {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator+(const Complex &b) const {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator*(const Complex &b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

int rev[maxn];

#define cp Complex

void FFT(cp *a, int n, int inv) {
    int bit = 0;
    while ((1 << bit) < n)++bit;
    for (int i = 0; i <= n - 1; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if (i < rev[i])swap(a[i], a[rev[i]]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int mid = len >> 1;
        cp unit(cos(PI / mid), inv * sin(PI / mid));
        for (int i = 0; i < n; i += len) {
            cp omega(1, 0);
            for (int j = 0; j < mid; ++j, omega = omega * unit) {
                cp x = a[i + j], y = omega * a[i + j + mid];
                a[i + j] = x + y;
                a[i + j + mid] = x - y;
            }
        }
    }
    if (inv == -1) {
        for (int i = 0; i <= n; ++i)a[i].x /= n;
    }
}


```

###### *1.5.6 FWT*

```cpp
const int maxn = 5e5 + 10;
const int mod = 998244353;
const int OR = 1, AND = 2, XOR = 3, XNOR = 4;

int add(int x, int y) {
    return (x += y) >= mod ? x - mod : x;
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + mod : x;
}

void fwt(int op, int *a, int n, int rev) {
    for (int d = 1; d < n; d <<= 1) {
        for (int m = d << 1, i = 0; i < n; i += m) {
            for (int j = 0; j < d; ++j) {
                int x = a[i + j], y = a[i + j + d];
                if (rev == 1) {
                    if (op == OR)a[i + j + d] = add(y, x);
                    if (op == AND)a[i + j] = add(x, y);
                    if (op == XOR)a[i + j] = add(x, y), a[i + j + d] = sub(x, y);
                    if (op == XNOR)a[i + j] = sub(y, x), a[i + j + d] = add(x, y);
                } else {
                    ll inv2 = (mod + 1) >> 1;
                    if (op == OR)a[i + j + d] = sub(y, x);
                    if (op == AND)a[i + j] = sub(x, y);
                    if (op == XOR)a[i + j] = 1ll * add(x, y) * inv2 % mod, a[i + j + d] = 1ll * sub(x, y) * inv2 % mod;
                    if (op == XNOR)a[i + j] = 1ll * sub(y, x) * inv2 % mod, a[i + j + d] = 1ll * add(x, y) * inv2 % mod;
                }
            }
        }
    }
}

int A[maxn], B[maxn];

void mul(int op, int *a, int n, int *b, int m, int *ans) {
    int bitn = 1;
    while (bitn < (n + m))bitn <<= 1;
    for (int i = 0; i < bitn; ++i)A[i] = a[i], B[i] = b[i];
    fwt(op, A, bitn, 1);
    fwt(op, B, bitn, 1);
    for (int i = 0; i < bitn; ++i)ans[i] = 1ll * A[i] * B[i] % mod;
    fwt(op, ans, bitn, -1);
}
```

### *2. 图论*
##### *2.1 Tarjan*
###### *2.1.1 割点*

```cpp
int n, m;
int head[maxn], cnt, dfn[maxn], low[maxn];
struct node {
    int next, to;
} e[maxn * 2];
bool vis[maxn], cut[maxn];

void ins(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void cut_bridge(int cur, int fa, int dep) {
    vis[cur] = 1;
    dfn[cur] = low[cur] = dep;
    int children = 0;
    for (int i = head[cur]; i; i = e[i].next) {
        int x = e[i].to;
        if (x != fa && vis[x] == 1) {
            if (dfn[x] < low[cur])low[cur] = dfn[x];
        }
        if (vis[x] == 0) {
            cut_bridge(x, cur, dep + 1);
            children++;
            if (low[x] < low[cur])low[cur] = low[x];
            if ((fa == -1 && children > 1) || (fa != -1 && low[x] >= dfn[cur]))cut[cur] = 1;
        }
    }
    vis[cur] = 2;
}
```
###### *2.1.2 边双联通分量*

```cpp
const int maxn = 1e4 + 10;
int n, m;
struct data {
    int to, next;
} e[maxn * 10];
int head[maxn], cnt = 0;
int cur = 0, top = 0;
int low[maxn], dfn[maxn], vis[maxn], ans[maxn * 10];

void ins(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(int u, int fa) {
    vis[u] = 1;
    dfn[u] = low[u] = ++cur;
    for (int i = head[u]; i; i = e[i].next) {
        int x = e[i].to;
        if (vis[x] == 1 && x != fa) {
            if (low[u] > dfn[x])low[u] = dfn[x];
            ans[++top] = u;
            ans[++top] = x;
        }
        if (vis[x] == 0) {
            tarjan(x, u);
            if (low[x] < low[u])low[u] = low[x];
            if (low[x] > dfn[u]) {
                ans[++top] = u;
                ans[++top] = x;
                ans[++top] = x;
                ans[++top] = u;
            } else {
                ans[++top] = u;
                ans[++top] = x;
            }
        }
    }
    vis[u] = 2;
}

//tarjan(i ,-1);

```

###### *2.1.3 点双连通分量*

```cpp
const int maxn = 5010;
int n, m, q, head[maxn];
struct data {
    int to, next;
} e[maxn * 4];
int cnt = 0, top = 0, tot = 0;
int dfn[maxn], low[maxn], s[maxn], vis[maxn];
vector<int> color[maxn];
int block[maxn];
int block_color = 0;

void ins(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void bic(int v, int fa, int dep) {
    vis[v] = 1;
    s[++top] = v;
    block[v] = block_color;
    dfn[v] = low[v] = dep;
    for (int i = head[v]; i; i = e[i].next) {
        int x = e[i].to;
        if (vis[x] == 0) {
            bic(x, v, dep + 1);
            if (low[x] >= dfn[v]) {
                tot++;
                do {
                    color[s[top]].push_back(tot);
                    top--;
                } while (s[top + 1] != x);
                if (low[x] == dfn[v])color[v].push_back(tot);
            }
            if (low[x] <= low[v])low[v] = low[x];
        } else if (x != fa && vis[x] == 1)low[v] = min(low[v], dfn[x]);
    }
    vis[v] = 2;
}

//bic(x, -1, 0);

```

###### *2.1.4 极大强连通分量*

```cpp
const int maxn = 1e4 + 10;

int n, m;
int cur = 0;
vector<int> v[maxn];
bool vis[maxn];
int low[maxn], dfn[maxn];
int s[maxn];
int top = 0, tot = 0;

void tarjan(int x) {
    s[++top] = x;
    vis[x] = 1;
    dfn[x] = low[x] = ++cur;
    for (int i = 0; i < v[x].size(); ++i) {
        int u = v[x][i];
        if (dfn[u] == 0)tarjan(u);
        if (vis[u] && low[x] > low[u])low[x] = low[u];
    }
    if (low[x] == dfn[x]) {
        tot = 0;
        while (s[top + 1] != x) {
            top--;
            tot++;
        }
    }
}

```

##### *2.2 路径*
###### *2.2.1 Dijkstra*
使用堆优化Dijkstra，复杂度O(mlogn)。

```cpp
struct heap {
    int d, u;
 
    bool operator<(const heap &b) const {
        return d > b.d;
    }
};
 
struct edge {
    int to, next, vi;
} e[maxn * 2];
int head[maxn], cnt, dis[maxn];
 
void ins(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    e[cnt].vi = z;
    head[x] = cnt;
}
 
bool vis[maxn];
 
void dijkstra(int src) {
    priority_queue<heap> q;
    memset(dis, 63, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[src] = 0;
    q.push((heap) {0, src});
    while (!q.empty()) {
        heap uu = q.top();
        q.pop();
        int x = uu.u;
        if (vis[x])continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] > dis[x] + e[i].vi) {
                dis[v] = dis[x] + e[i].vi;
                q.push((heap{dis[v], v}));
            }
        }
    }
}
```
邻接矩阵存储，复杂度O(n^2)。

```cpp
int g[maxn][maxn], dis[maxn];
bool vis[maxn];
 
void dijkstra(int src) {
    memset(vis, 0, sizeof vis);
    memset(dis, 63, sizeof dis);
    dis[src] = 0;
    for (int i = 1; i <= n; ++i) {
        int x = -1, m = inf;
        for (int y = 1; y <= n; ++y) {
            if (!vis[y] && dis[y] <= m) {
                x = y;
                m = dis[x];
            }
        }
        if (x == -1)break;
        vis[x] = 1;
        for (int y = 1; y <= n; ++y) {
            dis[y] = min(dis[y], dis[x] + g[x][y]);
        }
    }
}
```
###### *2.2.2 SPFA*

```cpp
const int maxn = 1e5 + 10;
const int maxm = 5e5 + 10;
int n, m;
struct edge {
    int to, next, vi;
} e[maxm];
int head[maxn], dis[maxn], cnt;
bool inq[maxn];

void ins(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    e[cnt].vi = z;
    head[x] = cnt;
}

queue<int> q;

void spfa(int src) {
    memset(dis, 63, sizeof dis);
    dis[src] = 0;
    inq[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int l = q.front();
        q.pop();
        for (int i = head[l]; i; i = e[i].next) {
            int x = e[i].to;
            if (dis[l] + e[i].vi < dis[x]) {
                dis[x] = dis[l] + e[i].vi;
                if (!inq[x]) {
                    inq[x] = 1;
                    q.push(x);
                }
            }
        }
        inq[l] = 0;
    }
}
```
###### *2.2.3 Floyd - Warshall*

```cpp
/*Warshall求传递闭包*/
void Warshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
}

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
```

 ###### *2.2.4 次短路*

```cpp
const int maxm = 1e5 + 10;
const int maxn = 5e3 + 10;
int head[maxn], cnt, n, m, dis[maxn], dis1[maxn];
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > q;
struct edge {
    int to, next, vi;
} e[maxm * 2];

void ins(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    e[cnt].vi = z;
    head[x] = cnt;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(dis, 63, sizeof(dis));
        memset(dis1, 63, sizeof(dis1));
        int x, y, z;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            ins(x, y, z);
            ins(y, x, z);
        }
        dis[1] = 0;
        q.push(P(0, 1));
        while (!q.empty()) {
            P u = q.top();
            q.pop();
            int v = u.second;
            for (int i = head[v]; i; i = e[i].next) {
                if (dis[e[i].to] > u.first + e[i].vi) {
                    dis1[e[i].to] = dis[e[i].to];
                    dis[e[i].to] = u.first + e[i].vi;
                    q.push(P(dis[e[i].to], e[i].to));
                } else if (dis1[e[i].to] > u.first + e[i].vi && dis[e[i].to] < u.first + e[i].vi) {
                    dis1[e[i].to] = u.first + e[i].vi;
                    q.push(P(dis1[e[i].to], e[i].to));
                }
            }
        }
        printf("%d\n", dis1[n]);
    }
    return 0;
}
```

 ##### *2.3 匹配*
 ###### *2.3.1 匹配的相关概念*

 记图G=(V,E)。
1.匹配：（边集）在G中两两没有公共端点的边集合ME。
2.边覆盖：G中的任意顶点都至少是F中某条边的端点的边集合FE。
3.独立集：（点集）在G中两两互不相连的顶点集合SV。
4.顶点覆盖：G中的任意边都有至少一个端点属于S的顶点集合SV。

a.对于不存在孤立点的图，|最大匹配|+|最小边覆盖|=|V|。
b.|最大独立集|+|最小顶点覆盖|=|V|。
c.对于二分图：|最大匹配|=|最小顶点覆盖|。

###### *2.3.2 朴素匹配*

求取最大匹配。

```cpp
bool g[maxn][maxn];
bool vis[maxn];
int p[maxn], n;

bool find_path(int x) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && g[x][i]) {
            vis[i] = 1;
            if (!p[i] || find_path(p[i])) {
                p[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

//if (find_path(i))tot++;

```

##### 

 ###### *2.3.3 匈牙利算法*

邻接矩阵存储。

```cpp
int g[maxn][maxn];
int from[maxn];
bool vis[maxn];

bool match(int x) {
    for (int i = 1; i <= n; ++i) {
        if (g[x][i] && vis[i] == 0) {
            vis[i] = 1;
            if (from[i] == -1 || match(from[i])) {
                from[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int hungry() {
    int tot = 0;
    memset(from, -1, sizeof(from));
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        if (match(i))
            ++tot;
    }
    return tot;
}

```

 ##### *2.4 树*
 ###### *2.4.1 lca*


```cpp
const int maxn = 1e5 + 10;
const int maxh = 17;
int n, q, tot, head[maxn], f[maxn][25], dep[maxn];
struct Edge {
    int to, next;
} e[2 * maxn];

void ins(int x, int y) {
    e[++tot].to = y, e[tot].next = head[x], head[x] = tot;
}

void dfs(int x, int fa) {
    f[x][0] = fa;
    for (int i = 1; (1 << i) <= dep[x]; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].to;
        if (y == fa) continue;
        dep[y] = dep[x] + 1;
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = maxh; i >= 0; i--)
        if (dep[f[y][i]] >= dep[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = maxh; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
```
###### *2.4.2 生成树Kruskal*

```cpp
const int maxn = 2e5 + 10;

int r[maxn], p[maxn], u[maxn], v[maxn], w[maxn];

bool cmp(const int i, const int j) { return w[i] < w[j]; }

int find(int x) { return p[x] == x ? p[x] : p[x] = find(p[x]); }

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)scanf("%d%d%d", &v[i], &u[i], &w[i]);
    for (int i = 1; i <= n; i++)p[i] = i;
    for (int i = 1; i <= m; i++)r[i] = i;
    sort(r + 1, r + 1 + m, cmp);
    int tot = 0, sum = 0;
    for (int i = 1; i <= m; i++) {
        int e = r[i];
        int x = find(v[e]);
        int y = find(u[e]);
        if (x != y) {
            p[x] = y;
            tot++;
            sum += w[e];
        }
    }
    return 0;
}
```
 ##### *2.5 网络流*

###### *2.5.1 最大流 Ford-Fulkerson实现*

```cpp
struct edge {
    int to, next, cap, rev;
} e[10010];
bool vis[1010];
int head[310], n, m, cnt = 0;

void ins(int s, int t, int c) {
    e[++cnt].to = t;
    e[cnt].next = head[s];
    head[s] = cnt;
    e[cnt].cap = c;
    e[cnt].rev = cnt + 1;
    e[++cnt].to = s;
    e[cnt].next = head[t];
    head[t] = cnt;
    e[cnt].cap = 0;
    e[cnt].rev = cnt - 1;
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    vis[v] = 1;
    for (int i = head[v]; i; i = e[i].next) {
        if (!vis[e[i].to] && e[i].cap > 0) {
            int d = dfs(e[i].to, t, min(f, e[i].cap));
            if (d > 0) {
                e[i].cap -= d;
                e[e[i].rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(vis, 0, sizeof(vis));
        int f = dfs(s, t, 1e9);
        if (f == 0)return flow;
        flow += f;
    }
}
```
###### *2.5.2 最大流Dinic实现*

```cpp
const int maxn = 2e3 + 10;
const int maxm = 5e3 + 10;
struct edge {
    int to, next, cap, rev;
} e[maxm];
int n, m, cnt = 0, head[maxn], dis[maxn], iter[maxn];
queue<int> q;

void ins(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
    e[cnt].cap = z;
    e[cnt].rev = cnt + 1;
    e[++cnt].to = x;
    e[cnt].next = head[y];
    head[y] = cnt;
    e[cnt].cap = 0;
    e[cnt].rev = cnt - 1;
}

void bfs(int s) {
    memset(dis, -1, sizeof(dis));
    while (!q.empty())q.pop();
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next) {
            if (e[i].cap && dis[e[i].to] < 0) {
                q.push(e[i].to);
                dis[e[i].to] = dis[u] + 1;
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    for (int i = (iter[v] ? iter[v] : head[v]); i; i = e[i].next, iter[v] = i) {
        if (e[i].cap && dis[v] < dis[e[i].to]) {
            int d = dfs(e[i].to, t, min(f, e[i].cap));
            if (d > 0) {
                e[i].cap -= d;
                e[e[i].rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        bfs(s);
        if (dis[t] < 0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, 1e9)) > 0)
            flow += f;
    }
}

```

###### *2.5.3 费用流*
SPFA实现：

```cpp
const int maxm = 1e5 + 10;
const int maxn = 1e4 + 10;
int n, m;
int cnt, head[maxn], dis[maxn], prevv[maxn], preve[maxn];
struct edge {
    int to, next, cap, cost, rev;
} e[maxm];

void ins(int x, int y, int z, int c) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
    e[cnt].cap = z;
    e[cnt].rev = cnt + 1;
    e[cnt].cost = c;
    e[++cnt].to = x;
    e[cnt].next = head[y];
    head[y] = cnt;
    e[cnt].cap = 0;
    e[cnt].rev = cnt - 1;
    e[cnt].cost = -c;
}

int min_cost_flow(int s, int t, int f) {
    int ans = 0;
    while (f > 0) {
        memset(dis, 63, sizeof(dis));
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (dis[v] > 1e8)continue;
            for (int i = head[v]; i; i = e[i].next) {
                if (e[i].cap > 0 && dis[e[i].to] > dis[v] + e[i].cost) {
                    dis[e[i].to] = dis[v] + e[i].cost;
                    prevv[e[i].to] = v;
                    preve[e[i].to] = i;
                    q.push(e[i].to);
                }
            }
        }
        if (dis[t] > 1e8)
            return -1;
        int d = f;
        for (int i = t; i != s; i = prevv[i]) {
            d = min(d, e[preve[i]].cap);
        }
        f -= d;
        ans += d * dis[t];
        for (int i = t; i != s; i = prevv[i]) {
            e[preve[i]].cap -= d;
            e[e[preve[i]].rev].cap += d;
        }
    }
    return ans;
}
```
### *3 组合数学*

#### 3.1. 盒子放小球问题
$n$个小球，$m$个盒子。
##### 3.1.1 n个小球有区别，m个盒子有区别
(1)允许空盒：每个球放到任意盒子里，总方案数$m^n$。
(2)不允许空盒：需满足$n \geq m\geq 1$ ，$m>n$时无解。其方案数及时看成m个盒子相同时的方案数，再乘以$m!$。答案即是$S(n,m)*m!$。S代表第二类斯特林数。
##### 3.1.2 n个小球有区别，m个盒子无区别
(1)允许空盒：假设放了k个盒，$m\geq k\geq 1$。那么答案就是$\sum_{k=1}^{m}S(n,k)$。
(2)不允许有空盒：$S(n,m)$。
##### 3.1.3 n个小球无区别，m个盒子有区别
(1)允许空盒：$n\geq m\geq 1$。“隔板法”。假设不允许有空盒，每一个盒里都先放一个小球，这样小球共有$n+m$个，然后插板，插板的方案数为$C^{n-1}_{n+m-1}$。
(2)不允许空盒：$n\geq m\geq 1$。“隔板法”。方案数$C^{m-1}_{n-1}$。
##### 3.1.4 n个小球无区别，m个盒子无区别
(1)允许空盒：划分数问题。$dp[i][j]$表示i个球，j个盒子的方案数。转移方程为
$$dp[i][j]=dp[i-j][j]+dp[i][j-1] (i\geq j)$$
$$dp[i][j]=dp[i][j-1] (i< j)$$
如果$n<m$，答案为$dp[n][n]$，否则为$dp[n][m]$。
(2)不允许空盒：$n\geq m\geq 1$。转成上情况的$n-m$个小球，$m$个盒子。

#### 3.2. 计数原理与计数公式
##### 3.2.1 可重复的排列与组合
###### 3.2.1.1 可重复的排列
从n个不同元素中取m个元素（同一元素可以重复取出），按照一定的顺序排成一列。排列的个数为$n^m$。
###### 3.2.1.2 可重复的组合
从n个不同元素中取m个元素（同一元素可以重复取出），并成一组。组合的个数为$C^{m}_{n+m-1}$。
【证明】
$1,2,...,n$表示n个不同元素。从中取m个可以表示成：
$$\{i_1,i_2,...,i_m\} (1\leq i_1\leq i_2 \leq ... \leq i_m \leq n)$$
令$j_k = i_k + (k-1)$，即：
$$\begin{aligned}j_1 &= i_1\\
j_2 &= i_2+ 1\\
j_3 &= i_3 + 2\\
...\\
j_m &=i_m+(m-1)
\end{aligned}$$
可以得到组合
$$\{j_1,j_2,...,j_m\} (1\leq j_1< j_2 < ... <j_m \leq n-m+1)$$
这样就相当于在$n+m-1$个元素中取$m$个不相同的元素，作为一组。
因此即是$C_{n+m-1}^{m}$。

###### 3.2.1.3 不全相异元素的全排列
n个元素中，分别有$n_1,n_2,...,n_k$个元素相同，且$n_1+n_2+...+n_k=n$，则称这n个元素的全排列为不全相异元素的全排列，个数为
$$\frac{n!}{n_1!n_2!...n_k!}$$

###### 3.2.1.4 多组组合
n个相异的元素分为$k(k\leq n)$个按照**一定顺序**排列的组，其中第$i$组有$n_i$个元素$(i=1,2,...,k)(n_1+n_2+...+n_k=n)$。不同的分组方法为
$$\frac{n!}{n_1!n_2!...n_k!}$$
【例】
从$n(n\geq 6)$个选手中选3对选手参加双打，问共有多少种选法。
答案为（注意不考虑**组的顺序**）
$$\frac{C_{n}^{6}*\frac{6!}{2!*2!*2!}}{3!}$$

##### 3.2.2  相异元素的圆排列和项链数
###### 3.2.2.1 圆排列
n个元素不分首尾排成一圈，成为n个相异元素的圆排列。排列的种数为$(n-1)!$。
###### 3.2.2.2 项链数
将n粒不相同的珠子，穿成一副项链，得到的不同的项链数。
由于项链顺时针和逆时针都是相同的，所以个数即是圆排列的一半。
$$\left\{
\begin{aligned}
&1,n = 1或n=2\\
&\frac{1}{2}*(n-1)!,n\geq3
\end{aligned}
\right.$$
##### 3.2.3 错排问题
错排递推式。
$D(n)$代表$n$个数的错排公式，则
$$D(n) = (n-1)*[D(n-1)+D(n-2)]$$
错排公式
$$D(n) = n!(1-\frac{1}{1!}+\frac{1}{2!}-\frac{1}{3!}+...+\frac{(-1)^n}{n!})$$


##### 3.2.4 组合数常用公式
$$\begin{aligned}
&C_{n}^{2} = \frac{n*(n-1)}{2}\\
&\\
&C_{n}^{3}=\frac{n*(n-1)(n-2)}{6}\\
&\\
&C_{n}^{m}=C_{n-1}^{m-1}+C_{n-1}^{m}\\
&\\
&m*C_{n}^{m} = n*C_{n-1}^{m-1}\\
&\\
&C_n^0+C_n^1+...+C_n^n =2^n\\
&\\
&1C_n^1+2C_n^2+...+nC_n^n=n2^{n-1}\\
&\\
&1^2C_n^1+2^2C_n^2+...+n^2C_n^n=n(n+1)2^{n-2}\\
&\\
&\frac{C_n^1}{1}-\frac{C_n^2}{2}+\frac{C_n^3}{3}+...+(-1)^{n-1}\frac{C_n^n}{n}=1+\frac{1}{2}+\frac{1}{3}+...+\frac{1}{n}\\
&\\
&(C_n^0)^2+(C_n^1)^2+(C_n^2)^2+...+(C_n^n)^2=C_{2n}^n\\
\end{aligned}$$
范德蒙恒等式:
$$\sum_{i=0}^{k}C_n^iC_m^{k-i}=C_{n+m}^k$$

经验式(link [https://www.cnblogs.com/qrsikno/p/10170523.html](https://www.cnblogs.com/qrsikno/p/10170523.html)):
$$\begin{aligned}
&\sum_{i=0}^{n}C_n^i*r^i=(r+1)^n（广义二项式定理）\\
&\\
&\sum_{i=0}^{n}i*C_n^i=n*2^{n-1}\\&\\
&\sum_{i=0}^{n}C_i^k=C_{n+1}^{k+1}\\&\\
&\sum_{i=0}^{k}C_{n+i}^i=C_{n+k+1}^{k}\\
\end{aligned}$$


#### 3.3. 抽屉原理与平均值原理
##### 3.3.1 抽屉原理
###### 3.3.1.1 第一抽屉原理
如果将m个物件放入n个抽屉内，那么必有一个抽屉内至少有$[\frac{m-1}{n}]+1$个物件。
【推广】
如果将$m_1+m_2+...+m_n+1$个物件放入n个抽屉内，那么或者第一个抽屉内至少有$m_1+1$个物件，或者第二个抽屉内至少有$m_2+1$个物件……或者第n个抽屉内至少有$m_n+1$个物件。
###### 3.3.1.2 第二抽屉原理
如果将m个物件放入n个抽屉内，那么必有一个抽屉内至多有$[\frac{m}{n}]$个物件。
【推广】
如果将$m_1+m_2+...+m_n-1$个物件放入n个抽屉内，那么或者第一个抽屉内至多有$m_1-1$个物件，或者第二个抽屉内至多有$m_2-1$个物件……或者第n个抽屉内至多有$m_n-1$个物件。
##### 3.3.2 平均值原理
（1）设$a_1,a_2,...,a_n$是实数，$A =\frac{1}{n}(a_1+a_2+...+a_n)$，则$a_1,a_2,...,a_n$中必有一个数不小于A，也有一个数不大于A。
（2）设$a_1,a_2,...,a_n$是实数，$G =\frac{1}{n}\sqrt[n]{a_1a_2...a_n}$，则$a_1,a_2,...,a_n$中必有一个数不小于G，也有一个数不大于G。
#### 3.4. 生成函数
生成函数的定义：
实数序列 $a_0,a_1,...,a_k,...$的生成函数是无穷级数
$$G(x)=a_0+a_2x+...+a_kx^k+...=\sum_{k=0}^{\infty}a_kx^k$$
${a_k}$的普通生成函数。
广义二项式系数：
$$\dbinom{u}{k}=\left \{ \begin{aligned}&u(u-1)(u-2)...(u-k+1)/k!,&k>0\\
&1,&k=0
\end{aligned}\right.$$
 【例】
 $$\begin{aligned}\dbinom{1/2}{3}&=\frac{(1/2)(1/2-1)(1/2-2)}{3!}\\
 &=\frac{(1/2)(-1/2)(-3/2)}{6}\\
 &=1/16 
 \end{aligned}$$
设$x$是实数，$|x|<1$，$u$是实数，那么
$$(1+x)^u=\sum_{k=0}^{\infty}\dbinom{u}{k}x^k$$

##### 3.4.1 常用生成函数
$$\begin{aligned}
&\frac{1-x^{n+1}}{1-x}=\sum_{k=0}^{n}x^k\\
&\\
&\frac{1}{1-ax}=\sum_{k=0}^{\infty}a^kx^k\\
&\\
&\frac{1}{(1-x)^2}=\sum_{k=0}^{\infty}(k+1)x^k\\
&\\
&\frac{1}{(1-x)^n}=\sum_{k=0}^{\infty}C_{n+k-1}^{k}x^k\\
&\\
&\frac{1}{(1+x)^n}=\sum_{k=0}^{\infty}C_{n+k-1}^{k}(-1)^kx^k\\
\end{aligned}$$
##### 3.4.2 计数问题

#### 3.5. 特殊计数序列
##### 3.5.1 Catalan数列
前几项：$1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, ......$即$c[0]=1,c[1]=1,c[2]=2...$

$$\begin{aligned}
&递推式1：f[n]=\sum_{i=0}^{n-1}f[i]*f[n-i-1]\\
&\\
&递推式2：f[n]=\frac{4n-2}{n+1}f[n-1]\\
&\\
&组合式1：f[n]=\frac{C_{2n}^{n}}{n+1}\\
&\\
&组合式2：f[n] = C_{2n}^{n}-C_{2n}^{n-1}
\end{aligned}$$

应用：
1. 二叉树计数1：已知二叉树有$n$个节点，能够构成$C_{n}$种不同的二叉树。（二叉搜索树）
2. 二叉树计数2：已知二叉树的叶子$n$个，能够构成$C_{n-1}$种不同的二叉树。（二叉搜索树）
3. 括号匹配数：一个合法的表达式由()包围，()可以嵌套和连接，给出$n$对括号，可以组成的合法表达式的个数为$C_{n}$。
4. 划分问题：将一个凸$n+2$多边形区域分成三角形区域的方法数为$C_{n}$。
5. 出栈问题1：一个栈的进栈序列为$1,2,3,..n$，不同的出栈序列有$C_{n}$种。
6. 出栈问题2：有2n个人排成一行进入剧场。入场费5元。其中只有n个人有一张5元钞票，另外n人只有10元钞票，剧院无其它钞票，问有多少种方法使得只要有10元的人买票，售票处就有5元的钞票找零。5元的相当于入栈，10元的相当于出栈，转化成上问题。
7. 路径问题：在$n*n$的方格地图中，从一个角到另外一个角，不跨越对角线的路径数有$C_{n}$种。
8. 握手问题：$2n$个人均匀坐在一个圆桌边上，某个时刻所有人同时与另一个人握手，要求手之间不能交叉，共有$C_{n}$种握手方法。
##### 3.5.2 Fibonacci数列
通项公式：$$F_n=\frac{1}{\sqrt{5}}[(\frac{1+\sqrt{5}}{2})^n-(\frac{1-\sqrt{5}}{2})^n]$$
递推式：
$$F_n=F_{n-1}+F_{n-2}$$
性质：
$$\begin{aligned}&F_1+F_1+F_2+F_3+...+F_n=F_{n+2}-1\\
&\\
&F_1+2F_2+3F_3+...+nF_n=nF_{n+2}-F_{n+3}+2\\
&\\
&F_1+F_3+F_5+...+F_{2n-1}=F_{2n}\\
&\\
&F_2+F_4+F_6+...+F_{2n}=F_{2n+1}-1\\
&\\
&F_1^2+F_2^2+F_3^2+...+F_n^2=F_nF_{n+1}\\
&\\
&F_{n-1}F_{n+1}-F_n^2=(-1)^n
\end{aligned}$$

定理：
$$\begin{aligned}
&F_nF_m+F_{m-1}F_{n-1}=F_{m+n-1}\\
&\\
&F_mF_{n+1}+F_{m-1}F_n=F_{m+n}\\
&\\
&m=n时，\\
&F_{2n-1}=F_n^2+F_{n-1}^2\\
&\\
&F_{2n}=(F_{n-1}+F_{n+1})F_n=(2F_{n-1}+F_n)F_n\\
&\\
&F_n整除F_m当且仅当n整除m，其中n\geq3\\
&\\
&任意连续三个Fibonacci数两两互素。
\end{aligned}$$

##### 3.5.3 Lucas数列
定义：
$$L_n=
\left\{\begin{aligned}&2,&n=1\\
&1,&n=2\\
&L_{n-1}+L_{n-2},&n\geq3
\end{aligned}
\right.$$
通项公式：
$$L_n=(\frac{1+\sqrt{5}}{2})^n+(\frac{1-\sqrt{5}}{2})^n$$
与Fibonacci数的关系：
$$\begin{aligned}
&F_{2n}=L_nF_n\\
&\\
&L_n=F_{n-1}+F_{n+1}\\
&\\
&F_n=\frac{L_{n-1}+L_{n+1}}{5}\\
&\\
&L_n^2=5F_n^2+4(-1)^n
\end{aligned}$$
##### 3.5.4 Stirling数
###### 3.5.4.1 第一类Stirling数

$S1(n,m)$表示的是将$n$个不同元素构成$m$个圆排列的数目。
递推式：
$$S1(n,m)=(n-1)*S1(n-1,m)+S1(n-1,m-1)(n>1,m>1)$$

边界条件：
$$\begin{aligned}
&S1(0,0)=1,S1(n,0) = 0\\
&S1(n,n) = 1
\end{aligned}$$
性质：
$$\sum_{k=0}^{n}S1(n,k)=n!$$
【例】$n$个仓库， $2n$把钥匙，$n$ 位官员。如果把$n$位官员分成$m$个不同的部，部中的官员数量与管理的仓库数量一致。有多少种方案使得所有同部的官员可以打开所有本部管理的仓库，而无法打开其他管理的仓库。（$n$把钥匙放到仓库，$n$把钥匙分给官员）
方案数即为$S1(n,m)n!$。
前面的是放到仓库里的方案数，后面说官员的分配方案。

###### 3.5.4.2 第二类Stirling数
$S2(n,m)$表示的是把$n$个不同元素划分到$m$个集合的方案数。
递推式：
$$S2(n,m)=m*S2(n-1,m)+S2(n-1,m-1)(1\leq m\leq n-1)$$
边界条件：
$$\begin{aligned}
&S2(n,0)=0,S2(n,1)=1\\
&S2(n,n)=1
\end{aligned}$$

### *4  数据结构*

 ##### *4.1 树状数组*
 ###### *4.1.1 普通树状数组*

 仅支持单点修改区间查询。

```cpp
const int maxn = 1e5 + 10;

int tree[maxn];

int lb(int x) { return x & -x; }

int read(int x) {
    int tot = 0;
    for (int i = x; i; i -= lb(i)) {
        tot += tree[i];
    }
    return tot;
}

void add(int num, int x) {
    for (int i = x; i <= n; i += lb(i)) {
        tree[i] += num;
    }
}

```

###### *4.1.2 普通二维树状数组*

```cpp
const int maxn = 1010;
int tree[maxn][maxn];
int n, m;

int lb(int x) { return x & -x; }

int read(int x, int y) {
    int tot = 0;
    for (int i = x; i; i -= lb(i)) {
        for (int j = y; j; j -= lb(j))
            tot += tree[i][j];
    }
    return tot;
}

void add(int num, int x, int y) {
    for (int i = x; i <= n; i += lb(i)) {
        for (int j = y; j <= m; j += lb(j)) {
            tree[i][j] += num;
        }
    }
}
```

###### *4.1.3 树状数组维护区间最大、最小值*

维护区间[1,x]的：

```cpp
const int maxn = 1e5 + 10;
int c[maxn], n, r[maxn], a[maxn];

inline int lb(int x) { return x & -x; }

int query(int x) {
    int tot = 0;
    for (; x; x -= lb(x))
        tot = max(tot, c[x]);
    return tot;
}

void update(int x, int v) {
    for (; x <= n; x += lb(x)) {
        c[x] = max(c[x], v);
        int t = x - lb(x);
        for (int y = x - 1; y && y - lb(y) >= t; y -= lb(y))
            c[x] = max(c[x], c[y]);
    }
}

```

 ##### *4.2 线段树*

###### *4.2.1 维护区间最值，区间修改*

```cpp
const int maxn = 1e5 + 10;
 
struct tree {
    int left, right;
    ll sum, add, maxm, minm;
} c[maxn << 2];
 
ll a[maxn];
 
void build(int id, int l, int r) {
    c[id].left = l;
    c[id].right = r;
    if (l == r) {
        c[id].maxm = c[id].minm = c[id].sum = a[l];
        c[id].add = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    c[id].maxm = max(c[id << 1].maxm, c[id << 1 | 1].maxm);
    c[id].minm = min(c[id << 1].minm, c[id << 1 | 1].minm);
    c[id].sum = c[id << 1].sum + c[id << 1 | 1].sum;
}
 
void pushdown(int id) {
    c[id << 1].sum += (c[id << 1].right - c[id << 1].left + 1) * c[id].add;
    c[id << 1].minm += c[id].add;
    c[id << 1].maxm += c[id].add;
    c[id << 1].add += c[id].add;
    c[id << 1 | 1].sum += (c[id << 1 | 1].right - c[id << 1 | 1].left + 1) * c[id].add;
    c[id << 1 | 1].minm += c[id].add;
    c[id << 1 | 1].maxm += c[id].add;
    c[id << 1 | 1].add += c[id].add;
    c[id].add = 0;
}
 
void update(int id, int pos, ll v) {
    if (c[id].left == c[id].right)c[id].sum = c[id].maxm = c[id].minm = v;
    else {
        int mid = (c[id].left + c[id].right) >> 1;
        if (pos <= mid)update(id << 1, pos, v);
        else update(id << 1 | 1, pos, v);
        c[id].sum = c[id << 1].sum + c[id << 1 | 1].sum;
        c[id].maxm = max(c[id << 1].maxm, c[id << 1 | 1].maxm);
        c[id].minm = min(c[id << 1].minm, c[id << 1 | 1].minm);
    }
}
 
ll query_max(int id, int l, int r) {
    if (c[id].left == l && c[id].right == r)return c[id].maxm;
    int mid = (c[id].left + c[id].right) >> 1;
    if (c[id].add)pushdown(id);
    if (r <= mid)return query_max(id << 1, l, r);
    else if (l > mid)return query_max(id << 1 | 1, l, r);
    else return max(query_max(id << 1, l, mid), query_max(id << 1 | 1, mid + 1, r));
}
 
ll query_min(int id, int l, int r) {
    if (c[id].left == l && c[id].right == r)return c[id].minm;
    int mid = (c[id].left + c[id].right) >> 1;
    if (c[id].add)pushdown(id);
    if (r <= mid)return query_min(id << 1, l, r);
    else if (l > mid)return query_min(id << 1 | 1, l, r);
    else return min(query_min(id << 1, l, mid), query_min(id << 1 | 1, mid + 1, r));
}
 
void update(int id, int l, int r, ll v) {
    if (c[id].left > r || c[id].right < l)return;
    if (c[id].left >= l && c[id].right <= r) {
        c[id].add += v;
        c[id].sum += (c[id].right - c[id].left + 1) * v;
        return;
    }
    if (c[id].add)pushdown(id);
    update(id << 1, l, r, v);
    update(id << 1 | 1, l, r, v);
    c[id].sum = c[id << 1].sum + c[id << 1 | 1].sum;
}
 
ll query_sum(int id, int l, int r) {
    if (r < c[id].left || l > c[id].right)return 0;
    if (c[id].left >= l && c[id].right <= r) {
        return c[id].sum;
    }
    if (c[id].add)pushdown(id);
    ll ans = query_sum(id << 1, l, r) + query_sum(id << 1 | 1, l, r);
    c[id].sum = c[id << 1].sum + c[id << 1 | 1].sum;
    return ans;
}
 
```
###### *4.2.2 动态开点线段树*

```cpp
const int maxn = (1e6 + 10) * 51;
const int inf = 1e9 + 10;

int ls[maxn], rs[maxn], cnt;

struct tree {
    int left, right, mmin;
} c[maxn];

void build(int id, int l, int r) {
    c[id].left = l;
    c[id].right = r;
    c[id].mmin = inf;
    ls[id] = rs[id] = 0;
}

void update(int id, int pos, int v) {
    if (c[id].left == c[id].right)c[id].mmin = min(c[id].mmin, v);
    else {
        int mid = (c[id].left + c[id].right) >> 1;
        if (pos <= mid) {
            if (ls[id] == 0) {
                ls[id] = cnt;
                build(cnt, c[id].left, mid);
                ++cnt;
            }
            update(ls[id], pos, v);
            c[id].mmin = min(c[id].mmin, c[ls[id]].mmin);
        } else {
            if (rs[id] == 0) {
                rs[id] = cnt;
                build(cnt, mid + 1, c[id].right);
                ++cnt;
            }
            update(rs[id], pos, v);
            c[id].mmin = min(c[id].mmin, c[rs[id]].mmin);
        }
    }
}

bool query_min(int id, int l, int r, int ck) {
    if (c[id].left == l && c[id].right == r)return (ck >= c[id].mmin);
    if (c[id].mmin > ck)return 0;
    int mid = (c[id].left + c[id].right) >> 1;
    if (r <= mid) {
        if (ls[id] != 0)return query_min(ls[id], l, r, ck);
    } else if (l > mid) {
        if (rs[id] != 0)return query_min(rs[id], l, r, ck);
    } else {
        if (ls[id] != 0 && query_min(ls[id], l, mid, ck))return 1;
        else if (rs[id] != 0 && query_min(rs[id], mid + 1, r, ck))return 1;
    }
    return 0;
}
```
 ### *5 动态规划*
 ##### *5.1 常见线性模型*
 ###### *5.1.1 LIS(O(nlogn))*
 采用树状数组优化。
```cpp
int c[maxn], n, r[maxn], a[maxn];
 
inline int lb(int x) { return x & -x; }
 
int query(int x) {
    int tot = 0;
    for (; x; x -= lb(x))
        tot = max(tot, c[x]);
    return tot;
}
 
void update(int x, int v) {
    for (; x <= n; x += lb(x)) {
        c[x] = max(c[x], v);
//        int t = x - lb(x);
//        for (int y = x - 1; y && y - lb(y) >= t; y -= lb(y))
//            c[x] = max(c[x], c[y]);
    }
}
 
const int cmp(const int i, const int j) {
    return a[i] == a[j] ? i < j : a[i] < a[j];
}
 
int main() {
    __;
    int _;
    cin >> _;
    while (_--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            r[i] = i;
        }
        sort(r + 1, r + 1 + n, cmp);
        memset(c, 0, sizeof c);
        int ans = 0;
        for (int j = 1; j <= n; ++j) {
            int i = r[j];
            int tmp = query(i - 1) + 1;
            update(i, tmp);
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
```
###### *5.1.2 LCS*
复杂度O(nlogn)

```cpp
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], c[maxn];
int mp[maxn];

inline int lb(int x) { return x & -x; }

int query(int x) {
    int tot = 0;
    for (; x; x -= lb(x))
        tot = max(tot, c[x]);
    return tot;
}

void update(int x, int v) {
    for (; x <= n; x += lb(x)) {
        c[x] = max(c[x], v);
//        int t = x - lb(x);
//        for (int y = x - 1; y && y - lb(y) >= t; y -= lb(y))
//            c[x] = max(c[x], c[y]);
    }
}

int main() {
    __;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        mp[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i) b[i] = mp[a[i]];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = query(b[i] - 1) + 1;
        update(b[i], tmp);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
```

###### *5.1.3 LCIS*
复杂度O(n*m)

```cpp
int n, m;
int a[maxn], b[maxn];
int f[maxn][maxn];
 
int main() {
    __;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        int tot = 0;
        for (int j = 1; j <= m; ++j) {
            f[i][j] = a[i] == b[j] ? tot + 1 : f[i - 1][j];
            if (b[j] < a[i])tot = max(tot, f[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
```

###### *5.1.4 石子合并问题*

```cpp
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int inf = 1000000000;
int a[201];
int f[201][201] = {0};
int sum[201] = {0};

int main() {
    __;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
        sum[i + n] = sum[i + n - 1] + a[i + n];
    }
    memset(f, 0, sizeof(f));
    for (int k = 1; k < n; k++) {
        for (int i = 1; i + k <= 2 * n; i++) {
            int r = i + k;
            f[i][r] = inf;
            for (int j = i; j < r; j++)f[i][r] = min(f[i][r], sum[r] - sum[i - 1] + f[i][j] + f[j + 1][r]);
        }
    }
    int tot = inf;
    for (int i = 1; i <= n; i++)tot = min(tot, f[i][i + n - 1]);
    cout << tot << endl;
    memset(f, 0, sizeof(f));
    for (int k = 1; k < n; k++) {
        for (int i = 1; i + k <= 2 * n; i++) {
            int r = i + k;
            f[i][r] = 0;
            for (int j = i; j < r; j++)f[i][r] = max(f[i][r], sum[r] - sum[i - 1] + f[i][j] + f[j + 1][r]);
        }
    }
    tot = 0;
    for (int i = 1; i <= n; i++)tot = max(tot, f[i][i + n - 1]);
    cout << tot;
    return 0;
}
```
##### *5.3 树型dp*
###### *5.3.1 森林转二叉树*
题意：给你n门课程，每门课有其先修课和学分。求选m门课程的最大学分。（森林转二叉树）



树形dp。关键是存树的方式。

在森林上找多个包含树根的连通块，使所有点的权值最大。

用二叉树存储，定义两个数组head和next，其中head[i]表示节点i的第一个儿子节点，next[i]表示节点i的兄弟节点。

若以知一个节点的父亲，则插入该节点的代码：

```cpp
    if (head[fa] == 0)head[fa] = i;
    else {
        int t = head[fa];
        while (next[t] != 0)t = next[t];
        next[t] = i;
    }
```
dp方程：



$f[c][s]$ 表示在二叉树中以c为根的子树中取s个节点的最大权值，其中这s个节点均联通。

$$f[c][s] = a[c] + max(f[head[c]][i], f[next[c]][s - 1 - i]);$$

由于二叉树中节点c的右节点实际上与c是兄弟关系，故$f[c][s]$的值可以不包含节点c，故还应保证

$$f[c][s] = max(f[c][s], f[next[c]][s]);$$

代码：

```cpp
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int a[1001];
int head[1001], nxt[1001];
int f[1001][1001];

int dp(int c, int s) {
    if (s == 0)return 0;
    if (c == 0)return 0;
    if (f[c][s] != 0)return f[c][s];
    for (int i = 0; i < s; i++)f[c][s] = max(f[c][s], a[c] + dp(head[c], i) + dp(nxt[c], s - 1 - i));
    f[c][s] = max(f[c][s], dp(nxt[c], s));
    return f[c][s];
}

int main() {
    __;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int fa;
        cin >> fa;
        if (head[fa] == 0)head[fa] = i;
        else {
            int t = head[fa];
            while (nxt[t] != 0)t = nxt[t];
            nxt[t] = i;
        }
        cin >> a[i];
    }
    cout << dp(head[0], m);
    return 0;
}
```


 ##### *5.4 单调栈*
 手动实现版：

例题大意：给出N个矩形和他们的高和宽 现在把他们宽放在x轴上对齐，请问现在最大矩形面积。
```cpp
int n;
struct Data {
    int left, right, height;
} s[maxn], a[maxn];

int main() {
    __;
    while (cin >> n) {
        if (n == -1)break;
        int l = 0, w, h;
        for (int i = 1; i <= n; ++i) {
            cin >> w >> h;
            a[i].height = h;
            a[i].left = l;
            l += w;
            a[i].right = l;
        }
        int ans = 0, top = 0;
        for (int i = 1; i <= n; ++i) {
            while (top && s[top].height > a[i].height) {
                Data p = s[top--];
                if (top == 0) {
                    ans = max(ans, p.height * (a[i].left));
                } else {
                    ans = max(ans, p.height * (a[i].left - s[top].right));
                }
            }
            Data x;
            x.left = a[i].left;
            x.right = a[i].right;
            x.height = a[i].height;
            s[++top] = a[i];
        }
        while (top) {
            Data p = s[top--];
            if (top == 0) {
                ans = max(ans, p.height * (a[n].right));
            } else {
                ans = max(ans, p.height * (a[n].right - s[top].right));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```
STL写法：
例题：给出直方图上n个矩形的高度，求最大面积。

```cpp
stack<pair<ll, ll> > s;
ll n, a[maxn];

int main() {
    __;
    while (cin >> n) {
        if (n == 0)break;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        for (ll i = 1; i <= n; ++i) {
            while (!s.empty() && s.top().first > a[i]) {
                pair<ll, ll> p = s.top();
                s.pop();
                if (s.empty()) {
                    ans = max(ans, p.first * (i - 1));
                } else {
                    ans = max(ans, (i - 1 - s.top().second) * p.first);
                }
            }
            s.push(pair<int, int>(a[i], i));
        }
        while (!s.empty()) {
            pair<ll, ll> p = s.top();
            s.pop();
            if (s.empty()) {
                ans = max(ans, n * p.first);
            } else {
                ans = max(ans, (n - s.top().second) * p.first);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```
不使用栈，直接用数组记录。

```cpp
int n, m;
int a[2001][2001], h[2001][2001];
int l[2002][2001], r[2002][2002];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j]) {
                h[i][j] = 1;
                if (h[i - 1][j])h[i][j] += h[i - 1][j];
            } else h[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j]) {
                int t = j - 1;
                l[i][j] = 1;
                while (t >= 1 && h[i][j] <= h[i][t]) {
                    l[i][j] += l[i][t];
                    t -= l[i][t];
                }
            }
        }
        for (int j = m; j >= 1; j--) {
            if (h[i][j]) {
                int t = j + 1;
                r[i][j] = 1;
                while (t <= m && h[i][j] <= h[i][t]) {
                    r[i][j] += r[i][t];
                    t += r[i][t];
                }
            }
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tot = max(tot, (l[i][j] + r[i][j] - 1) * h[i][j]);
        }
    }
    printf("%d\n", tot);
    return 0;
}
```

 ##### *5.5 单调队列*

手动实现版：

$r - 2 * sum[r] - ((l - 1) - 2 * sum[l-1]) + x$ ，维护对于每个$r$，只需找出最小的$((l - 1) - 2 * sum[l - 1])$即可。
```cpp
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + c[i] - '0';
    while (m--) {
        int x;
        scanf("%d", &x);
        int l = 1, r = 0;
        int ans = 0;
        q[++r] = 0;
        for (int i = 1; i <= n; ++i) {
            while (l <= r && q[r] - sum[q[r]] * 2 > i - sum[i] * 2)
                --r;
            q[++r] = i;
            while (l <= r && sum[q[r]] - sum[q[l]] > x)
                ++l;
            ans = max(ans, q[r] - 2 * sum[q[r]] - (q[l] - 2 * sum[q[l]]) + x);
        }
    }
```

STL实现版：

```cpp
ll sum[maxn], b[maxn];
list<int> q;

ll dp(int len, int cnt) {
    q.clear();
    ll ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        sum[i] = sum[i - 1] + b[i];
    }
    for (int i = 1; i <= cnt; ++i) {
        while (!q.empty() && sum[q.front()] > sum[i])
            q.pop_front();
        q.push_front(i);
        while (!q.empty() && i - len > q.back())
            q.pop_back();
        if (i > 1)ans = max(ans, sum[i] - sum[q.back()]);
        else ans = max(ans, sum[i]);
    }
    return ans;
}
```

##### *5.6 数位dp*
Windy数：

```cpp
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

int a[100];
ll f[101][11];

ll dp(int len) {
    if (len == 0)return 0;
    ll ans = 1;
    for (int i = 1; i < a[len]; ++i) {
        ans += f[len][i];
    }
    for (int i = len - 1; i; --i) {
        for (int j = 0; j < a[i]; ++j) {
            if (abs(j - a[i + 1]) >= 2)ans += f[i][j];
        }
        if (abs(a[i] - a[i + 1]) < 2) {
            ans--;
            break;
        }
    }
    for (int i = len - 1; i; --i) {
        for (int j = 1; j <= 9; ++j) {
            ans += f[i][j];
        }
    }
    return ans;
}

ll solve(ll t) {
    int pos = 0;
    while (t) {
        a[++pos] = (int) (t % 10);
        t /= 10;
    }
    return dp(pos);
}

int main() {
    __;
    for (int i = 0; i <= 9; ++i)
        f[1][i] = 1;
    for (int i = 2; i <= 15; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (abs(j - k) >= 2) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
```
##### *5.7 四边形不等式优化*

1. $f[i][j]=\min{\{f[i][k]+f[k+1][j]\}}+w[i][j]$


- 若$w[a][c]+w[b][d]\leq w[b][c]+w[a][d]\ (a<b<c<d)$则称w满足四边形不等式
- w满足四边形不等式，当且仅当$w[i][j]+w[i+1][j+1]\leq w[i+1][j]+w[i][j+1]$
- 若$w[a][b]<=w[a'][b']\ ([a,\ b]\subset [a',\ b'])$则称w关于区间包含关系单调
- 如果w满足四边形不等式且关于区间包含关系单调，则f也满足四边形不等式
- 如果f满足四边形不等式，则决策点$p[i][j-1]\leq p[i][j]\leq p[i+1][j]$，此时若把p看作一个矩阵则p在每一行和每一列上上单调不降

此时k的枚举由$[i,\ j]$变为了$[p[i][j-1],\ p[i+1][j]]$。只要将p矩阵打印出来观察每行每列是否单调即可，如果单调说明方程可以四边形优化。 

### *6 其它问题*
 ##### *6.1 星期计算*

只适用于1582年之后的日期。

计算星期几的公式：

```cpp
int Day(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        --y;
    }
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
}
```
求得的结果1~7分别表示星期一到星期日。
##### *6.2 逆序对*
树状数组写法：

```cpp
int n, r[maxn];
ll a[maxn], c[maxn];
 
int lb(int x) { return x & -x; }
 
ll read(int x) {
    ll tot = 0;
    for (int i = x; i; i -= lb(i))tot += c[i];
    return tot;
}
 
void add(ll num, int x) {
    for (int i = x; i <= n; i += lb(i))
        c[i] += num;
}
 
const int cmp(const int i, const int j) { return i == j ? i < j : a[i] < a[j]; }
 
int main() {
    __;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r[i] = i;
    }
    sort(r + 1, r + 1 + n, cmp);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        int x = r[i];
        tot += read(n) - read(x);
        add(1, x);
    }
    cout << tot << endl;
    return 0;
}
```
归并排序写法：

```cpp
ll inversed_pair(int a[], int n) {
    if (n == 1)return 0;
    ll sum = 0;
    int mid = (n >> 1);
    sum += inversed_pair(a, mid);
    sum += inversed_pair(a + mid, n - mid);
    int *b = new int[n];
    memcpy(b, a, n * sizeof(int));
    for (int i1 = 0, i2 = mid, i = 0; i1 < mid || i2 < n; ++i) {
        if (i2 == n) {
            a[i] = b[i1];
            ++i1;
            sum += i2 - mid;
        }
        else if (i1 == mid) {
            a[i] = b[i2];
            ++i2;
        }
        else if (b[i1] < b[i2]) {
            a[i] = b[i1];
            ++i1;
            sum += i2 - mid;
        }
        else {
            a[i] = b[i2];
            ++i2;
        }
    }
    delete[] b;
    return sum;
}
```
##### *6.3 三分*

```cpp
    while (l + eps < r) {
        double lm = l + (r - l) / 3.0, rm = l + 2.0 * (r - l) / 3.0;
        if (dis(lm) > dis(rm))
            r = rm;
        else
            l = lm;
    }
```
##### *6.4 母函数*
有n个重量为1g的砝码，n/2个重量为2g的砝码，...，1个重量为ng的砝码，问称取ng的物品有多少种放砝码的方法。

$$(1 + x + x^2 + x^3 + ... + x^n)  * (1 + x^2 + x^4 + ... + x^n) * ... * (1 + x^n)$$
```cpp
int c1[maxn], c2[maxn];

int main() {
    __;
    int n;
    while (cin >> n) {
        for (int i = 0; i <= n; ++i) {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k + j <= n; k += i) {
                    c2[j + k] += c1[j];
                }
            }
            for (int j = 0; j <= n; ++j) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[n] << endl;
    }
    return 0;
}
```
### *7 博弈*
#### 7.0 参考文章
[https://blog.csdn.net/weixin_38686780/article/details/82940573](https://blog.csdn.net/weixin_38686780/article/details/82940573)
[https://blog.csdn.net/qq_41552508/article/details/89159952](https://blog.csdn.net/qq_41552508/article/details/89159952)
[https://www.zhihu.com/question/27467617](https://www.zhihu.com/question/27467617)

#### 7.1 平等博弈
##### 7.1.1 常见概念及定理
###### 7.1.1.1 组合游戏
公平组合游戏ICG -- Impartial Combinatorial Games
游戏的胜负仅仅取决于当前状态，与谁在玩没有关系。
判定：
1. 2人博弈
2. 当前状态的下一个状态的个数有限
3. 每个状态，两人操作集合相同
4. 交替移动
5. 一个人不能移动就为输
6. 有限步内终止
###### 7.1.1.2 P状态与N状态
P - 必败态
N - 必胜态
1. 所有终止的状态是P状态
2. 能一步到达P状态的是N状态
3. 每一步都将到达N状态的为P状态

###### 7.1.1.3 SG函数和SG定理
sg函数值的意义，如果$sg(x)=0$，那么x是必败态，否则x是必胜态。
定义：$$sg(x)=min\{n\geq 0|n=sg(y),y\in  F(x)\}$$
$F(x)$表示x所有的下一个状态的集合。
定义mex函数为不在一个集合里的最小非负整数。则
$$sg(x)=mex\{sg(y)|y\in F(x)\}$$

SG定理：
$$sg(x_1,x_2,...,x_n)=sg(x_1) \oplus sg(x_2)\oplus ... \oplus sg(x_n)$$

求sg函数代码：
```cpp
const int maxn = 5e4 + 10;

//f[i]代表可行的转移方式 k代表方式总数

int f[maxn], k, sg[maxn];
bool vis[maxn];

void getsg(int n) {
    memset(sg, 0, sizeof sg);
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        for (int j = 1; f[j] <= i && j <= k; ++j) {
            vis[sg[i - f[j]]] = 1;
        }
        for (int j = 0;; ++j)
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
    }
}

```
##### 7.1.2 常见模型
###### 7.1.2.1 巴什博弈
一堆n个物品，每人每次轮流从中取出$1 - m$个，最后取光者胜。
结论：如果$n \% (m+1)==0$那么后手胜，否则先手获胜。
###### 7.1.2.2 nim博弈
两个人玩取石子游戏，共有N堆石子，每个人每次可以从一堆石子里面任意多个石子，最后取光者胜。
结论：亦或和为0先手必败，否则先手必胜。

阶梯nim：n级台阶，每级台阶上放有石子。每人每次选一级台阶上的若干石子移到下一层。第0层为地面。不能移动的为输。
结论：奇数级台阶的亦或和为0先手必败，否则先手必胜。
###### 7.1.2.3 反nim博弈
将nim改为最后取的人输。
必胜态有两种：
1. 所有石堆个数都是1,且有偶数堆。
2. 如果存在某堆个数不为1,那么亦或和不为0。
###### 7.1.2.4 威佐夫博弈
两个人玩取石子游戏，共有2堆石子，每个人可以选择从一堆石子里面取石子，也可以选择从两堆石子里面取相同数量的石子，最后取光者胜。
结论：必败局势为(a,b)(a<b)，满足
$$a=(int)(b-a)*\frac{\sqrt{5}+1}{2}$$

代码：

```cpp
		if (x > y)swap(x, y);
        double r = (sqrt(5.0) + 1) / 2;
        if ((int) ((double) (y - x) * r) == x)cout << "houshou" << endl;
        else cout << "xianshou" << endl;
```
###### 7.1.2.5 Moore’s Nimk
两个人玩取石子游戏，共有N堆石子，每个人每次可以从至多k堆石子里面任意多个石子，最后取光者胜。
结论：把n堆石子的石子数用二进制表示，统计每个二进制位上1的个数，若每一位上1的个数mod(k+1)全部为0，则必败。
###### 7.1.2.6 Fibonacci博弈
1堆石子有n个,两人轮流取。先取者第1次可以取任意多个，但不能全部取完。以后每次取的石子数不能超过上次取子数的2倍。最后取光者胜。
结论：先手必胜当且仅当识字数n不是Fibonacci数。

