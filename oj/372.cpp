/*************************************************************************
	> File Name: 372.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sat Nov 27 21:22:37 2021
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 500000

int a[MAX_N + 5];
int b[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int p, top1, top2;
    top1 = top2 = 0;
    for (p = 1; p < n; p++) {
        while ((top1 != -1) && a[p] <= a[top1]) --top1;
        while ((top2 != -1) && b[p] <= b[top2]) --top2;
        if (top1 - top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
    }
    cout << p << endl;
    return 0;
}
