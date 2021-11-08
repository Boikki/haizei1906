/*************************************************************************
	> File Name: EP07_1.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Oct 22 09:11:59 2021
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>


// inline bool is_prime(int x) __attribute__((always_inline));

//整理inilne关键字

extern inline bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (!(x % i)) return false;
    }
    return true;
}

int main() {
    int cnt = 0, i = 1;
    while (cnt < 10001) {
        i++;
        if (is_prime(i)) cnt++;
    }
    printf("%d\n", i);
    return 0;
}
