/*************************************************************************
	> File Name: 4.calculate.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Dec  1 16:27:38 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 100

int calc(char *s, int l, int r) {
    int pos = -1, pri = 10000 - 1, cur_pri, temp = 0;
    for (int i = l; i < r + 1; i++) {
        cur_pri = 10000;
        switch (s[i]) {
            case '+': 
            case '-': cur_pri = temp + 1; break;
            case '*': 
            case '/': cur_pri = temp + 2; break;
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
        }
        if (cur_pri < pri) pri = cur_pri, pos = i;
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i < r + 1; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    int a = calc(s, l, pos - 1);
    int b = calc(s, pos + 1, r);
    switch (s[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
int main() {
    char s[100];
    while (~scanf("%[^\n]s", s)) {
        getchar();
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
}
