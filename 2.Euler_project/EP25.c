/*************************************************************************
	> File Name: EP25.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/11 11:15:38 2021
 ************************************************************************/
 //先导知识 EP13 大整数加法
 //本题求第一个1000位的fib数是第几项
 //循环数组+大整数加法

#include <stdio.h>
#include <math.h>
#define MAX_N 1000

int fib[3][MAX_N + 5];

int main() {
    int n = 2; 
    fib[1][0] = fib[2][0] = 1; //存大整数的位数
    fib[1][1] = fib[2][1] = 1;

    while (fib[n % 3][0] < 1000) {
        n++;
        int n0 = n % 3, n1 = (n - 1) % 3, n2 = (n - 2) % 3;
        for (int i = 1; i <= fib[n1][0]; i++) {
            fib[n0][i] = fib[n1][i] + fib[n2][i];
        }
        fib[n0][0] = fib[n1][0];
        for (int i = 1; i <= fib[n0][0]; i++) {
            if (fib[n0][i] < 10) continue;
            fib[n0][i + 1] += fib[n0][i] / 10;
            fib[n0][i] %= 10;
            fib[n0][0] += (fib[n0][0] == i);
        }
    }
    printf("%d\n", n);
    
    return 0;
}
