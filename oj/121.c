/*************************************************************************
	> File Name: 121.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Mon 30 Aug 2021 11:25:29 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {

    char a, b;
    scanf("%s%s", &a, &b);

    if (a == b) {
        printf("TIE\n");
    } else if ((a == 'O' && b == 'Y') || (a == 'Y' && b == 'H') || (a == 'H' && b == 'O')) {
        printf("MING\n");
    } else {
        printf("LI\n");
    }
    return 0;
}
