/*************************************************************************
	> File Name: cilent.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Mar 23 16:26:47 2022
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "common.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage : ./cilent ip port name");
        exit(EXIT_FAILURE);
    }
    int sockfd;
    char buff[512];
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *name = argv[3];
    struct sockaddr_in server_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    send(sockfd, name, strlen(name), 0);
    while (1) {
        scanf("%[^\n]s", buff);
        getchar();
        send(sockfd, buff, strlen(buff), 0);
    }
    close(sockfd);
    return 0;
}
