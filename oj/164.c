/*************************************************************************
	> File Name: 164.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Sep 17 10:04:16 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m, flag = 0;
    scanf("%d%d", &n, &m);
    if (n % m) {
        flag = 1;
    }
    printf ("%d\n", n / m + flag);
    return 0;
}
