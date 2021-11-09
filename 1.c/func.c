/*************************************************************************
	> File Name: func.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Wed 01 Sep 2021 12:21:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>

int max(int n, ...) {
    va_list arg;
    va_start(arg, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", va_arg(arg, int));
    }
    va_end(arg);

}

int main() {
    max(4, 6, 7, 8, 9);
    return 0;
}
