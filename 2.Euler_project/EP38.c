/*************************************************************************
	> File Name: EP38.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 10:22:00 2021
 ************************************************************************/

 // 鸽巢原理 确定上界

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define MAX_N 10000

int get_digits(int64_t num) {
    return floor(log10(num)) + 1;

}

int64_t pandigital_multiples(int x) {
    int64_t ans = 0;
    int n = 1;
    while (get_digits(ans) < 9) {
        ans *= pow(10, get_digits(n * x));
        ans += n * x;
        n += 1;
    }
    if (get_digits(ans) != 9) return -1;
    int num[10] = {0};
    num[0] = 1;
    int64_t temp = ans;
    while (temp) {
        if (num[temp % 10]) return -1;
        num[temp % 10] += 1;
        temp /= 10;
    }
    return ans;
}

int main() {
    int64_t temp, ans;
    for (int i = 1; i < MAX_N; i++) {
        temp = pandigital_multiples(i);
        if (temp > ans) ans = temp;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}

