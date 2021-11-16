/*************************************************************************
	> File Name: EP18.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 09:27:20 2021
 ************************************************************************/
 //暴力递归
 // dp 实际上是不用递归的！

#include <stdio.h>

#define MAX_N 20


int val[MAX_N + 5][MAX_N + 5];

int max(a, b) {
    return (a > b ? a : b);
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    for (int i = MAX_N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    //实际上我们这个过程是模拟了递归的回溯，没了递归的从上向下走的过程
    //

    printf("%d", val[0][0]);
    return 0;
}
