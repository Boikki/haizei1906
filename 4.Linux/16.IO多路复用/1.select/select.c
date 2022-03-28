/*************************************************************************
	> File Name: select.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri Mar 25 19:50:57 2022
 ************************************************************************/

#include "common.h"

#define MAX_CLIENTS 40
#define PORT 8888
#define MAX_SIZE 1024

typedef struct server_data {
    int client_cnt;
    int client_fds[MAX_CLIENTS];
    fd_set all_fds;
    int max_fd;
} server_data;

server_data *s_d = NULL;

void accept_client(int server_listen) {
    int client_fd = -1;
    client_fd = socket_accept(server_listen);
    if (client_fd == -1) {
        perror("socket accept");
        return ;
    }
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (s_d->client_fds[i] < 0) {
            s_d->client_fds[i] = client_fd;
            s_d->client_cnt++;
            break;
        }
    }
}

void recv_send(fd_set *readfds) {
    int client_fd;
    char buff[MAX_SIZE] = {0};
    int num;
    char ip[20] = {0};
    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    for (int i = 0; i < s_d->client_cnt; i++) {
        client_fd = s_d->client_fds[i];
        if (client_fd < 0) {
            continue;
        }
        if (FD_ISSET(client_fd, readfds)) {
            num = recv(client_fd, buff, MAX_SIZE, 0);
            if (num <= 0) {
                FD_CLR(client_fd, &(s_d->all_fds));
                close(client_fd);
                s_d->client_fds[i] = -1;
                continue;
            }
            getpeername(client_fd, (struct sockaddr *)&client, &len);
            strcpy(ip, inet_ntoa(client.sin_addr));
            printf("<%s> : %s ", ip, buff);
            num = send(client_fd, buff, strlen(buff), 0);
            if (num > 0) {
                printf("[snet ✅] \n");            
            } else {
                printf("[sent ❌]");
            }
        }
    }
    return ;
}

void do_client(int server_listen) {
    int client_fd = -1, ret;
    fd_set *readfds = &(s_d->all_fds);
    struct timeval tm;
    while (1) {
        FD_ZERO(readfds);
        FD_SET(server_listen, readfds);
        s_d->max_fd = server_listen;
        tm.tv_sec = 5;
        tm.tv_usec = 0;
        for (int i = 0; i < s_d->client_cnt; i++) {
            client_fd = s_d->client_fds[i];
            if (client_fd != -1) {
                FD_SET(client_fd, readfds);
            }
            s_d->max_fd = (client_fd > s_d->max_fd ? client_fd : s_d->max_fd);
        }
        ret = select(s_d->max_fd + 1, readfds, NULL, NULL, &tm);
        if (ret == -1) {
            perror("select");
            return ;
        }
        if (ret == 0) {
            printf("time out!\n");
            continue;
        }
        if (FD_ISSET(server_listen, readfds)) {
            printf("before accept!\n");
            accept_client(server_listen);
            printf("after accept!\n");
        } else {
            recv_send(readfds);
        }
    }
    return ;
}

int main(int ac, char **av) {
    int server_listen;
    s_d = (server_data *)malloc(sizeof(server_data));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        s_d->client_fds[i] = -1;
    }
    s_d->client_cnt = 0;
    server_listen = socket_create(PORT);
    if (server_listen < 0) {
        perror("socket create");
        exit(EXIT_FAILURE);
    }
    printf("init linsten socket = %d !\n", server_listen);
    do_client(server_listen);
    return 0;
}
