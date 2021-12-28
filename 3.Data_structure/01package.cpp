/*************************************************************************
	> File Name: 01package.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 12/23 14:49:27 2021
 ************************************************************************/

#include <iostream>
using namespace std;

// dp[i][j] 第i物品在背包容量j的max
// dp[4][15] 4 - 15kg
// dp[i][j] = max{dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]}
//
int dp[M][N] = {0};

int main() {
    for (int i = 0; i <= N; i++) {
        for (int j = w[i]; j <= V; j++) {
            dp[i][j] = max(dp[i - 1][j], dp)
        }
    }
    return 0;
}
