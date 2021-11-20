
# Summary of EP01, 02, 03, 04, 06, 28, 30, 34, 36

### EP01

**description:** 找出0-1000内3和5的倍数

#### solution 1

暴力求解，找出3和5的来之后再减去15的。因为15的相当于算了两次。

#### soultion 2

观察倍数，发现这实际上是一个等差数列。直接求和，$O(1)$



### EP02 

**description**:求4000000以下的奇数项的Fibonacci的sum

#### solution 1

首先确定上界即数组的大小，我们要开一个数组进行fib数列的迭代。

下面给出推导过程，放缩：
$$
\begin{align*}
& F(n) = F(n - 1) + F(n-2) \\
& F(n - 1) = F(n - 2) + F(n - 3) \\
& \because F(n-2)>F(n-3)\\
& \therefore F(n-2) > 0.5F(n-1)\\
& 带入1式 有: F(n)>1.5F(n-1) \\
& 也就是F(n) > 1.5^nF(0) = 1.5^n
\end{align*}
$$
$log_{1.5}^{4000000} < 44$

所以开到44即可

让数组的0位作为fib的项数进行暴力迭代

#### soultion 2 滚动数组

通过上个方法我们发现$F(n)$的值只和$F(n-1)$和$F(n-2)$有关。所以我们只开三个大小的数组就够了。

用`n % 3 = (n - 1) % 3 + (n - 2) % 3, n = 2`就能实现。

再精简其实两个就够了

```c
f[0] = 1, f[1] = 1;
int n = 2;
while (fib[n % 2] < 4000000) {
    n++;
    int n0 = n & 1, n1 = n0 ^ 1;
    fib[n0] += fib[n1];
    if (n0) sum += fib[n0];
}
```

#### solution 3

其实还是两个滚动数组的变形，用两个变量`a, b` 替代进行相加:

```c
#include <stdio.h>
#define MAX_M 4000000
int main() {
    int sum = 0;
    int a = 0, b = 1;
    // 咱说有编程洁癖咋办，我就想让一开始的变量是0, 1
    // fib向前推，可得前几项为0, 1, 1, 2, 3.
    // 负数部分就是-2, 1, -1
    while (a + b < MAX_M) {
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
```

### EP03 整数最大素因子

显然，对于一个正整数n，有$n = a * b \  \ (a <= b)$

所以程序设计的时候只需循环到$\sqrt{n}$



