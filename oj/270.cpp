/*************************************************************************
	> File Name: 270.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sat Nov 27 10:05:03 2021
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 300000
int q[MAX_N + 5] , head, tail;
//q这里存数组的下标 这是个很重要的编程技巧 因为要是存值那不和arr一样了
int64_t arr[MAX_N + 5];

int main() {
    int64_t n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while ((tail - head) && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    
    return 0;
}
