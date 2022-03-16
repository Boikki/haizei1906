/*************************************************************************
	> File Name: 8.c++11_dynamic_cast.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Tue Mar 15 09:38:03 2022
 ************************************************************************/

#include <iostream>
using namespace std;

struct B;
struct C;
struct D;
struct E;
struct F;

int ans = 1;
struct A {
    struct IVisitor {
        //抽象类
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

struct B : A {
    B() { x = 123; }
    void Accept(IVisitor *visitor) {
        visitor->visit(this);
    }
    int x;
};

struct C : A {
    C() { x = 123.45; }
    void Accept(IVisitor *visitor) {
        visitor->visit(this);
    }
    double x;
};

struct D : A {
    D() { x = "hello world."; }
    void Accept(IVisitor *visitor) {
        visitor->visit(this);
    }
    string x;
};

struct E : A {
    E() { x = new int; }
    void Accept(IVisitor *visitor) {
        visitor->visit(this);
    }
    int *x;
};
struct F : A {
    F() { x = new int; }
    void Accept(IVisitor *visitor) {
        visitor->visit(this);
    }
    int *x;
};

struct OutputVisitor : A::IVisitor {
    virtual void visit(B *obj) {
        cout << "class B " << endl;
    }
    virtual void visit(C *obj) {
        cout << "class C " << endl;
    }
    virtual void visit(D *obj) {
        cout << "class D " << endl;
    }
    virtual void visit(E *obj) {
        cout << "class E " << endl;
    }
    virtual void visit(F *obj) {
        cout << "class F " << endl;
    }
};

struct AddVisitor : A::IVisitor {
    AddVisitor(int ans) : ans(ans) {}
    virtual void visit(B *obj) {
        ans += 2;
    }
    virtual void visit(C *obj) {
        ans *= 3;
    }
    virtual void visit(D *obj) {
        ans -= 5;
    }
    virtual void visit(E *obj) {
        ans += 6;
    }
    virtual void visit(F *obj) {
        ans *= 2;
    }
    int ans;
};
ostream &operator<<(ostream &out, const AddVisitor &vis) {
    out << vis.ans;
    return out;
}
int main() {
    srand(time(0));
    A *pa_arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 5) {
            case 0 : pa_arr[i] = new B(); break;
            case 1 : pa_arr[i] = new C(); break;
            case 2 : pa_arr[i] = new D(); break;
            case 3 : pa_arr[i] = new E(); break;
            case 4 : pa_arr[i] = new F(); break;
        }
    }
    AddVisitor visi(1);
    for (int i = 0; i < 10; i++) {
        OutputVisitor vis;
        pa_arr[i]->Accept(&vis);
        pa_arr[i]->Accept(&visi);
    }
    cout << visi.ans << endl;
    return 0;
}
