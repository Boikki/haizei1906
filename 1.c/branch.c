/*************************************************************************
	> File Name: branch.c
	> Author: Ren Boyu 
	> Mail: renboyu2333@gmail.com
	> Created Time: 2021年03月15日 星期一 17时56分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    int a, b;
    a = 0, b = 0;
    if ((a++) && (b++)) {
        printf("true!\n");
    } else {
        printf("false!\n");
    }
    if ((a++) || (b++)) {
        printf("true!\n");
    } else {
        printf("false!\n");
    }
    srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
    }



    return 0;
}
