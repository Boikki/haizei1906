/*************************************************************************
	> File Name: 9.visitor.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri Apr 15 09:20:38 2022
 ************************************************************************/

#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

class B;
class C;
class D;
class E;

class A {
public :
    class IVisitor {
    public : 
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

class B : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class C : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class D : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class E : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputIVistor : public A::IVisitor {
    virtual void visit(B *obj) {
        cout << "this is a class B obj" << endl;
    }
    virtual void visit(C *obj) {
        cout << "this is a class C obj" << endl;
    }
    virtual void visit(D *obj) {
        cout << "this is a class D obj" << endl;
    }
    virtual void visit(E *obj) {
        cout << "this is a class E obj" << endl;
    }
};

int main() {
    A *arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0 : arr[i] = new B(); break;
            case 1 : arr[i] = new C(); break;
            case 2 : arr[i] = new D(); break;
            case 3 : arr[i] = new E(); break;
        } 
    }
    OutputIVistor vis;

    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    return 0;
}
