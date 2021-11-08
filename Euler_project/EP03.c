/*************************************************************************
	> File Name: EP03.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Oct 19 10:46:50 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 600851475143LL

int main() {
    long long num = MAX_N, ans, i = 2;
    while (i * i <= MAX_N) {
        if (num % i == 0) ans = i; 
        // ans为当前最大素数因子
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num;
    printf("%lld\n", ans);

    
    return 0;
}

