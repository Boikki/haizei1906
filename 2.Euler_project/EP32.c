/*************************************************************************
	> File Name: EP32.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 六 11/13 09:10:21 2021
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 10000

bool add_to_num(int x, int *num) {
    while (x) {
        if (num[x % 10]) return false;
        num[x % 10] += 1;
        x /= 10;
    }
    return true;
}

static inline int digits(int x) {
    if (!x) return 1;
    return floor(log10(x) + 1);
}

bool is_pandigital(int a, int b, int c) {
    if (digits(a) + digits(b) + digits(c) - 9) return false;
    int num[10] = {0};
    int flag = 1;
    num[0] = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(c, num);
    return flag;
}

int can[MAX_N + 5];

int main() {
    int sum = 0;
    for (int i = 1; i < 100; i++) {
        for (int j = i + 1; j < 10000; j++) {
            // 1位数 * 4位数 >= 4位数 所以这样就够九位数了
            // 2位数 * 3位数 >= 4位数 所以取i 1、2位数 j 3、4位数
            if (!is_pandigital(i, j, i * j)) continue;
            if (can[i * j]) continue;
            sum += i * j;
            can[i * j] = 1;
        }
    }
    printf("%d", sum);
    return 0;
}
