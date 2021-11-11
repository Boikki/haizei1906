/*************************************************************************
	> File Name: EP08.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 08:55:19 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define MAX_N 1000

char num[MAX_N + 5];

int main() {
    int len = 0;
    // while (~scanf("%s", num + len)) len += strlen(num + len);
    while (~scanf("%c", num + len)) len += 1;
    printf("%s", num);
    int64_t p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) p *= num[i];
        else zero += 1;
        if (i - 13 < 0) continue;
        if (num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
