/*************************************************************************
	> File Name: 139.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Wed 08 Sep 2021 08:05:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (n << 1) - 1; i++) {
        for (int j = 0; j < abs(n - i - 1); j++) {
            printf(" ");
        }
        for (int k = 0; k < (n - abs(n - i - 1)) << 1; k++) {
            printf("A");
        }
        printf("\n");
    }
    return 0;
}
