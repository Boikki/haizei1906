/*************************************************************************
	> File Name: 137.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Wed 08 Sep 2021 04:07:34 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char a = 'A';
    for (char i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%c", a++);
        }
        printf("\n");
    }
    return 0;
}
