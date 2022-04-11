/*************************************************************************
	> File Name: shm_1.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Apr 11 09:54:44 2022
 ************************************************************************/

#include "common.h" 
#define PAGE_SIZE 4096


char *shared_memory = NULL;
void *print(int i) {
    printf("{Father} : %s = %d\n", shared_memory, i);
    return NULL;
}
int main() {
    int shmid;
    pid_t pid;
    key_t key = ftok(".", 8731);
    if ((shmid = shmget(key, PAGE_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shared_memory = (char *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        for (; ;) {
            printf("<child> : \n");
            scanf("%s", shared_memory);
            kill(getppid(), 32);
        }
    } else {
        for (; ;) {
        signal(32, print(1));
            printf("<Father> :  %s\n", shared_memory);
            sleep(4);
        }
    }
    return 0;
}

