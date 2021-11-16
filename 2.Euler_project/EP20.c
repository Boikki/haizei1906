/*************************************************************************
	> File Name: EP20.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 11:12:49 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100000

int num[MAX_N + 5];
int main() {
    num[0] = num[1] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= num[0]; j++) num[j] *= i;
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (num[0] == j);
        }
    }
    int sum = 0;
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    printf("%d", sum);
    return 0;
}
