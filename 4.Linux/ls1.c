/*************************************************************************
	> File Name: ls1.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Mar 21 14:39:22 2022
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

void show_info(char *dirname) {
    struct stat info;
    if (stat(dirname, &info) < 0) {
        perror("stat");
    }
    printf("%s\t%lld\n", dirname, info.st_size);
    return ;
}
int main(int argc, char *argv[]) {
    struct dirent *entry;
    DIR *dir_ptr;
    if (argc == 1) show_info(".");
    if ((dir_ptr = opendir(*++argv)) == NULL) {
        perror("opendir");
    }
    while ((entry = readdir(dir_ptr)) != NULL) {
        show_info(entry->d_name);
    }
    closedir(dir_ptr);
    return 0;
}
