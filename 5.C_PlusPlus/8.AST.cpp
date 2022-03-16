/*************************************************************************
	> File Name: 8.AST.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Mar 16 09:33:43 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class AST {
public :
    AST(std::string expr) {}

private :
    std::string expr;

};

int main() {
    std::string str;
    cin >> str;
    AST tree(str);
    tree.output();
    return 0;
}
