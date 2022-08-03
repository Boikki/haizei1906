/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 12/21 10:34:36 2021
 ************************************************************************/

#include <iostream>
using namespace std;

void quick_sort(int *num, int l, int r) {
    if (r < l) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[y] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

int main() {
    int arr[4] = {3, 5, 2, 1};
    quick_sort(arr, 0, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
