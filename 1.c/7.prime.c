/*************************************************************************
	> File Name: 7.prime.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sun Sep 19 10:38:33 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000

void init_prime() {
    int prime[MAX_N + 5];
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
        
    }
    return ;
}

int main() {
    init_prime();
    return 0;
}
