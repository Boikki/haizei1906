/*************************************************************************
	> File Name: 131.cpp
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Tue 07 Sep 2021 03:41:57 PM CST
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;



int main() {

    int n, a;
    int32_t ans_min = INT32_MAX, ans_max = INT32_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans_min = min(ans_min, a);
        ans_max = max(ans_max, a);

    }
    cout << ans_max - ans_min << endl;
    return 0;
}
