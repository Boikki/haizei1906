/*************************************************************************
	> File Name: EP36.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Oct 20 15:55:03 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int is_vaild(int n, int base) {
    int temp = 0, x = n;
    while (x) {
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == n;
}

int main() {
    int sum = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (!(is_vaild(i, 10) && is_vaild(i, 2))) continue;
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
