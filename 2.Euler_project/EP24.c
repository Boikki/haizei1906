/*************************************************************************
	> File Name: EP24.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 15:52:57 2021
 ************************************************************************/
 // 全排列状态
 // 将n个数从小到大全排列 取第1000000个数
 // 对于12345的全排列 不妨将12345看作第一种状态 求其第100种状态
 // 第一位由1跳2进行了4! = 24次 100 / 24 = 4 即由1变成5 51234
 // 还剩4次 第三位由2跳3 2! = 2次 但是我们求的是最小的状态 所以先让第三位跳1 即51324
 // 这时还剩两次 2跳两次即可 51342
 // 本程序就是模拟了这个过程

#include <stdio.h>

#define MAX_N 10
int fact[MAX_N + 5];
int num[MAX_N + 5] = {0}; //标记哪一位能用 最高位看成第n位

void init(int n) {
    fact[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        num[i] = 1;
    }
    return ;
}
/*
 *
int get_num(int k, int val, int n, int* x) {
    int step = k / val; // step就是我们除出来的要在第几位开始跳
    int t = 0, i = 0;
    for (; i < n && t <= step; i++) {
        t += num[i];
    }
    // 举个例子
    // 0 1 2 3 4 下标
    // 0 0 1 1 1 num
    // if step = 0 当前状态可以取的最小值是2
    // if step = 1 t += num[2]; t = 1 此时t <= step
    // 可以执行i++ i = 3, t += num[3] t = 2;
    *x = i;
    k %= val;
    return k;
}
*
*/

int get_num(int k, int val, int n, int* x) {
    int step = k / val;
    *x = 0;
    for (int t = 0; t <= step; (*x) += (t <= step)) {
        t += num[*x];
    }
    k %= val; 
    num[*x] = 0;
    return k;
}

int main() {
    init(MAX_N);
    //主函数里开始计算第1000000位全排列数
    int k = 1000000 - 1; // 当前应该跳k步了
    for (int i = 10; i >= 1; i--) { 
        int x;
        k = get_num(k, fact[i - 1], MAX_N, &x); //fact = 每位改变的状态数 即n!;  get_num return 当前改变的状态数
        printf("%d", x);
    }

    return 0;
}

