/*************************************************************************
	> File Name: EP26.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/17 09:30:56 2021
 ************************************************************************/
 //find longest 小数 循环节
 //1 / n的余数最多是n - 1 个 [1, n - 1]
 //因为0不可以是余数 0表示除尽了
 //即循环节最长是n - 1 
 //当出现前边出现的余数了 就代表循环开始了

#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int len[MAX_N + 5];

int get_length(int d) {
    int r = 1, t = 1; // 余数和出现的时间点
    memset(len, 0, sizeof(len));
    while (r) {
        r *= 10;
        r %= d;
        t += 1;
        if (len[r]) return t - len[r];
        len[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, length = 1;
    for (int i = 2; i < MAX_N; i++) {
        int temp = get_length(i);
        if (temp > length) {
            length = temp;
            d = i;
        }

    }
    printf("%d", d);
    return 0;
}

