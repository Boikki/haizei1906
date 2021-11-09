/*************************************************************************
	> File Name: 113.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sun 29 Aug 2021 02:45:36 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
        if (m == 2) {
            printf("29\n");
        } else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            printf("31\n");
        } else {
            printf("30\n");
        }

    } else if (m == 2) {
        printf("28\n");
    } else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        printf("31\n");
    } else {
        printf("30\n");
    }
    return 0;
}
