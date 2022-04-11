/*************************************************************************
	> File Name: head.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Apr 11 13:30:38 2022
 ************************************************************************/

#include "head.h"

char *get_shm(char *path, int id, int *shmid) {
    char *shared_memory = NULL;
    key_t key = ftok(path, id);
    if ((*shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
    }
    if ((shared_memory = shmat(*shmid, NULL, 0)) == NULL) {
        perror("shmat");
    }
    return shared_memory;
}
