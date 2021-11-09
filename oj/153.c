/*************************************************************************
	> File Name: 153.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 14 14:25:26 2021
 ************************************************************************/

#include <stdio.h>
int week[7] = {6, 7, 1, 2, 3, 4, 5};

int main() {

    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (m == 1) m = 13, y -= 1;
    else if (m == 2) m = 14, y -= 1;
    printf("%d", week[(d + 26 * (m + 1) / 10 + (y % 100) + (y % 100) / 4 + (y / 100) / 4 + 5 * (y / 100)) % 7]);
    return 0;
}
