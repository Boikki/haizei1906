/*************************************************************************
	> File Name: 7.c++11_auto.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Mar 12 17:51:39 2022
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <map>
#include <string>
using namespace std;

string randString(int x) {
    string ret = "";
    for (int i = 0; i < x; i++) {
        char ch = rand() % 26 + 'A';
        ret += ch;
    }
    return ret;
}

static int my_seed = 15;
void my_srand(int seed) {
    my_seed = seed;
}

int my_rand() {
    my_seed = my_seed * 3 % 101;
    return my_seed;
}

int main() {
    map<string, int> ind;
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        cout << my_rand() << endl;
    }
    my_srand(16);
    for (int i = 0; i < 100; i++) {
        cout << endl;
        cout << my_rand() << endl;
    }

    for (int i = 0; i < 10; i++) {
        ind[randString(rand() % 10 + 3)] = rand();
    }
//    map<string, int>::iterator iter;
    auto iter = ind.begin();
    for (iter = ind.begin(); iter != ind.end(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }
    for (auto x : ind) {
        cout << x.first << x.second << endl;
    }
    return 0;
}
