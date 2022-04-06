/*************************************************************************
	> File Name: my_cd.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Apr  6 16:37:18 2022
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
    printf("%s\n", getwd(NULL));
}
