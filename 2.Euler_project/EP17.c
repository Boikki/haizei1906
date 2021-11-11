/*************************************************************************
	> File Name: EP17.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/11 10:33:14 2021
 ************************************************************************/

#include <stdio.h>

int arr[20] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 
    6, 6, 8, 8, 7, 7, 9, 8, 8
    };
int arr2[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6
};

int get_letter_nums(int x) {
    if (x < 20) return arr[x];
    else if (x < 100) return arr2[x / 10] + arr[x % 10];
    else if (!(x % 100) && x < 1000) return arr[x / 100] +  7;
    else if (x < 1000) return arr[x / 100] + 10 + get_letter_nums(x % 100);
    else return 11;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += get_letter_nums(i);
    }
    printf("%d\n", ans);
    return 0;
}
