/*************************************************************************
	> File Name: EP45.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 16:11:35 2021
 ************************************************************************/

 // 函数指针
 // 取巧 6边形数一定是三角形数
 // 换元的方法

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100000

int triangle(int n) {
    return n * (n + 1) >> 1;
}

int pentagonal(int n) {
    return n * (3 * n - 1) >> 1;
}

int hexagonal(int n) {
    return n * ((n << 1) - 1);
}

bool binary_search(int n, int (*func)(int)) {
    int head = 1, tail = n, mid;
    mid = (head + tail) >> 1;
    int t;
    while (head <= tail) {
        t = func(mid);
        if (t == n) return true;
        if (t < n) head = mid + 1;
        else tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return false;
}

int main() {
    int n = 1, flag = 2, t;
    while (flag) {
        ++n;
        t = hexagonal(n);
        if (binary_search(t, pentagonal) && binary_search(t, triangle)) flag--;
    }
    printf("%d\n", n);
    return 0;
}

