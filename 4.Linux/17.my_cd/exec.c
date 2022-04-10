/*************************************************************************
	> File Name: exec.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri Apr  8 10:49:08 2022
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
    pid_t pid;
    char filename[512] = {0};
    char name[512] = {0};
    char tmp[5] = {0};
    char cc_flag[50] = {0};
    int status;
    if (ac != 2) {
        printf("Usage : ./a.out file\n");
        exit(1);
    }
    strcpy(filename, av[1]);
    char *sub;
    sub = strstr(filename, ".");
    strncpy(name, filename, (sub - filename));
    strcpy(tmp, sub);
    if (!strcmp(tmp, ".c")) {
        strcpy(cc_flag, "gcc");
    } else if (!strcmp(tmp, ".cpp")) {
        strcpy(cc_flag, "g++");
    } else {
        printf("file type not support.\n");
        exit(2);
    }
    if ((pid = fork()) < 0) {
        perror("fork vim");
        exit(3);
    }
    if (pid == 0) {
        execlp("/usr/bin/vim", "vim", filename, NULL);
    }
    //在此基础上编写退出之后编译，编译成功立刻执行

    wait(status);

    pid_t _pid;
    if ((_pid = fork()) < 0) {
        perror("fork complier");
    }
    if (_pid == 0) {
        execlp("/usr/bin/g++", "g++", filename, NULL);
    }
    return 0;
}
