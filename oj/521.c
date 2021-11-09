/*************************************************************************
	> File Name: 521.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Sep 28 09:13:45 2021
 ************************************************************************/
 /**
  * 题目描述：
  * 给出 𝑛 个正整数 𝑥1,𝑥2......𝑥𝑛，在这 𝑛 个数中任取 𝑟 个，计算 𝑟 个数的和为质数的个数。
输入:
第一行两个整数 𝑛,𝑟。（1≤𝑟≤𝑛≤30）
第二行 𝑛 个整数，表示 𝑥𝑖。（1≤𝑥𝑖≤105）

输出
输出一个数，表示答案。
*/

#include <stdio.h>
#define MAX_N 3000000
int prime[MAX_N + 5] = {1, 1};
int n, r, ans, num[35]; 

void init_prime() {
    for (int i = 2; i * i <= MAX_N + 5; i++) {
        if (prime[i] == 0) {
            for (int j = 2; i * j <= MAX_N + 5; j++) {
                prime[i * j] = 1;
            }
        }
    }
    return ;
}

void func(int s, int sum, int deep) {
    if (deep == r) {
        if (prime[sum] == 0) ans++;
        return ;
    }
    for (int i = s; i <= n - r + deep; i++) {
        sum += num[i];
        func(i + 1, sum, deep + 1);
        sum -= num[i];
    }
}

int main() {
    init_prime();
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    func(0, 0, 0);
    printf("%d\n", ans);

    return 0;
}
