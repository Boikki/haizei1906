/*************************************************************************
	> File Name: 13.ls2.c
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Tue Mar 22 09:45:07 2022
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <string.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
#include <math.h>


#define LEN 512

int ls_opt = 0;
char work_dir[LEN];

void do_ls(char *);
void do_stat(char *);
void show_file_info(char *, struct stat *);
void mode_to_letters(mode_t, char *);
void size_window(char file_name[][LEN], int cnt, int *row, int *col);
void show_files(char file_name[][LEN], int cnt, int row, int col);
char *gid_to_name(gid_t);
char *uid_to_name(uid_t);


int main(int argc, char *argv[]) {
    int opt;
    getwd(work_dir);
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a' : ls_opt += 1; break;
            case 'l' : ls_opt += 2; break;
            default : exit(1);
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);
    if (argc == 1) {
        do_ls(".");
    } else {
        while (--argc) {
            do_ls(*(++argv));
        }
    }
    return 0;
}

int cmp_name(const void *_a, const void *_b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    return strcmp(a, b);
}

void do_ls(char *dirname) {
    printf("%s:\n", dirname);
    chdir(work_dir);
    DIR *dir_ptr = NULL;
    struct dirent *direntp;
    int row, col;
    char file_name[LEN][LEN] = {0};
    int cnt = 0;
    if ((dir_ptr = opendir(dirname)) == NULL) {
        perror("opendir");
    } else {
        while ((direntp = readdir(dir_ptr)) != NULL) {
            strcpy(file_name[cnt++], direntp->d_name);
        }
        qsort(file_name, cnt, LEN, cmp_name);
    }
    if (ls_opt >= 2) {
        chdir(dirname);
        for (int i = 0; i < cnt; i++) {
            do_stat(file_name[i]);
        }
    } else if(ls_opt == 0) {
        size_window(file_name, cnt, &row, &col);
        show_files(file_name, cnt, row, col);
    }
    return ;
}

void size_window(char file_name[][LEN], int cnt, int *row, int *col) {
    struct winsize size;
    int len[cnt];
    int max = 0, all = 0;
    memset(len, 0, cnt * sizeof(int));
    if (isatty(STDOUT_FILENO) == 0) {
        exit(1);
    }
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }
    for (int i = 0; i < cnt; i++) {
        len[i] = strlen(file_name[i]);
        if (max < len[i]) max = len[i];
        all += len[i] + 2;
    }
    if (max > size.ws_col) {
        *row = cnt;
        *col = 1;
        return ;
    }
    if (all < size.ws_col) {
        *row = 1;
        *col = cnt;
        return ;
    }
    int try_begin = 0;
    for (int i = 0, tmp = 0; i < cnt; i++) {
        tmp += (len[i] + 2);
        if (tmp > size.ws_col) {
            try_begin = i;
            break;
        }
    }
    for (int i = try_begin; ; i--) {
        int *wide = (int *)malloc(sizeof(int) * i);
        memset(wide, 0, sizeof(int) * try_begin);
        *row = (int)ceil(cnt / i);
        int try_sum = 0;
        for (int x = 0; x < i; x++) {
            for (int y = x * *row; y < (x + 1) * *row && y < cnt; y++) {
                if (wide[x] < len[y]) wide[x] = len[y];
            }
            try_sum += (wide[x] + 2);
        }
        if (try_sum > size.ws_col) continue;
        else {
            *col = i;
            break;
        }
    }
    return ;
}

void show_files(char file_name[][LEN], int cnt, int row, int col) {
    int wide_file[cnt];
    memset(wide_file, 0, sizeof(int) * cnt);
    for (int i = 0; i < col; i++) {
        for (int j = (i * row); j < (i + 1) * row && j < cnt; j++) {
            if (wide_file[i] < strlen(file_name[j])) wide_file[i] = strlen(file_name[j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = i; j < i + (row * col) && j < cnt; j = j + row) {
            int tmp = j / row;
            printf("%-*s  ", wide_file[tmp], file_name[j]);
        }
        printf("\n");
    }
}

void do_stat(char *file_name) {
    struct stat info;
    if (stat(file_name, &info) == -1) {
        perror(file_name);
    } else {
        show_file_info(file_name, &info);
    }
    return ;
}

void show_file_info(char *file_name, struct stat *info) {
    char mode_str[11] = "----------";
    char *uid_to_name(), *gid_to_name(), *ctime();
    mode_to_letters(info->st_mode, mode_str);
    printf("%s ", mode_str);
    printf("%4d ", (int)info->st_nlink);
    printf("%-8s ", uid_to_name(info->st_uid));
    printf("%-8s ", gid_to_name(info->st_gid));
    printf("%8ld ", (long)info->st_size);
    printf("%.12s ", 4 + ctime(&info->st_mtime));
    printf("%s\n", file_name);
    return ;
}

void mode_to_letters(mode_t mode, char *str) {
    if (S_ISREG(mode)) str[0] = '-';
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
    if (S_ISLNK(mode)) str[0] = 'l';
    if (S_ISSOCK(mode)) str[0] = 's';
    if (S_ISFIFO(mode)) str[0] = 'p';

    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
    return ;
}

char *uid_to_name(uid_t uid) {
    struct passwd *pw_ptr;
    static char num_str[10] = {0};
    if ((pw_ptr = getpwuid(uid)) == NULL) {
        sprintf(num_str, "%d", uid);
        return num_str;
    } else {
        return pw_ptr->pw_name;
    }
}


char *gid_to_name(gid_t gid) {
    struct group *grp_ptr;
    static char num_str[10] = {0};
    if ((grp_ptr = getgrgid(gid)) == NULL) {
        sprintf(num_str, "%d", gid);
        return num_str;
    } else {
        return grp_ptr->gr_name;
    }
}
