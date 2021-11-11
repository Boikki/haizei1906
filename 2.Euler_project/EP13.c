/*************************************************************************
	> File Name: EP13.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/11 18:32:02 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 50

char num[MAX_N + 5];
int ans[MAX_N + 5] = {0};

int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", num); // 读入数组
        int len = strlen(num);
        //这里取巧 将数组倒着存 这样的话进位可以在末尾解决 0存放数组的长度
        if (ans[0] < len) ans[0] = len;
        for (int i = 0; i < len; i++) {
            ans[len - i] += num[i] - '0'; 
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (ans[0] == i);
            //29: 若ans[i] < 10则不可能进行到这一步, 到这一步说明ans[i] > 10, 即最高位产生了进位
            //if (ans[i + 1]) ans[0] += 1;
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}
