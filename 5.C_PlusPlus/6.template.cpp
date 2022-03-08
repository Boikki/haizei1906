/*************************************************************************
	> File Name: 6.template.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一  3/ 7 13:34:18 2022
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
T add(T &a, T &b) {
    cout << "add function" << sizeof(T) << endl;
    static int i = 0;
    cout << i << endl;
    return a + b;
}

template<> 
int add(int &a, int &b) {
    cout << "int add function" << endl;
    return a + b;
}

template<typename T>
T add(T *a, T *b) {
    cout << "T * add function" << endl;
    return (*a) + (*b);
}
template<typename T>
class Array {
    
public :
    Array(int n) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if (ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];
    }
    template <typename U>
    friend ostream &operator<<(ostream &, const Array<U> &);

private :
    T *arr;
    T __end;
    int n;
};

template<>
class Array<double> {
    
public :
    Array(int n) : n(n) {
        cout << "double array template" << endl;
        this->arr = new double[n];
    }
    double &operator[](int ind) {
        if (ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];
    }
    template <typename U>
    friend ostream &operator<<(ostream &, const Array<U> &);

private :
    double *arr;
    double __end;
    int n;
};
template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    cout<< "Class Array : ";
    for (int i = 0; i < a.n; i++) {
        cout << a.arr[i] << " ";
    }
    return out;
}

int main() {
    int a = 1, b = 2;
    cout << add(a, b) << endl;

    cout << add(&a, &b) << endl;
    Array<int> c(10);
    for (int i = 0; i < 10; i++) {
        c[i] = rand() % 100;
    }
    cout << c << endl;
    Array<double> d(10);
    for (int i = 0; i < 10; i++) {
        d[i] = (rand() % 100) / 100.0;
    }
    cout << d << endl;
    return 0;
}

