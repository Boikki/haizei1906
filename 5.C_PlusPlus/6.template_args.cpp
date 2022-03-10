/*************************************************************************
    > File Name: 6.prefect_add_template.cpp
    > Author: rEn Chong 
    > Mail: renboyu@hrbeu.edu.cn 
    > Created Time: 一  3/ 7 09:36:41 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private :
    int x;
};
/*
template<typename T, typename U>
auto ((*((T *)0)) + (*((U *)0)) add(T &a, U &b) {
    return a + b;
}
*/
template<typename T, typename U>
auto  add(T &a, U &b) -> decltype(a + b) {
    return a + b;
}

template<typename T>
struct Print {
    template<typename U>
    void operator()(U &&a) {
        cout << a << endl;
        return ;
    }
};


template<typename T>
void print(const T &a) {
    cout << a << endl;
    cout << "-------end--------" << endl;
    return ;
}
template<typename T, typename ...ARGS>
void print(const T &a, ARGS... args) {
    cout << a << endl;
    print(args...);
    return ;
}

template<int n, typename T, typename ...U>
struct ARG {
    typedef T type;
    typedef typename ARG<n - 1, U...>::getT getT;
};
template<typename T, typename ...U>
struct ARG<1, T, U...> {
    typedef T type;
    typedef T getT;
};
template<typename T, typename ...U> struct Convertor;
template<typename T, typename ...U>
struct Convertor<T(U...)> {
    T operator()(typename ARG<1, U...>::getT &a, typename ARG<2, U...>::getT &b) {
        return a;
    }
};

template<int n, int m>
void func() {
    cout << n + m << endl;
    return ;
}

template<int n>
struct IsOdd {
    IsOdd();

public :
    const static bool r = n % 2;
};

template<int n, int i>
struct GetNextN {
    const static int r = (n > 0 && n % i != 0) * n;

};

template<int n, int i>
struct GetNextI {
    const static int r = (i * i <= n ? i + 1 : 0);
};
template <int n, int i>
struct TestPrime {
    const static int r = TestPrime<GetNextN<n, i>::r, GetNextI<n, i>::r>::r;
};
template <int i>
struct TestPrime<0, i> {
    const static int r = 0;
};
template <int n>
struct TestPrime<n, 0> {
    const static int r = 1;
};
template<int n>
struct IsPrime {
    IsPrime();
    const static bool r = TestPrime<n, 2>::r;
};

int main() {
    int a = 3, b = 4;
    double c = 4.5;
    A d(2);

    cout << add<decltype(a + b)>(a, b) << endl;
    //decltype 用来确定表达式的值，比如有一个exp的值我们不好确定，可以用decltype(exp()) x;
    //的形式声明一个同类型的x
    cout << add(a, b) << endl;
    cout << add(d, a) << endl;
    print(2, 2.3, "hello");
    print("hello");
    func<2, 4>();
    cout << IsOdd<3>::r << endl;
    cout << IsOdd<2>::r << endl;
    cout << IsPrime<9>::r << endl;
    cout << IsPrime<1000007>::r << endl;
    return 0;
}
