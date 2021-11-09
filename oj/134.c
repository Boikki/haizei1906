/*************************************************************************
	> File Name: 134.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Tue 07 Sep 2021 04:30:19 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    

    int a, b, flag = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        !(i % 11) && flag && printf(" ");
        if (i % 11 == 0) {
            printf("%d", i);
            flag = 1;
        }
    }
    printf("\n");

    return 0;
}
