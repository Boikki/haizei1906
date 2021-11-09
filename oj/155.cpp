/*************************************************************************
	> File Name: 155.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 14 15:11:01 2021
 ************************************************************************/

#include <stdio.h>

int num(int n) {
    if (n == 1) {
        return 3;
    }
    return num(n - 1) + ((n - 1) << 1);
}

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", num(i));
        sum += num(i);
    }
    printf("%d\n", sum);
    
    return 0;
}
