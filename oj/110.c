/*************************************************************************
	> File Name: 110.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sun 29 Aug 2021 11:23:03 AM CST
 ************************************************************************/

#include<stdio.h>


int main() {

    float x;
    scanf("%f", &x);
    if (x <= 15) {
        printf("%.2f\n", x * 6);
    } else {
        printf("%.2f\n", 90 + (x - 15) * 9);
    }

    return 0;
}
