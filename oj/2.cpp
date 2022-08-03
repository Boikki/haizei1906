/*************************************************************************
	> File Name: 2.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 六  7/30 12:30:12 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int is_2_power(int x) {
    if (x < 1) return 0;
    return (!(x & (x - 1)));
}
// 对于32位整形正数来说，二进制数都有一个特点即最高位为1，其余位为0
// 由于2^n不会是负数，所以负数不予考虑
// 所以x - 1 会是一个最高位位0其余位均为1的数
// 利用这一性质可以让x & (x - 1)，如果是2^n表达式结果为0
int main() {
    int x;
    cin >> x;
    cout << is_2_power(x) << endl;
    return 0;
}
