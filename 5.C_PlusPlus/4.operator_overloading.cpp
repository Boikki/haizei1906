/*************************************************************************
	> File Name: 4.operator_overloading.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  3/ 2 08:57:05 2022
 ************************************************************************/

#include <iostream>
#include <cstdarg>
using namespace std;

struct Data {
    Data() : x(0), y(0) {}
    Data(int x, int y) : x(x), y(y) {}
    Data operator+(Data &a) {
        return Data(x + a.x, y + a.y);
    }
    Data operator+=(Data &a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    Data &operator++() {
        x++;
        y++;
        return *this;
    } 
    Data operator++(int z) {
        Data ret(*this);
        x++;
        y++;
        return ret;
    }
    int operator[](string axis) {
        if (axis == "x") return x;
        if (axis == "y") return y;
        else return -1;
    }
    Data operator()(int num, ...) {
        va_list ap;
        int d;
        int sum_x = 0, sum_y = 0;
        va_start(ap, num);
        for (int i = 0; i < num; i++) {
            d = va_arg(ap, int);
            if (i % 2) {
                sum_x += d;
            } else {
                sum_y += d;
            }
        }
        Data ret(this->x + sum_x, this->y + sum_y);
        va_end(ap);
        return ret;

    }
    
    Data *operator->() {
        return p;
    }

    Data operator*(Data &b) {
        Data ret(x * b.x, y * b.y);
        return ret;
    }
    Data operator*() {
        return *this;
    }
    int x, y;
    Data *p;
};



ostream &operator<<(ostream &out, const Data &a) {
    out << "class<Data> : " << a.x << " " << a.y;
    return out;
}

int main() {
    Data a(2, 4), b(5, 6);
    int num = {1};
    cout << a.operator+(b) << endl;
    cout << a + b << endl;
    cout << (a += b) << endl;
    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << a["x"] << endl;
    //函数对象 -- 表现的像个函数，但是实际上可能是函数对象，
    //宏定义或者函数
    a.p = &b;
    cout << a->x << endl;
    cout << a * b << endl;
    cout << *a.p << endl;
    //重载之后原有的运算符就不好用了！
    cout << a(3, 4, 5, 6) << endl;
    return 0;
}
