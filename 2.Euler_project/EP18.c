/*************************************************************************
	> File Name: EP18.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 09:27:20 2021
 ************************************************************************/
 //暴力递归

#include <stdio.h>

#define MAX_N 20
int val[MAX_N + 5][MAX_N + 5];

int dfs(int a, int b, int n) {
    if (a + 1 == n) return val[a][b];
    int val1 = dfs(a + 1, b, n);
    int val2 = dfs(a + 1, b + 1, n);
    return (val1 > val2 ? val1 : val2) + val[a][b];
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &val[i][j]);
        }
    }

    printf("%d", dfs(0, 0, MAX_N));
    return 0;
}
