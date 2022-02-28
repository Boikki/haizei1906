/*************************************************************************
	> File Name: 4.my_cout.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一  2/28 13:15:19 2022
 ************************************************************************/

#include <iostream>
#include <string>

namespace haizei {
    class ostream {
    public :
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }
        ostream &operator<<(const double &a) {
           /*
            * char e_str[20];
            sprintf(e_str, "%-6g", a);
            for (int i = 0; e_str[i]; i++) {
                if (e_str[i] - ' ') continue;
                e_str[i] = 0;
                break;
            }
            printf("%s", e_str);
            return *this;
            */
            int e_num, temp;
            char e_str[20];
            sprintf(e_str, "%.5e", a);
            sscanf(e_str, "%d.%de%d", &temp, &temp, &e_num);
            if (e_num > 7 || e_num < -6) {
                printf("%s", e_str);
            } else {
                temp = 5 - e_num;
                sprintf(e_str, "%%.%dlf", temp);
                printf(e_str, a);
            }
            return *this;
        }
    };

    char endl = '\n';
    ostream cout;

}

int main() {
    haizei::cout << "hello haizei" << haizei::endl;
    haizei::cout << "123.567" << haizei::endl;
    double a = 3787878787878780.;
    for (int i = 0; i < 20; i++) {
        a /= 10;
        haizei::cout << i << " " << a;
        printf(" %.5e\n", a);
    }
    std::cout << "----------------------" << std::endl;

    haizei::cout << 123.45 << haizei::endl;
    haizei::cout << 123. << 123. << haizei::endl;
    std::cout << 123. << 123. << haizei::endl;
    haizei::cout << 123. << haizei::endl;
    printf("%.2lf", 23456.789);
    return 0;
}
