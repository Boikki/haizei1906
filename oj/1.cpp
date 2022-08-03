/*************************************************************************
	> File Name: 1.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 六  7/30 12:13:36 2022
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void random(vector<int> &arr) {
    srand(time(0));
    int index, tmp;
    for (int i = 0; i < arr.size(); i++) {
        index = rand() % (arr.size() - i) + i;
        if (index != i) {
            tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
        }
    }
    return ;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    random(arr);
    for (auto x : arr) {
        cout << x << endl;
    }
}


