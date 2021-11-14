/*************************************************************************
	> File Name: EP43.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 10:59:02 2021
 ************************************************************************/
 // 全排列函数

#include <iostream>
using namespace std;

int64_t is_valid(int *a) {
    if (a[0] == 0) return 0;
    int p[7] = {2, 3, 5, 7, 11, 13, 17}, j = 0;
    int64_t num = a[0], ret = a[0];
    for (int i = 1; i < 10; i++) {
        num = num * 10 + a[i];
        ret = ret * 10 + a[i];
        if (i < 3) continue;
        // 这几行很巧妙
        // 19行将数字的前三位存了起来，直到第四次循环，即i = 3的时候才向下执行
        // 往下就是模拟题目的取三位数，即现在是a1a2a3a4, 减去a1*1000即可
        // 对于a2a3a4这个新数, 按照题目规则%相应的素数即可。
        num -= 1000 * a[i - 3];
        if (num % p[j++]) return 0;
    }
    return ret;
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    int64_t sum = 0, temp;
    do {
        sum += is_valid(a);
    } while (next_permutation(a, a + 10));
    cout << sum << endl;
    return 0;
}
