/*************************************************************************
	> File Name: father.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Apr 11 10:48:30 2022
 ************************************************************************/

#include "common.h"

struct Msg {
    pid_t pid;
    char message[1024];
};

void *shared_memory = NULL;
struct Msg *msg;

void print() {
    printf("%s\n", msg->message);
}

int main() {
    int shmid;
    signal(10, print);
    key_t key = ftok(".", 8731);
    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0644)) < 0) {
        perror("shmget");
    }
    if ((shared_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
    }
    msg = (struct Msg *)shared_memory;
    msg->pid = getpid();
    for (;;) {
        pause();
    }
    return 0;
}
