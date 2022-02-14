/*************************************************************************
	> File Name: 7.radix_sort.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/13 11:55:09 2022
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define LOW16(a) (a & 0xffff)
//#define HIGH16(a) ((a & 0xffff0000) >> 16)

#define __HIGH16(a) (((a) & 0xffff0000) >> 16)
#define HIGH16(a) (__HIGH16(a) > INT16_MAX ? (__HIGH16(a) - 32768) : (__HIGH16(a) + 32768))
//修改之后对负数也能排序

void radix_sort(int *arr, int n) {
    int cnt[UINT16_MAX + 1] = {0};
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)  cnt[LOW16(arr[i])] += 1;
    for (int i = 1; i < UINT16_MAX + 1; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) temp[--cnt[LOW16(arr[i])]] = arr[i];

    for (int i = 0; i < UINT16_MAX + 1; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++)  cnt[HIGH16(arr[i])] += 1;
    for (int i = 1; i < UINT16_MAX + 1; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) arr[--cnt[HIGH16(temp[i])]] = temp[i];
    free(temp);
    return ;
}

int *getRandData(int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    srand(time(0));
    for (int i = 0; i < n; i++) temp[i] = (rand() % 2 ? 1 : -1) * (rand());
    return temp;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    int *arr = getRandData(MAX_OP);
    output(arr, MAX_OP);
    radix_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    return 0;
}
