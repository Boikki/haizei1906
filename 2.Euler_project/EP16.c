/*************************************************************************
	> File Name: EP16.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 08:59:31 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 400

int num[MAX_N + 5];

int main() {
    int sum = 0;
    num[0] = 1, num[1] = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= 1024;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (num[0] == j);
        }
    }
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}