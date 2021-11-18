/*************************************************************************
	> File Name: EP29_1.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/17 10:05:29 2021
 ************************************************************************/

 //筛法思想求
 //不同的幂数

#include <stdio.h>
#include <math.h>
#define MAX_N 100

int f[MAX_N + 5][MAX_N + 5];

int main() {
    for (int i = 2; i *i <= MAX_N; i++) {
        for (int j = 2; j <= MAX_N; j++) {
            // f[i][j]  表示的是(x ^ i) ^ j
            if (f[i][j]) continue;
            for (int k = 2; k * k <= j; k++) {
                if (j % k) continue;
                int a1 = k, a2 = j / k;
                // f[i ^ a1][j] = 1 但是 i ^ a1 有可能越界
                // a1 最小是2 所以将i循环条件设成i * i <= MAX_N
                if (1.0 * a1 * log10(i) <= 2) f[(int)pow(i, a1)][a2] = 1;
                if (1.0 * a2 * log10(i) <= 2) f[(int)pow(i, a2)][a1] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = 2; j <= MAX_N; j++) {
            sum += (f[i][j] == 0);
        }
    }
    printf("%d", sum);
    return 0;
}

