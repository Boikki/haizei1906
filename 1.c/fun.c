/*************************************************************************
	> File Name: fun.c
	> Author: Ren Boyu 
	> Mail: renboyu2333@gmail.com
	> Created Time: 2021年03月16日 星期二 15时54分32秒
 ************************************************************************/

#include<stdio.h>

int f(int n) {
    if (n == 0) return 1; // 边界条件 写在前面才不会无限展开 展开道这里就停止了
    return n * f(n - 1); //递归公式
}

int main() {
    return 0;
}
