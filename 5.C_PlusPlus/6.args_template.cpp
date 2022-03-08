/*************************************************************************
	> File Name: 6.args_template.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一  3/ 7 14:24:26 2022
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
    return ;
}
template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;

}


template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T __final;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::__final b) {
        return a + b;
    }
};
int main() {
    /*
    print(123, 'o', "hello world", 78.9);
    cout << sizeof(ARG<int, double, float>::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::rest::getT) << endl;
    ARG<int, double, float>::getT a = 123;
    cout << a << endl;
    //Test<int, double, float>
    Test<int(double, float)> d;
    Test<int(float)> e;
    Test<int(int, double, float)> f;
    */
    Test<int(double, float)> d;
    
    cout << d(2.3, 4.5) << endl;
    return 0;
}
