中国剩余定理（拓展）
--------------------

### 中国剩余定理

中国剩余定理可以求出以下的一元线性同余方程组中$x$的一个解：
$$(S):\left\{
\begin{aligned}
x \equiv & a_1 \pmod {m_1} \\
x \equiv & a_2 \pmod {m_2} \\
\vdots \\
x \equiv & a_n \pmod {m_n}
\end{aligned}
\right.$$

假设整数$m_1,m_2, ... ,m_n$两两互质，则对任意的整数：$a_1,a_2, ... ,a_n$，方程组$(S)$有解，并且通解可以用如下方式构造得到：
设$M=\prod_{i=1}^{n}m_i$，并设$M_i=\frac{M}{m_i}$，$t_i=M_i^{-1}\pmod m_i$
即： $$x\equiv \sum_{i=1}^{n}a_it_iM_i \pmod M$$

### 拓展中国剩余定理

当$gcd(m_1,m_2)\ne 1$时，考虑合并两个方程： $$x\equiv c_1\pmod {m_1}$$
$$x\equiv c_2\pmod {m_2}$$ 显然有$x=c_1+k_1m_1$, $x=c_2+k_2m_2$,
即$c_1+k_1m_1=c_2+k_2m_2$ 移项得$k_1m_1=k_2m_2+c_2-c_1$
我们令$t=gcd(m_1,m_2)$,
则有$\frac{m_1}{t}k_1=\frac{m_2}{t}k_2+\frac{c_2-c_1}{t}$
**当且仅当$t|c_2-c_1$时可以合并** 此时有
$$\frac{m_1}{t}k_1\equiv \frac{c_2-c_1}{t}(mod\ \frac{m_2}{t})$$
使用扩展欧几里得求得$k_1$的通解：
$$k_1=ans+k\times \frac{m_2}{t}\ (k\in \mathbb{Z})$$
将$k_1$代回第一个方程得:
$$x\equiv ans\times m_1+k\times\frac{m_1\times m_2}{t}+c_1$$
最终再变换成同余方程的形式：
$$x\equiv ans\times m_1+c_1(mod\ \frac{m_1\times m_2}{t})$$
这是一个同余方程的形式，如此不断合并所有方程即可。
