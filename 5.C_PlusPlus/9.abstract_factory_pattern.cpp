/*************************************************************************
	> File Name: 9.abstract_factory_pattern.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Tue Apr 19 20:59:32 2022
 ************************************************************************/

#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

class ICar {
public :
    class IFactory {
    public :
        virtual ICar *create() = 0;
    };
    virtual void run() = 0;
protected :
    ICar() {}
    ~ICar() {}
};


class BenzCar : public ICar {
    BenzCar() {}
public :
    class Factory : public ICar::IFactory {
    public : 
        virtual ICar *create() {
            return new BenzCar();
        }
    };
    virtual void run() {
        cout << "Benz run" << endl;
    }
};
class BMWCar : public ICar {
public :
    class Factory : public ICar::IFactory {
    public : 
        virtual ICar *create() {
            return new BMWCar();
        }
    };
    BMWCar() {}
    virtual void run() {
        cout << "BMW run" << endl;
    }
};
class AudiCar : public ICar {
public :
    class Factory : public ICar::IFactory {
    public : 
        virtual ICar *create() {
            return new AudiCar();
        }
    };
    AudiCar() {}
    virtual void run() {
        cout << "Audi run" << endl;
    }
};

class Car {
public :
    int wheel_cnt, color, brand;
};

ICar::IFactory *fac[3] = {new BenzCar::Factory(), new AudiCar::Factory(), new BMWCar::Factory()};
//其实就是创建类的方法跟着类走，跟着另外一个类走，这个类还是在自己下边的
//如果没有抽象工厂，随机创建类的过程就是要switch case

int main() {
    ICar *cars[10];
    srand(time(0));
    new Car();
    new BenzCar::Factory();
    new BMWCar::Factory();
    for (int i = 0; i < 10; i++) {
        cars[i] = fac[rand() % 3]->create();
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
