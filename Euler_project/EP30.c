/*************************************************************************
	> File Name: EP30.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Oct 20 14:23:42 2021
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 354294

int is_vaild(int x) {
    int temp = x, num = 0;
    while (temp) {
        num += pow((temp % 10), 5);
        temp /= 10;
    }
    return x == num;
}

int main() {
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_vaild(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
