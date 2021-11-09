/*************************************************************************
	> File Name: 14.argc.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Oct 12 15:49:31 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[]) {
    for (int i = 0; argv[i]; i++) {
        printf("[%d] is %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        printf("[%d] is %s\n", i, env[i]);
        //下面实现一个检测用户是不是我自己的功能
        if (strncmp(env[i], "USER=", 5) == 0 ){
            if(strncmp(env[i + 5], "renboy", 6)) {
                printf("you are not renboy\n");
                exit(0);
            }
        }
    }

    return 0;
}
