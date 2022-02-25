/*************************************************************************
	> File Name: 181.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  2/24 09:17:25 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >='A' && str[i] <= 'Z') {
            str[i] += 32;
        } else if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    cout << str << endl;
    return 0;
}

