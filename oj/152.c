/*************************************************************************
	> File Name: 152.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Sep 13 20:27:51 2021
 ************************************************************************/

#include <stdio.h>

char week[10][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", week[(n + 2) % 7]);
    return 0;
}
