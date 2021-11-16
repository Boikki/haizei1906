/*************************************************************************
	> File Name: EP22.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二 11/16 11:25:35 2021
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include "EP22.h"
using namespace std;

int main() {
    int i = 0;
    long long ans, sum = 0;
    while(name[i++].length() != 0);
    std::sort(name, name + i - 1);
    i = 0;
    while (name[i].length() != 0) {
        sum = 0;
        for (int j = 0; j < name[i].length(); j++) {
            sum += name[i][j] - 'A' + 1;
        }
        ans += sum * (++i);
    }
    cout << ans << endl;
    return 0;
}
