/*************************************************************************
	> File Name: LCS.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 12/23 11:47:59 2021
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<int> dp[n + 1][m + 1];
    vector<int> b[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] == dp[i - 1][j] ? b[i][j] = {-1, 0} : b[i][j] = {0, -1};
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1]));

        }
    }
    cout << dp[n][m] << endl;
}
