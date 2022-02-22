/*************************************************************************
	> File Name: 2.class.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 二  2/22 10:08:09 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
    Point(); 
    Point(int x, int y); 
    Point(const Point &p);
    int x() const;
    int y() const;
    int z() const;
    ~Point();

    static int cnt();


private :
    int _x, _y;
    mutable int _z; 
    static int _cnt;
};


Point::Point() : _x(0), _y(0), _z(0) {
    cout << "default constructor" << endl;
    cout << this <<endl;
    _x++;
    this->_cnt += 1;
}
Point::Point(int x, int y) : Point(){
    this->_x = x, this->_y = y;
    cout << "constructor with parameters" << endl;
    cout << this <<endl;
}
Point::Point(const Point &p) : Point(){
    _x = p.x();
    _y = p.y();
    cout << "copy constructor" << endl;
    cout << this <<endl;
}

int Point::x() const { this->_z += 1; return this->_x; }
int Point::y() const { return this->_y; }
int Point::z() const { return this->_z; }
Point::~Point() {
    cout << "destructor" << endl;   
    cout << this <<endl;
    this->_cnt -= 1;
}

int Point::cnt() { return Point::_cnt; }
int Point::_cnt = 0;

int main() {
    Point(p1), p2(2, 3), p3(p2);
    cout << p1.x() << p1.y() << endl;
    cout << p2.x() << p2.y() << endl;
    cout << p3.x() << p3.y() << endl;
    cout << "p1_x_cnt = " << p1.z() << endl;
    cout << "p2_x_cnt = " << p2.z() << endl;
    cout << "p3_x_cnt = " << p3.z() << endl;
    cout << Point::cnt() << endl;
    return 0;
}
