/*************************************************************************
	> File Name: 1.sort_245.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/20 16:07:26 2022
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100000
int a[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    nth_element(a + 1, (a + (1 + n) / 2), a + 1 + n);
    //nth_element是将(a + (n + 1) / 2)放到它对应的位置, 即a + k位置的值放到k位置上。
    //快速选择算法就是它的底层实现
    int p = a[(n + 1) >> 1], ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - p);
    }
    cout << ans << endl;
    return 0;
}
