/*************************************************************************
	> File Name: EP34.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Oct 20 14:59:29 2021
 ************************************************************************/

#include <stdio.h>

#define MAX_N 2540160 
//9! * 7 比较9! * n and 10 ^ n - 1
//发现在7的时候还比他大，8的时候被反超，所以取到7

int num[10];

void init(int *num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
}

int is_vaild(int x, int *num) {
    int temp = x, val= 0;
    while (temp) {
        val += num[temp % 10];
        temp /= 10;
    }
    return x == val;
}

int main() {
    int sum = 0;
    init(num);
    for (int i = 2; i < MAX_N; i++) {
        if (!is_vaild(i, num)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
