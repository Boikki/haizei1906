/*************************************************************************
	> File Name: 149.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Sep 13 11:10:21 2021
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main() {
	
	char str[200];
	int cnt = 0;
	scanf("%50[^\n]", str);
    printf("strlen = %d", (int)sizeof(str));
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] - ' ' == 0) break;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
