/*************************************************************************
	> File Name: fork.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Thu Apr  7 15:42:43 2022
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    char *a = "abcd";
    int status;
    pid = fork();
    if (pid == 0) {
        printf("Chlid : %d -> %d\n", getpid(), getppid());
        exit(1);
    } else {
        pid = wait(&status);
        printf("Father : %d = %d\n", getpid(), status);
        if (WIFEXITED(status)) printf("exit status = %d\n", WEXITSTATUS(status));
    }
    printf("%s\n", a);
    return 0;
}
