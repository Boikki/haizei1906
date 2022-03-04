/*************************************************************************
	> File Name: 5.my_hash_table.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  3/ 4 14:36:09 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class Node {
public :
    Node() : _flag(false), _str(nullptr) {}
    void clear() {
        this->_flag = false;
        if (this->_str) free(this->_str);
        this->_str = nullptr;
        return ;
    }
    void insert(const char *str) {
        this->clear();
        this->_flag = true;
        this->_str = strdup(str);
        return ;
    }
    bool empty() { return this->_flag == false; }
    bool operator!=(const char *str) {
        if (this->_str == nullptr) return true;
        return (strcmp(this->_str, str) != 0);
    }
    bool operator==(const char *str) {
        return !((*this) != str);
    }
    ~Node() {
        if (this->_str) free(this->_str);
        this->_str = nullptr;
    }
private :
    bool _flag;
    char *_str;
};

class HashFunc {
public :
    virtual int operator()(const char *str) const = 0;
};

class HashTable {
public :
    HashTable(const HashFunc &func); //有参构造函数
    bool insert(const char *str);
    bool find(const char *str);
    ~HashTable();

private :
    Node &find_position(const char *str);
    int _size;
    Node *data;
    const HashFunc *p_func;
    //p_func不用析构，因为不是在Node创建的时候初始化的

};

class BKDRhash : public HashFunc {
    int operator()(const char *str) const {
        int seed = 31;
        int hash_value = 0;
        for (int i = 0; str[i]; i++) {
            hash_value = hash_value * seed + str[i];
        }
        return hash_value & 0x7fffffff;
    }
};

int main() {
    BKDRhash bkdr_func;
    HashTable h1(bkdr_func);
    int op;
    char str[100];
    while (cin >> op >> str) {
        switch (op) {
            case 0: {
                cout << "insert " << str << " to HashTable = " << h1.insert(str) << endl;
            } break;
            case 1: {
                cout << "search " << str << " from HashTable = " << h1.find(str) << endl;
                
            } break;
        }
    }

    return 0;
}

HashTable::HashTable(const HashFunc &func) : p_func(&func) {
    this->_size = 100;
    this->data  = new Node[this->_size];
}

bool HashTable::insert(const char *str) {
    Node &d = find_position(str);
    if (!d.empty()) return false;
    d.insert(str);
    return true;
}

bool HashTable::find(const char *str) {
    Node &d = find_position(str);
    return (!d.empty());
}

Node &HashTable::find_position(const char *str) {
    //返回的是Node节点的引用
    int ind = (*p_func)(str) % this->_size;
    int times = 1;
    while (!data[ind].empty() && data[ind] != str) {
        ind += times * times;
        ind %= this->_size;
        times++;
    }
    return data[ind];
}

HashTable::~HashTable() {
    delete[] this->data;
    
}
