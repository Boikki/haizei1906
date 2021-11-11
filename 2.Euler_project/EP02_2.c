/*************************************************************************
	> File Name: EP02_2.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 14 11:54:51 2021
 ************************************************************************/

//简单写法 md整理
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
