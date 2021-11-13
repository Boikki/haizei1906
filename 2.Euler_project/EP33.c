/*************************************************************************
	> File Name: EP33.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 六 11/13 15:14:20 2021
 ************************************************************************/

 //找奇异的

#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

bool is_non_trivial(int x, int y) {
    int x1, y1, x2, y2;
    x1 = x / 10, x2 = x % 10;
    y1 = y / 10, y2 = y % 10;
    if (!x1 || !x2 || !y1 || !y2) return false;
    if (x1 == y1 && x2 * y == y2 * x && x2 != 0) return true;
    if (x1 == y2 && x2 * y == y1 * x && x2 != 0) return true;
    if (x2 == y2 && x1 * y == y1 * x && x1 != 0) return true;
    if (x2 == y1 && x1 * y == y2 * x && x1 != 0) return true;
    return false;
}

int main() {
    int x = 1, y = 1, c;
    for (int i = 10; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            if (!(is_non_trivial(i, j))) continue;
            x *= i, y *= j;
            c = gcd(x, y);
            x /= c, y /= c;
        }
    }

    printf("%d", y);
    return 0;
}


