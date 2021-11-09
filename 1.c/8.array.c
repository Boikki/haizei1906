/*************************************************************************
	> File Name: 8.array.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sun Sep 19 16:09:06 2021
 ************************************************************************/

#include <stdio.h>

int func(int (*a)[200]) {
    a[0][1] = 1;
    return 0;
}

int main() {
    int arr[100][200];
    func(arr); 
    //为什么我们在像func函数传入一个指针的指针时候不可以呢。
    //这就涉及到**指针的特性。
    // a[0] + 1 ,a[0]是指向一片200个int型变量的指针。+1会移动800bit
    // 但是*a 是指针的指针，+1只会移动8bit。这两个根本不能进行等价操作。
    // 但是将改成func(int (*a)[200]) 也就是*a是指向一片200int数组的指针。
    // 类似的 传递三维数组的时候，也只能省略一个维度。

    return 0;
}
