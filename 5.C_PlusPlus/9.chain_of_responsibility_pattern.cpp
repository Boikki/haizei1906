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
    class IHandler {
    public :
        IHandler() : next(nullptr) {}
        virtual bool is_valid(int x) = 0;
        virtual ICar *do_it() = 0;
        IHandler *next;
    };
    virtual void run() = 0;
protected :
    ICar() {}
    ~ICar() {}
};


class BenzCar : public ICar {
    BenzCar() {}
public :
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public : 
        virtual ICar *create() {
            return new BenzCar();
        }
        virtual bool is_valid(int x) {
            if (x == 0) return true;
            return false;
        }
        virtual ICar *do_it() {
            return this->create();
        }
    };
    virtual void run() {
        cout << "Benz run" << endl;
    }
};
class BMWCar : public ICar {
public :
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public : 
        virtual ICar *create() {
            return new BMWCar();
        }
        virtual bool is_valid(int x) {
            if (x == 1) return true;
            return false;
        }
        virtual ICar *do_it() {
            return this->create();
        }
    };
    BMWCar() {}
    virtual void run() {
        cout << "BMW run" << endl;
    }
};
class AudiCar : public ICar {
public :
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public : 
        virtual ICar *create() {
            return new AudiCar();
        }
        virtual bool is_valid(int x) {
            if (x == 2) return true;
            return false;
        }
        virtual ICar *do_it() {
            return this->create();
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

class ChainMaster {
public :
    static ICar::IHandler *get_instance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private :
    static void buildChain() {
        head = new BenzCar::Factory();
        head->next = new BMWCar::Factory();
        head->next->next = new AudiCar::Factory();
        return ;
    }
    static ICar::IHandler *head;
};

ICar::IHandler *ChainMaster::head = nullptr;

int main() {
    ICar *cars[10];
    srand(time(0));
    new Car();
    new BenzCar::Factory();
    new BMWCar::Factory();
    for (int i = 0; i < 10; i++) {
        int req = rand() % 3;
        for (auto p = ChainMaster::get_instance(); p; p = p->next) {
            if (p->is_valid(req)) cars[i] = p->do_it();
        }
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
