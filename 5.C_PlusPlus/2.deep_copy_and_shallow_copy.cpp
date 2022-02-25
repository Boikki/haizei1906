/*************************************************************************
	> File Name: 2.deep_copy_and_shallow_copy.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  2/23 10:43:00 2022
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

class A {
public :
    A() { 
        n = 160;
        str = new char[n]; 
    }
    A(const A &obj) : A() {
        memcpy(str, obj.str, sizeof(char) * n);
        str[strlen(str)] = 'a';
        str[strlen(str) + 1] = '\0';
    }
    void set_str(const char *dest) {
        strcpy(str, dest);
    }
    void output_str() {
        cout << str << endl;
    }
    ~A() {
        printf("%p\n", str);
        delete[] str;
    }

private :
    int n;
    char *str;

};

int main() {
    A a;
    a.set_str("hello haizei");
    A b = a;
    a.output_str();
    b.output_str();
    return 0;
}
