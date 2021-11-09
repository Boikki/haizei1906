/*************************************************************************
	> File Name: 158.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Sep 16 18:37:54 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d", n - i);
        for (int j = ((n - i)<< 1) - 1; j; j--) {
            printf(" ");
        }
        printf("%d\n", n - i);
    }
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    printf("0\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d", n - i);
        for (int j = ((n - i)<< 1) - 1; j; j--) {
            printf(" ");
        }
        printf("%d\n", n - i);
    }
    return 0;
}
