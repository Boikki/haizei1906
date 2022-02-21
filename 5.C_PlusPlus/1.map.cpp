/*************************************************************************
	> File Name: 1.map.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/20 21:40:03 2022
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<int, int> arr;
    arr[-100] = 36;
    arr[-90] = 50;
    arr[105] = 37;
    arr[78] = 65;
    unordered_map<int, int> m;
    m[-100] = 36;
    m[-90] = 50;
    m[105] = 37;
    m[78] = 65;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << endl;
    }
    cout << endl;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << endl;
    }
    //map是有序的，unordered_map无序的，又叫哈希表
    //set就看成小顶堆
    return 0;
}


