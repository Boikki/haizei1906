/*************************************************************************
	> File Name: 135.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Wed 08 Sep 2021 03:33:57 PM CST
 ************************************************************************/

#include<stdio.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Days(int y, int m) {
    return (days[m] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))));
}


void next_day(int &y, int &m, int &d) {
    d += 1;
    if (d > Days(y, m)) {
        m += 1, d = 1;
        if (m > 12) {
            y += 1, m = 1;
        }
    }
    return ;
}
int main() {
    int x, y, m, d;
    scanf("%d", &x);
    scanf("%d%d%d", &y, &m, &d);
    for (int i = 0; i < x; i++) {
        next_day(y, m, d);
    }

    printf("%d %d %d", y, m, d);
    return 0;
}
