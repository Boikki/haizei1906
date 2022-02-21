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

class HashTable {
public: 
    HashTable(int n = 100) :  data(n), flag(n), cnt(0) {}
    void insert(string s) {
        int ind = BKBRHash(s) % data.size();
        recalc_ind(ind, s);
        data[ind] = s;
        flag[ind] = true;
        cnt += 1;
        if (cnt > data.size() * 0.75) expand();
        return ;
    }
    bool find(string s) {
        int ind = BKBRHash(s) % data.size();
        recalc_ind(ind, s);
        return flag[ind];
    }

private:
    int cnt;
    vector<string> data;
    vector<bool> flag; // 01标记位置是否存储data

    void expand() {
        int n = data.size() >> 1;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (flag[i] == false) continue;
            h.insert(data[i]);
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
        //开放定址法
        int times = 0;
        while (flag[ind] && data[ind] != s) {
            times++;
            ind += times * times;
            ind %= data.size();
        }
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
