/*************************************************************************
	> File Name: EP07_3.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Oct 22 10:38:35 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5]; 
//sortage prime ,zero represents the 当前的第几个 prime
int is_prime[MAX_N + 5]; 
//sortage is_prime or not

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}
