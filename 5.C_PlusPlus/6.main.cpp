/*************************************************************************
	> File Name: 6.main.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  3/ 9 15:42:04 2022
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <set>
#include "6.BSTree.h"

int main() {
    haizei::BSTree<int> root;
    std::set<int> root_s;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        root.insert(rand() % 101);
        //root_s.insert(rand() % 10);
    }
    //for (std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) {
    //    std::cout << *iter << std::endl;
    //}
    for (haizei::BSTree<int>::iterator iter = root.begin(); iter != root.end(); iter++) {
        std::cout << *iter << std::endl;
    }
    return 0;
}

