/*************************************************************************
	> File Name: 161.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Sep 15 14:17:50 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    double x;
    scanf("%lf%d", &x, &n);
    for (int i = 1; i <= n; i++) {
        x += x * 0.06;
    }
    printf("%.6lf\n", x);
    return 0;
}
