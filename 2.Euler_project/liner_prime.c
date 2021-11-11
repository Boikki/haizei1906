/*************************************************************************
	> File Name: liner_prime.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 09:47:28 2021
 ************************************************************************/

#include <stdio.h>

#define MAX_N 2000000

int prime[MAX_N] = {0};
int is_prime[MAX_N] = {0};

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[10001]);
}
