/*************************************************************************
	> File Name: 167.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sat Nov 27 15:51:48 2021
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    cout << a.size() << endl;
    cout << a.find("a") + 1 << endl;
    cout << a.insert(n - 1, b) << endl;
    return 0;
}
