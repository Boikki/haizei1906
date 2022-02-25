/*************************************************************************
	> File Name: 170.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  2/24 09:49:15 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    int found = 0;
    for (int i = 0; i < n; i++) {
        while ((found = str[i].find("Ban_smoking")) != -1) {
            str[i].replace(found, 11, "No_smoking");
        }
    }
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    
    return 0;
}
