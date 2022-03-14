/*************************************************************************
	> File Name: 7.c++11_lambda_expression.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sun Mar 13 15:09:25 2022
 ************************************************************************/

#include <iostream>
using namespace std;

auto add = [](int a, int b) {
    return a + b;
};

auto Data = [](int a, int b) {
    return [=](auto func) {
        return func(a, b);
    };
};

function<int()> Temp_Func() {
    int a = 23;
    return [=]() -> int {
        return a;
    };
};

auto first = [](int a, int b) {
    return a;
};
auto second = [](int a, int b) {
    return b;
};

int main() {
    cout << add(2, 4) << endl;
    auto func = Temp_Func();
    cout << func() << endl;
    auto a = Data(2, 4);
    cout << a(first) << endl;
    cout << a(second) << endl;
    return 0;
}
