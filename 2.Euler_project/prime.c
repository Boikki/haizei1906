/*************************************************************************
	> File Name: prime.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 09:00:41 2021
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100

int is_prime[MAX_N + 5];
int prime[MAX_N + 5];

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i; 
        printf("prime[0] = %d\n", prime[0]);
        for (int j = 1; j <= prime[0]; j++) {
            //就是用当前的存下来的素数去标记后面的, i即M, j即 <= M的素
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            printf("MARK: %d * %d = %d\n", prime[j], i, prime[j] * i);
            printf("%d = %d\n", j, is_prime[j]);
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        printf("%d = %d\n", i, prime[i]);
        
    }
    return 0;
}
