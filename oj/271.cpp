/*************************************************************************
	> File Name: 271.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sat Nov 27 17:15:28 2021
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 300000

int arr[MAX_N + 5];
int q[MAX_N + 5];
//q记录的是arr里的下标信息，为啥呢
//因为在维护大小为k的窗口的时候
//你只有两个值怎么看它够没够k呢
//所以记录下标才能看
//这也提示我们记录的时候要记录原信息
//下标=>值 但是value推不出下标来

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int head = 0, tail = 0;
    q[tail++] = 0;
    for (int i = 0; i < n; i++) {
        while ((tail - head) && arr[q[tail - 1]] > arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - k) head++;
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for (int i = 0; i < n; i++) {
        while ((tail - head) && arr[q[tail - 1]] < arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - k) head++;
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
