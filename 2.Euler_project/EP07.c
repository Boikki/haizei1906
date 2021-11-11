/*************************************************************************
	> File Name: EP07.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 21 14:05:21 2021
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10001
int prime[MAX_N + 5];

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = 2 * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }

}
