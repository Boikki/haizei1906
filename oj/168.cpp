/*************************************************************************
	> File Name: 168.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Sat Nov 27 16:04:33 2021
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string name[105];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }
    for (int i = 0; i < n; i++) {
        if (name[i][0] > 'a' && name[i][0] < 'z') name[i][0] -= ('a' - 'A');
        for (int j = 1; j < name[i].size(); j++) {
            if (name[i][j] > 'A' && name[i][j] < 'Z') name[i][j] += ('a' - 'A');
        }
    }
    for (int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }

    return 0;
}
