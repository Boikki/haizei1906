/*************************************************************************
	> File Name: common.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Mar 23 16:42:03 2022
 ************************************************************************/

#include "common.h"

int socket_create(int port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("bind");
        close(sockfd);
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        perror("listen");
        close(sockfd);
        return -1;
    }
    return sockfd;
}

int socket_create_nonblock(char *ip, int port, long timeout) {
    int sockfd, ret;
    struct sockaddr_in server;
    struct timeval tm;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    printf("connect to %s : %d\n", ip, port);

    unsigned long ul = 1;
    ioctl(sockfd, FIONBIO, &ul);
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    tm.tv_sec = 0;
    tm.tv_usec = timeout;
    int error;
    int len = sizeof(error);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        if (select(sockfd + 1, NULL, &set, NULL, &tm) > 0) {
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len) < 0) {
                perror("getsockopt");
                ret = -1;
            }
            if (error == 0) ret = 1;
            else ret = -1;
        }
    }
    close(sockfd);
    return ret;
}
