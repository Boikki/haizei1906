/*************************************************************************
	> File Name: 270.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/20 14:21:21 2022
 ************************************************************************/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> q;
vector<int> arr;


int main() {
    int n, m, a, ans;
    cin >> n >>  m;
    arr.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    q.push_back(0);
    ans = arr[1];
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
        if (i - q.front() > m) q.pop_front();
        ans = max(ans, arr[i] - arr[q.front()]);
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
    }
    cout  << ans << endl;

    return 0;
}
