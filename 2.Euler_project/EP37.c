/*************************************************************************
	> File Name: EP37.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 09:22:24 2021
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>


#define MAX_N 50000000

int prime[MAX_N];
int is_prime[MAX_N];

void init_prime() {
    is_prime[0] = is_prime[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

bool is_truncatable(int n) {
    if(is_prime[n]) return false;
    int x = n, h;
    h = (int)pow(10, floor(log10(n)));
    while (x) {
        if (is_prime[x]) return false;
        x /= 10;
    }
    x = n;
    while (x) {
        if (is_prime[x]) return false;
        x -= (x / h) * h;
        h /= 10;
    }
    return true;
}

int main() {
    init_prime();
    int sum = 0, flag = 11;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (!is_truncatable(prime[i])) continue;
        sum += prime[i], flag -= 1;
        printf("%d\n", prime[i]);
    }
    !flag && printf("%d\n", sum);
    return 0;
}
