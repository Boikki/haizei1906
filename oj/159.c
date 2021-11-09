/*************************************************************************
	> File Name: 159.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Sep 16 18:53:51 2021
 ************************************************************************/

#include <stdio.h>


int main() {
    char ch;
    scanf("%s", &ch);
    for (int i = 0; i <= ch - 'A'; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = i; j <= ch - 'A'; j++) {
            printf("%c", ch - j);
        }
        for (int j = ch - 'A'; j > i; j--) {
            printf("%c", ch - j);
        }
        printf("\n");
    }
    return 0;
}
