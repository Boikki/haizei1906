/*************************************************************************
	> File Name: EP02.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 14 10:59:59 2021
 ************************************************************************/

#include <stdio.h>

//#define MAX_N 4000000

#define MAX_N 44
#define MAX_M 4000000
int fib[MAX_N + 5];

int main() {
    fib[1] = 1, fib[2] = 2;
    int sum = 0;
    for (fib[0] = 2; fib[fib[0]] <= MAX_M; fib[0]++) {
        fib[fib[0] + 1] = fib[fib[0]] + fib[fib[0] - 1];
    }
    for (int i = 1; i <= fib[0]; i++) {
        if (fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}

int main() {
    fib[1] = 1, fib[2] = 2;
    int sum = 0, n = 2;
    for (n = 2; fib[n] <= MAX_M; n++) {
        fib[n + 1] = fib[n] + fib[n - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}

int main() {
    fib[1] = 1, fib[2] = 2;
    int n = 2;
    while (fib[n] + fib[n - 1] < MAX_M) {
        fib[n + 1] = fib[n - 1] + fib[n];
        n++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}
