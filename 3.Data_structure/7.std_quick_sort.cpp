/*************************************************************************
	> File Name: 7.std_quick_sort.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四  2/10 17:23:34 2022
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

const int __threshold = 16;

void quick_sort_v2(vector<int> &nums, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = nums[l];
        while (x < y) {
            while (x < y && nums[y] >= z) y--;
            if (x < y) nums[x++] = nums[y];
            while (x < y && nums[x] <= z) x++;
            if (x < y) nums[y--] = nums[x];
        }
        nums[x] = z;
        quick_sort_v2(nums, x + 1, r);
        r = x - 1;
    }
    return ;
}

int getMid(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void __quick_sort_v3(vector<int> &nums, int l, int r) {
    while (r - l > __threshold) {
        int x = l, y = r, z = getMid(nums[l], (nums[(l + r) >> 1]), nums[r]);
        do {
            while (nums[x] < z) x++;
            while (nums[y] > z) y--;
            if (x <= y) {
                swap(nums[x], nums[y]);
                x++, y--;
            }
        } while (x <= y);
        __quick_sort_v3(nums, x + 1, r);
        r = y;
    }
}

void final_insert_sort(vector<int> &nums, int l, int r) { 
    // 无监督
    int ind = l;
    for (int i = l + 1; i <= r; i++) {
        if (nums[i] < nums[ind]) ind = i;
    }
    while (ind > l) {
        swap(nums[ind], nums[ind - 1]);
        ind--;
    }
    for (int i = l + 2; i <= r; i++) {
        int j = i;
        while (nums[j] < nums[j - 1]) {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    return ;
}

int main() {
    return 0;
}
