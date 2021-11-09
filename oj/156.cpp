/*************************************************************************
	> File Name: 156.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 14 17:06:44 2021
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int is_square(int x) {
    for (int i = 0; i < 10; i++) {
        if (i * i == x / 100){
            return 1;
            
        } 
    }
    return 0;
}

int is_square1(int x) {
    for (int i = 0; i < 10; i++) {
        if (i * i == x % 100) {
            return 1;
            
        } 
    }
    return 0;
}

int main() {
    int a, b, cnt = 0, flag = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        is_prime(i) && is_square(i) && is_square1(i) && flag && printf(" ");
        is_prime(i) && is_square(i) && is_square1(i) && printf("%d",i);
        if (is_prime(i) && is_square(i) && is_square1(i)) {
            flag = 1, cnt++;
        }
    }
    printf("\n%d", cnt);
    return 0;
}
