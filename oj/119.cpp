/*************************************************************************
	> File Name: 119.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Mon 30 Aug 2021 10:26:10 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>

int days[13] = {0, 
               31, 28, 31, 30, 
               31, 30, 31, 31, 
               30, 31, 30, 31
               };

int Days(int y, int m) {

    return (days[m] + (m == 2 && (y % 400 ==0 || (y % 4 == 0 && y % 100 != 0))));
}


void prev_day(int &y, int &m, int &d) {
    d -= 1;
    if (d == 0) {
        m -= 1;
        if (m == 0) {
            y -= 1, m = 12;
        }

        d = Days(y, m);
    }
    return ;
}

void next_day(int &y, int &m, int &d) {
    d += 1;
    if (d > Days(y, m)) {
        m += 1;
        d = 1;
        if (m > 12) {
            y += 1;
            m = 1;
        }
    }
    return ;
}




int main() {

    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    prev_day(y, m, d);
    printf("%d %d %d\n", y, m, d);
    next_day(y, m, d);
    next_day(y, m, d);
    printf("%d %d %d\n", y, m, d);
    return 0;
}
