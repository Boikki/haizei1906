/*************************************************************************
	> File Name: EP10.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 09:29:25 2021
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX_N 2000000

int prime[MAX_N + 5];

int main() {
    int64_t sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }   
    }
    printf("%" PRId64 "\n", sum);
    return 0;
}

