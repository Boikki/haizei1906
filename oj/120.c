/*************************************************************************
	> File Name: 120.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Mon 30 Aug 2021 11:12:21 AM CST
 ************************************************************************/

#include<stdio.h>


int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Days(int y, int m) {
    return (days[m] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100))));
}

int main() {

    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (y < 0 || m > 12 || d < 0 || d > Days(y, m)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
