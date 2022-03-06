/*************************************************************************
	> File Name: 6.template_思考题.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 日  3/ 6 15:23:42 2022
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T, typename ...REST>
struct ARG {
    typedef T __type;
    typedef ARG<REST...> __rest;
};

template<typename T>
struct ARG<T> {
    typedef T __type;
    typedef T __final;
};

template<typename T, typename ...ARGS> struct Test;
template<typename T, typename ...ARGS>
struct Test<T(ARGS...)> {
    T operator()(typename ARG<ARGS...>::__type a, typename ARG<ARGS...>::__rest::__final b) {
        return a + b;
    }
};

int main() {
    Test<int(double, int)> func_a;
    Test<int(int, int, int)> func_b;
    cout << func_a(1.9, 79) << endl;
    return 0;
}

