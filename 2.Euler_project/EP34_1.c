/*************************************************************************
	> File Name: EP34_1.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Oct 20 15:21:31 2021
 ************************************************************************/

 

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define MAX_N 2540160 // 9! * 7

void init(int32_t *num) {
    num[0] = 1;
    for (int32_t i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
    return ;
}

bool IsCurious(int32_t n, int32_t *a) {
    if (n <= 2) return false;
    int32_t sum = 0, x = n;
    while (n) {
        sum += a[n % 10];
        n /= 10;
    }
    return sum == x;
}

int32_t solve(int32_t *num) {
    int32_t sum = 0;
    for (int32_t i = 10; i <= MAX_N; i++) {
        if (IsCurious(i, num))
            sum += i;
    }
    return sum;
}

int32_t main() {
    int32_t num[10] = {0};
    init(num);
    int32_t sum = solve(num);
    printf("%d\n", sum);
    return 0;
}

