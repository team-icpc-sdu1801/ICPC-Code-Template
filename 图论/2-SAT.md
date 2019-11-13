图论
====

2-SAT
-----

对于$a_i$，用第$2i-1$和$2i$表示取$0$和$1$，一条边$x->y$表示选了$x$必选$y$
$i'$表示$i$的反面：

1.  $i,j$不能同时选：$i\to j',j\to i'$， 一般为$a_i xor a_j=1$

2.  $i,j$必须同时选：$i\to j,j\to i$， 一般为$a_i xor a_j=0$

3.  $i,j$只能选其一：$i\to j',j\to i',i'\to j,j'\to i$
    一般为$a_i or a_j=1$

4.  必须选$i$：$i'\to i$ 一般为$a_i=1$ 或 $a_i and a_j=1$


