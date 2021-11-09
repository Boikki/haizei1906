/*************************************************************************
	> File Name: function.c
	> Author: Ren Boyu 
	> Mail: renboyu2333@gmail.com
	> Created Time: 2021年03月16日 星期二 17时06分24秒
 ************************************************************************/

#include<stdio.h>


int funA(int );
int funB(int );

/*
int funA(int a) {
    printf("funA = %d\n", a);
    if (a == 0) return 0;
    funB(a - 1);
    return a;
}

int funB(int b) {
    printf("funB = %d\n", b);
    if (b == 0) return 0;
    funA(b - 1);
    return b;
}
*/


int main() {
    funA(6);
    funB(6);

    return 0;
}
