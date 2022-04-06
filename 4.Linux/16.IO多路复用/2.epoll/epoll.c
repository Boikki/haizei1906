/*************************************************************************
	> File Name: epoll.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sun Mar 27 17:17:25 2022
 ************************************************************************/

#include "common.h"

#define BUFF_SIZE 1024
#define MAX_CLIENTS 1024
#define PORT 7777

typedef struct UserData {
    int fd;
    char name[20];
    char msg[BUFF_SIZE];
} UserData;

UserData *userdata = NULL;
userdata = (UserData *)malloc(sizeof(UserData) * MAX_CLIENTS);

int main() {
    int server_listen;
    struct epoll_event events[MAX_CLIENTS], ev;
    if ((server_listen = socket_create(PORT)) < 0) {
        perror("socket create");
        exit(EXIT_FAILURE);
    }
    int epollfd;
    epollfd = epoll_create(MAX_CLIENTS);
    ev.events = EPOLLIN;
    userdata[server_listen]->fd = server_listen;
    ev.data.ptr = &userdata[server_listen];
    epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev);
    for ( ; ; )  {
        int nfds = epoll_wait(epollfd, events, MAX_CLIENTS, -1);
        for (int i = 0; i < nfds; i++) {
            if (ev[i].data.ptr->fd && server_listen && events[i].events & EPOLLIN) {
                int sockfd = accept(server_listen, NULL, NULL);
                recv(sockfd, userdata[sockfd]->name, 20, 0);
                userdata[sockfd]->fd = sockfd;
                ev.events = EPOLLIN;
                ev.data.ptr = userdata[sockfd];
                epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev);
            } else if (events[i].events & EPOLLIN) {
                int recv_num = recv(
                    ((UserData *)events[i].data.ptr)->fd,
                    userdata[((UserData *)events[i].data.ptr)->fd].msg, 
                    BUFF_SIZE, 0);
                if (recv_num <= 0) {
                    printf("closed by peer!\n");
                    close(((UserData *)events[i].data.ptr)->fd);
                    memset(&userdata [((UserData *)events[i].data.ptr)->fd], 0, sizeof(UserData));
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, ((UserData *)events[i].data.ptr)->fd, &ev);
                } else {
                    UserData *tmp_d = (UserData *)events[i].data.ptr;
                    printf("<%s> : %s\n", tmp_d->name, temp_d->msg);
                    ev.events = EPOLLOUT;
                    ev.data.ptr = &userdata(temp_d->fd);
                    epoll_ctl(epollfd, EPOLL_CTL_MODm tem_d->fd, &ev);
                }
            } else if ()
        }
    } 

}
