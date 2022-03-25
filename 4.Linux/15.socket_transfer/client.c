/*************************************************************************
	> File Name: cilent.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Mar 23 16:26:47 2022
 ************************************************************************/


#include "common.h"
#define MAX_SIZE 1024

void send_file(int sockfd, char *path) {
    FILE *fp = fopen(path, "r");
    int num_read;
    char data[MAX_SIZE] = {0};
    while (1) {
        memset(data, 0, MAX_SIZE);
        num_read = fread(data, 1, MAX_SIZE, fp);
        if (send(sockfd, data, strlen(data), 0) < 0) {
            perror("send");
            fclose(fp);
            return ;
        }
        if (num_read == 0) break;
    }
    fclose(fp);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage : ./cilent ip port path");
        exit(EXIT_FAILURE);
    }
    int sockfd, sock_file;
    char buff[512];
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];
    char filename[50];
    struct sockaddr_in server_addr;
    if (access(path, R_OK) != 0) {
        perror("access");
        exit(EXIT_FAILURE);
    }
    char *p;
    strcpy(filename, (p = strrchr(path, '/')) ? p + 1 : path);
    printf("filename is %s\n", filename);
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
    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        perror("send");
    }
    int ack;
    if (recv(sockfd, &ack, sizeof(ack), 0) <= 0) {
        perror("receive ACK");
    }
    if (ack == 1) {
        if ((sock_file = socket_connect(server, 9999)) < 0) {
            perror("socket file connect");
            exit(EXIT_FAILURE);
        }
        printf("connect success!\n");
        send_file(sock_file, path);
        close(sock_file);
    }
    close(sockfd);
    return 0;
}
