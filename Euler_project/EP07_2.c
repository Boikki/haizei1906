/*************************************************************************
	> File Name: EP07_2.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Oct 22 09:54:16 2021
 ************************************************************************/

//素数筛
#include <stdio.h>

#define MAX_N 200000

int prime[MAX_N + 5];

int main() {
    for (int i = 2; i * i < MAX_N; i++) {
        //1-合数
        if (prime[i]) continue;
        for (int j = i << 1; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        //这边就是以0为计数位，第一个素数存在1-2
    }
    printf("%d", prime[10001]);
    

    return 0;
}
