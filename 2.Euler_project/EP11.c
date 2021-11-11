/*************************************************************************
	> File Name: EP11.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 10:34:29 2021
 ************************************************************************/

#include <stdio.h>

#define MAX_N 20
//方向数组
//四个方向 二维平面
int dir[4][2] = {1, 0, 0, 1, 1, -1, 1, 1};
int grid[MAX_N + 5][MAX_N + 5];


int clac(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int p = 1;
        for (int j = 0; j < 4; j++) {
            int dx = x + j * dir[i][0];
            int dy = y + j * dir[i][1];
            if (dx < 0 || dx > MAX_N) break;
            if (dy < 0 || dy > MAX_N) break;
            p *= grid[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
}
int main() {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            int p = clac(i, j);
            if (p > ans) ans = p;
        }   
    }
    printf("%d", ans);
    return 0;
}
