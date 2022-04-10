/*************************************************************************
	> File Name: my_cd.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Apr  6 16:37:18 2022
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define MAX_N 1024

char path[MAX_N] = {0};

int main(int ac, char *av[]) {
    if (ac > 2) {
        printf("Invalid argument!\n");
        return 1;
    } else if (ac == 1) {
        strcpy(path, ".");
    } else {
        strcpy(path, av[1]);
    }
    printf("Before : %s\n", getwd(NULL));
    if (chdir(path) < 0) {
        perror("path error");
        // 只能在出现错误的时候使用
        // 如果之前出现过errno
        // 之后没出过错
        // 每次调用perror都是原来那个错
        return 2;
    }
    printf("After : %s\n", getwd(NULL));
    sleep(10);
    return 0 ;
}
