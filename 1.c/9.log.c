/*************************************************************************
	> File Name: 9.log.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 21 10:53:37 2021
 ************************************************************************/

//功能 输出日志

#include <stdio.h>

#ifdef DEBUG

#define log(fmt, args...) { \
    printf("[%s : %d]", __func__, __LINE__); \
    printf(fmt, ##args); \
    printf("\n"); \
}
// ##代表链接, 可连接任何东西
#else
#define log(fmt, args...)
#endif
#define CONCAT(a, b) a##b
int main() {
    int a = 7;
    int abcdef = 19;
    log("%d", a);
    log("hello world");
    log("%d", abcdef);
    CONCAT(a, bcdef) = 21;
    log("%d", abcdef);
    return 0;
}
