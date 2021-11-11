/*************************************************************************
	> File Name: EP01.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 14 10:40:46 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum3 = (3 + 999) * 333 >> 1;
    int sum5 = (5 + 995) * 199 >> 1;
    int sum15 = (15 + (1000 / 15) * 15) * (1000 / 15) >> 1;
    printf("%d\n", sum3 + sum5 - sum15);
    return 0;
}
