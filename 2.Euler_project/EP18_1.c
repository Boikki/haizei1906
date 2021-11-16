/*************************************************************************
	> File Name: EP18.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 09:27:20 2021
 ************************************************************************/
 //暴力递归 + 记忆化
 //也就是将每次递归的值存下来

#include <stdio.h>

#define MAX_N 20
int val[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5];

int dfs(int a, int b, int n) {
    if (a + 1 == n) return val[a][b]; //递归边界
    if (keep[a][b]) return keep[a][b];
    int val1 = dfs(a + 1, b, n);
    int val2 = dfs(a + 1, b + 1, n);
    return (keep[a][b] = (val1 > val2 ? val1 : val2) + val[a][b]);
}
//但是keep数组并没有加速太多 只是说算过的不用再算了 
//运行时还是走了两轮

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &val[i][j]);
        }
    }

    printf("%d", dfs(0, 0, MAX_N));
    return 0;
}
