/*************************************************************************
	> File Name: 10.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Nov 30 11:25:17 2021
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};


inline bool matchOnChar(const char& ch1, const char& ch2) {
        return ch1 == ch2 || ch2 == '.';
    }

    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        int M = s.size();
        int N = p.size();
        const int MAX_STR_LEN = 27; // Minimum value to pass leetcode test
        bool T[MAX_STR_LEN][MAX_STR_LEN] = {false};
        T[0][0] = true;
        for (int j = 2; j <= N; j++) {
            if (p[j - 1] == '*') {
                T[0][j] = T[0][j - 2];
            }
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (matchOnChar(s[i - 1], p[j - 1])) { // matched
                    T[i][j] = T[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    T[i][j] = T[i][j - 2]; // ignore c*
                    if (j >= 2 && (matchOnChar(s[i - 1], p[j - 2]))) {
                        T[i][j] = T[i][j] || T[i - 1][j]; // match s[i - 1] once
                    }
                }
            }
        }

        return T[M][N];

        
inline bool match_one(char &s, char &p) {
        return (s == p || p == '.');
    }
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector<vector<bool>> f(s.size() + 1, vector<bool>(p.size() + 1, false));
        f[0][0] = true;
        for (int i = 2; i <= p.size(); i++) {
            if (p[i - 1] == '*') f[0][i] = f[0][i - 2];
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (match_one(s[i - 1], p[i - 1])) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 2];
                    if ((j >= 2) && match_one(s[i - 1], p[j - 2])) {
                        f[i][j] = f[i][j] || f[i - 1][j];
                    }
                }
            }
        }
        return f[s.size()][p.size()];
    }


    if (p.empty()) return s.empty();
        bool m0 = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.size() > 1 && p[1] == '*') { 
            return isMatch(s, p.substr(2)) || (m0 && isMatch(s.substr(1), p)); 
        } else {
            return m0 && isMatch(s.substr(1), p.substr(1));
        }

