/*************************************************************************
	> File Name: test.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sun Mar 20 21:29:23 2022
 ************************************************************************/

#include <stdio.h>

int main() {
    int a = 0x01234567;
    char *b = (char *)&a;
    printf("%x", *b);
}
