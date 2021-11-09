/*************************************************************************
	> File Name: 150.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Sep 13 19:32:13 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200

int num[MAX_N + 5][MAX_N + 5];

int main() {
    int n, m, flag = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            j != n - 1 && printf(" ");
            printf("%d", num[j][i]);
        }
        printf("\n");
    }
    return 0;
}
