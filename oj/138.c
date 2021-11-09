/*************************************************************************
	> File Name: 138.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Wed 08 Sep 2021 04:28:02 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i) * 2; j++) {
            printf("A");
        }
        printf("\n");
    }
    return 0;
}
