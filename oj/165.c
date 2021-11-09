/*************************************************************************
	> File Name: 165.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Sep 17 10:27:52 2021
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    long long c, cnt = 0;
    scanf("%lld", &c);
    for (long long i = 1; i < c; i++) {
        long long j = sqrt(c * c - i * i);
        if (i * i + j * j == c * c) {
            cnt++;
        } 
    }
    printf("%lld\n", cnt / 2);
    return 0;
}
