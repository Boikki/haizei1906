/*************************************************************************
	> File Name: EP31.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 五 11/12 08:32:31 2021
 ************************************************************************/

 // 加法原理 递推关系 DP引入
 // 递推关系:
     // 1. 设计递推状态: 本题为拼💰的方法总数, 前n种钱币拼m元的方法数:f(n, m)
     // 2. 拆成若干个没有交集的集合: 比如本题就是把f(n, m)拆成两个，一个是不用第n种钱币 f(n - 1, m);
     // 另一个是用第n种钱 f(n, m - w(n)) w(n)为第n种钱的面值 (容斥原理也能解决, 在找两个独立集合比较难的时候
     // 我们可以找两个有交集的, 再减去他们的交集)
     //

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 8
#define MAX_M 200
int w[MAX_N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int64_t f[MAX_M + 5][MAX_M + 5];

int main() {
    for (int i = 0; i < MAX_N; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= MAX_M; j++) {
            // 拆成两步进行
            f[i][j] = 0;
            if (i - 1 >= 0) f[i][j] += f[i - 1][j];
            if (j >= w[i]) f[i][j] += f[i][j - w[i]]; //为了让坐标合法 比如凑3块钱就不用看大于2的了
        }
    }
    printf("%" PRId64 "\n", f[MAX_N - 1][MAX_M]);

    return 0;
}
