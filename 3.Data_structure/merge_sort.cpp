/*************************************************************************
	> File Name: merge_sort.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 12/21 10:24:19 2021
 ************************************************************************/

#include <iostream>
using namespace std;

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && (num[l] > num[r])) swap(num[l], num[r]);
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 >= r) {
        if (p2 > r || (p1 <= mid && (num[p1] <= num[p2]))) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

int main() {
    return 0;
}
