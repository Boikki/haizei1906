/*************************************************************************
	> File Name: EP04.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Oct 19 11:31:57 2021
 ************************************************************************/

#include <stdio.h>

int main() {
    int ans = 0;
    for (int i = 0; i < 998002; i++) {
        int x = i;
        int temp = 0;
        // 注意变量作用域
        // 写到for外边temp每次就不会初始化了
        while (x) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        if ((i == temp) && i > ans) ans = i;
    }
    printf("%d", ans);
    return 0;
}
