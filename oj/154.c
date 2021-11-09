/*************************************************************************
	> File Name: 154.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 14 14:48:14 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i; i--) {
        for (int j = i; j; j--) {
            (j - i) && printf(" ");
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
