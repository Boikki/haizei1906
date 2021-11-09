/*************************************************************************
	> File Name: 114.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sun 29 Aug 2021 04:13:17 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char x;
    scanf("%c", &x);
    switch(x) {
        case 'h' : printf("He\n");
        break;
        case 'l' : printf("Li\n");
        break;
        case 'c' : printf("Cao\n");
        break;
        case 'd' : printf("Duan\n");
        break;
        case 'w' : printf("Wang\n");
        break;
        default : printf("Not Here\n");

    }
    return 0;
}
