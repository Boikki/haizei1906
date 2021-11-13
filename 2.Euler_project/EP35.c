/*************************************************************************
	> File Name: EP35.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 六 11/13 15:42:48 2021
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 1000000

int is_prime[MAX_N] = {0};
int prime[MAX_N] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}


bool is_circular_prime(int n) {
    if (is_prime[n]) return false;
    int x = n, h, j;
    h = (int)pow(10, floor(log10(n))); //权
    j = (int)floor(log10(n)) + 1; //位数
    for (int i = 0; i < j; i++) {
        printf("%d\n", x);
        x = x / 10 + (x % 10) * h;
        if (is_prime[x]) return false;
    }
    return true;
}

int main() {
    init_prime();
    int sum = 0;
    for (int i = 1; i < prime[0]; i++) {
        if(prime[i] > MAX_N) break;
        if (is_circular_prime(prime[i])) sum += 1;
    }
    printf("%d\n", sum);
    return 0;
}
