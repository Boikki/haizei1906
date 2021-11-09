/*************************************************************************
	> File Name: 133.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Tue 07 Sep 2021 03:52:50 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            (j - i) && printf("\t");
            printf("%d*%d=%d", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}
