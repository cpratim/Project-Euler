//
// Created by Annie Tang on 3/17/2023.
//

#ifndef PROJECT_EULER_PROBLEM116_H
#define PROJECT_EULER_PROBLEM116_H

#include <iostream>

using namespace std;

long dp(int x, int b_len) {
    long dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        dp[i] = dp[i - 1];
        if (i >= b_len) dp[i] += dp[i - b_len];
    }
    return dp[x];
}

void problem_116_solution(bool log) {
    int N = 50;
    long r = dp(N, 2) - 1;
    long g = dp(N, 3) - 1;
    long b = dp(N, 4) - 1;
    long ans = r + g + b;
    if (log) cout << ans << endl;
}

#endif //PROJECT_EULER_PROBLEM116_H
