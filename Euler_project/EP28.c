/*************************************************************************
	> File Name: EP28.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Oct 20 10:08:29 2021
 ************************************************************************/

#include <stdio.h>

//这个题教会我们先观察 找规律再写程序
int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += (4 * i * i - 6 * i + 6); 
    }
    printf("%d\n", sum);
    printf("%d\n", 500 / 6 *(32 * 250000 + 48 * 500 + 16) + 500 * 501 - 4);
    return 0;
}
