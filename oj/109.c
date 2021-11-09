/*************************************************************************
	> File Name: 109.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sun 29 Aug 2021 11:14:28 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, flag = 1;
    scanf("%d", &n);
    while (n && flag) {
        flag = n & 1;
        n /= 10;

    }
    printf(flag ? "NO" : "YES");
    return 0;
}
