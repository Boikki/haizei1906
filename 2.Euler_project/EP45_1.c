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
#include <inttypes.h>


int64_t triangle(int64_t n) {
    return n * (n + 1) >> 1;
}

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t hexagonal(int64_t n) {
    return n * ((n << 1) - 1);
}

bool binary_search(int64_t n, int64_t x, int64_t (*func)(int64_t)) {
    int head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (func(mid) == x) return true;
        else if (func(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return false;
}

int main() {
    int64_t n = 144;
    while (!(binary_search(n * 2, hexagonal(n), pentagonal))) n++;
    printf("%" PRId64 "\n", n);
    return 0;
}

