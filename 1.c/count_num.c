/*************************************************************************
	> File Name: count_num.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sat 28 Aug 2021 09:45:31 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n,i = 1;
    scanf("%d", &n);
    while (n / 10) {
        i++;
        n /= 10;
    }
    printf("%d\n", i);
    return 0;
}
