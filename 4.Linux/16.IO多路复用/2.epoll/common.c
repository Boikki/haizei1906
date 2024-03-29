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

int socket_connect(char *host, int port) {
    int sockfd;
    struct sockaddr_in server;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        //没必要perror
        return -1;
    }
    return sockfd;
}

int socket_accept(int sockfd) {
    //todo
    return 1;
}
