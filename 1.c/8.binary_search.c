/*************************************************************************
	> File Name: 8.binary_search.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Sep 20 10:50:51 2021
 ************************************************************************/

#include <stdio.h>

int binary_search(int *arr, int x, int n) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1 ;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;

} 
//上面是传统的二分查找，12行的<=会有很多种情况。
//比如head tail重合，比如head tail差一个
//13行也会有很多，head + tail + 1还是head + tail
//下面给出不用顾虑的做法


int binary_search(int *arr, int x, int n) {
    int head = 0, tail = n - 1, mid;
    while (head + 3 <= tail) {
        mid = (head + tail) >> 1 ;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    for (int i = head; i <= tail; i++) {
        if (arr[i] == x) return i;
    }
    return -1;

} 

//也就是二分一遍之后，head和tail之间怎么也得有
//0-3个元素，最后只需遍历一遍即可。
//接上文说的数组和函数的共同点，函数f(x) = y;
//不正是数组下标和值的索引关系吗
//所以将传入指针改成函数指针

int binary_search(int (*arr)(int), int x, int n) {
    int head = 0, tail = n - 1, mid;
    while (head + 3 <= tail) {
        mid = (head + tail) >> 1 ;
        if (arr(mid) == x) return mid;
        else if (arr(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    for (int i = head; i <= tail; i++) {
        if (arr(i) == x) return i;
    }
    return -1;

} 


int main() {

    return 0;
}
