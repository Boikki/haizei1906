/*************************************************************************
	> File Name: 169.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  2/25 16:20:42 2022
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, num[128] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a >> b;
        num[(int)a] = b;
    }
    string str;
    int ret = 0;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        ret += num[(int)str[i]];
    }
    cout << ret << endl;
    return 0;
}
