/*************************************************************************
	> File Name: EP06.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Oct 19 15:42:45 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum1 = 0;
    int sum2 = 5050 * 5050;
    for (int i = 1; i < 101; i++) {
        sum1 += i * i;
    }
    printf("%d\n", sum2 - sum1);
    return 0;
}
