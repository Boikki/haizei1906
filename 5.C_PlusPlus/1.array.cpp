/*************************************************************************
	> File Name: 1.array.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/20 14:49:39 2022
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Array {
public :
    Array() {
        this->__size = 10;
        this->__cnt = 0;
        this->data = new T[this->__size];
    }
    Array(int n) {
        this->__size = n << 1;
        this->__cnt = n;
        this->data = new T[this->__size];
    }
    void push_back(const T &a) {
        this->data[(this->__cnt)++] = a;
    }
    int size() { return this->__cnt;  }
    T &operator[](int ind) {
        return this->data[ind];
    }

private :
    T *data;
    int __size, __cnt;
};

int main() {
    vector<int> arr1;
    cout << arr1.size() << endl;
    arr1.push_back(123);
    cout << arr1.size() << endl;
    Array<int> arr2(10);
    cout << arr2.size() << endl;
    arr2.push_back(123);
    cout << arr2.size() << endl;
    cout << arr2[0] << endl;
    return 0;
}
