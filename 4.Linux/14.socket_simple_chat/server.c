/*************************************************************************
	> File Name: server.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Mar 23 17:16:48 2022
 ************************************************************************/


#include "common.h"

int main(int ac, char **av) {
    int port, sockfd, sockfd_listen;
    struct sockaddr_in client_addr;
    pid_t pid;
    if (ac != 2) {
        printf("Usage : ./server port\n");
        exit(EXIT_FAILURE);
    }
    port = atoi(av[1]);
    if ((sockfd_listen = socket_create(port)) < 0) {
        exit(EXIT_FAILURE);
    }
    socklen_t len = sizeof(client_addr);
    while (1) {
        if ((sockfd = accept(sockfd_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accpet");
            continue;
        }
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            char name[50] = {0};
            char buff[512];
            recv(sockfd, name, 50, 0);
            printf("[login] %s on %s : %d\n", name, inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
            while (1) {
                memset(buff, 0, sizeof(buff));
                if (recv(sockfd, buff, 512, 0) <= 0) {
                    close(sockfd);
                    break;
                }
                printf("[info] %s : %s\n", name, buff);
            }
        } else {
            close(sockfd);
        }
    }
    

    return 0;
}
