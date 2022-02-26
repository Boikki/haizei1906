/*************************************************************************
	> File Name: 176.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  2/25 16:50:30 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    char *s1 = NULL;
    char *s2 = NULL;
    size_t t1 = 0, t2 = 0;
    getline(&s1, &t1, stdin);
    getline(&s2, &t2, stdin);
    int ans = 0;
    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';
    int l = strlen(s1) - strlen(s2);
    int l2 = strlen(s2);
    for (int i = 0; i <= l; i++) {
        if (strncmp(s2, &s1[i], l2) == 0) ans += 1;
    }
    cout << ans << endl;


    return 0;
}
