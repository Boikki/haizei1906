/*************************************************************************
	> File Name: 174.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  2/25 21:26:06 2022
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX_N 3000000

char ret[MAX_N + 5];

int main() {
    char *str = NULL;
    size_t strcap = 0;
    getline(&str, &strcap, stdin);
    str[strlen(str) - 1] = '\0';
    for (int i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            ret[j] = str[i]; 
            j++;
        } else {
            ret[j] = '%';
            ret[j + 1] = '2';
            ret[j + 2] = '0';
            j += 3;
        }
    }
    cout << ret << endl;
    return 0;
}


