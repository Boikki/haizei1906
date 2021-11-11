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

int fib[3];

int main() {
    int n = 2; 
    fib[1] = 1, fib[2] = 1;
    while (log10(fib[n % 3]) + 1 < 3.0) {
        n++;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        printf("%d\n", fib[n % 3]);
    }
    printf("%d", n);
    
    return 0;
}
