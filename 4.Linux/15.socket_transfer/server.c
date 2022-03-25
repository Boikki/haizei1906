/*************************************************************************
	> File Name: server.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Thu Mar 24 17:43:03 2022
 ************************************************************************/

#include "common.h"
#define MAX_SIZE 1024

int main(int argc, char **argv) {
    int port, server_listen, server_fd, server_file, server_file_listen;
    char buff[MAX_SIZE] = {0};
    char pathname[100] = {0};
    int pid;
    if (argc != 2) {
        printf("Usage : ./server part\n");
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket create");
        exit(EXIT_FAILURE);
    }
    if ((server_file_listen = socket_create(9999)) < 0) {
        perror("socket create");
        exit(EXIT_FAILURE);
    }
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len;
        char ip[20] = {0};
        if ((server_fd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        strcpy(ip, inet_ntoa(client_addr.sin_addr));
        if (opendir(ip) == NULL) {
            mkdir(ip, 0755);
        }
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            if (recv(server_fd, buff, sizeof(buff), 0) < 0) {
                perror("recv filename");
            }
            sprintf(pathname, "%s/%s", ip, buff);
            printf("%s", pathname);
            printf("accept success = %d\n", server_fd);
            int ack = 1;
            send(server_fd, &ack, sizeof(ack), 0);
            if ((server_file = accept(server_file_listen, NULL, NULL)) < 0) {
                perror("server_file_listen");
            }
            FILE *fp = fopen(pathname, "w+");
            while (1) {
                int size;
                memset(buff, 0, sizeof(buff));
                if ((size = recv(server_file, buff, sizeof(buff), 0)) > 0) {
                    fwrite(buff, 1, size, fp);
                }
                if (size <= 0) {
                    close(server_file);
                    break;
                }
            }
            fclose(fp);
        }
        close(server_fd);
    }
    close(server_listen);
    return 0;
}

