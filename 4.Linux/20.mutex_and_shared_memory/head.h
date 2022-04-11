/*************************************************************************
	> File Name: common.h
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Apr 11 09:55:13 2022
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

struct Msg {
    char message[32];
    pthread_mutexattr_t m_attr;
    pthread_mutex_t mutex;
};

char *get_shm(char *path, int id, int *shmid); 
#endif
