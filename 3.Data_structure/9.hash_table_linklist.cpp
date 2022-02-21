/*************************************************************************
	> File Name: 9.hash_table.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 五  2/18 07:42:08 2022
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public :
    Node(string data = "", Node *next = nullptr) : data(), next(nullptr) {}
    string data;
    Node *next;
    void insert(Node *node) {
        node->next = this->next;
        this->next = node;
        return ;
    }
private :
};

class HashTable {
public: 
    HashTable(int n = 100) :  data(n), cnt(0) {}
    void insert(string s) {
        int ind = BKBRHash(s) % data.size();
        recalc_ind(ind, s);
        Node *p = &data[ind];
        if (p->next && p->next->data != s) p = p->next;
        if (p->next == nullptr) {
            p->insert(new Node(s));
            cnt += 1;
            if (cnt > data.size() >> 1) {
                expand();
            }
        }
        return ;
    }
    bool find(string s) {
        int ind = BKBRHash(s) % data.size();
        recalc_ind(ind, s);
        Node *p = data[ind].next;
        while (p && p->data != s) p = p->next;
        return p != nullptr;
    }

private:
    int cnt;
    vector<Node> data;

    void expand() {
        int n = data.size() >> 1;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            Node *p = data[i].next;
            while (p) {
                h.insert(p->data);
                p = p->next;
            }
        }
        *this = h;
        return ;
    }

    int BKBRHash(string &s) {
        int seed = 31, hash = 0;
        for (int i = 0; s[i]; i++) hash = hash * seed + s[i];
        return hash & 0x7fffffff;
    }

    void recalc_ind(int &ind, string &s) {
        return ;
    }
};

int main() {
    int op;
    string s;
    HashTable h;
    while (cin >> op >> s) {
        switch (op) {
            case 1: h.insert(s); break;
            case 2: cout << "find : " << s <<  " = " << h.find(s) << endl; break;
        }
    }
    return 0;
}
