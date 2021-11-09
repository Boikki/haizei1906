/*************************************************************************
	> File Name: palindrome.c
	> Author: Ren Boyu 
	> Mail: renboyu2333@gmail.com
	> Created Time: 2021年03月14日 星期日 18时14分53秒
 ************************************************************************/


 #define likely __builtin_expect(!!(x), 1)
// likely代表x经常成立
 #define unlikely __builtin_expect(!!(x), 0)
// unlikely反之
// CPU取指令的五步流水线: 1.取指令 2.指令解析 3.取数据 4.执行 5.回显
// 也就是
#include<stdio.h>


