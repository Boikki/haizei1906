/*************************************************************************
	> File Name: 173.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  2/24 09:30:08 2022
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char *str = NULL;
    size_t strcap = 0;
    ssize_t strlen;
    strlen = getline(&str, &strcap, stdin);
    int alpha = 0, num = 0, space = 0, other = -1;
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            alpha += 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            num += 1;
        } else if (str[i] == ' ') {
            space += 1;
        } else {
            other += 1;
        }
    }
    cout << alpha << " " << num << " " << space << " " << other << endl;
    return 0;
}
