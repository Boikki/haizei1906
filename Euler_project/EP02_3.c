/*************************************************************************
	> File Name: EP02_2.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 14 11:54:51 2021
 ************************************************************************/

//滑动窗口法 我们通过2发现只需三个变量就可以实现
//并且fib的函数只和前两个有关系
//也就是%3
#include <stdio.h>

#define MAX_M 4000000
int fib[3] = {0, 1};

int main() {
    int sum = 0, n = 2;
    while (fib[(n - 1) % 3] + fib[(n - 2) % 3] <= MAX_M) {
        fib[(n) % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
        n++;
    }

    printf("%d\n", sum);
    return 0;
}
