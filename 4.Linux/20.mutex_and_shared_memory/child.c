/*************************************************************************
	> File Name: child.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Apr 11 13:51:56 2022
 ************************************************************************/

#include "head.h"

struct Msg *msg;

int main() {
    int shmid;
    msg = (struct Msg *)get_shm(".", 8731, &shmid);
    if (msg == NULL) {
        exit(1);
    }
    pthread_mutexattr_init(&msg->m_attr);
    pthread_mutexattr_setpshared(&msg->m_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&msg->mutex, &msg->m_attr);
    for (;;) {
        pthread_mutex_lock(&msg->mutex);
        printf("<Input> : ");
        scanf("%s", msg->message);
        pthread_mutex_unlock(&msg->mutex);
    }

    return 0;
}
