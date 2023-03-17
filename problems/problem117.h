//
// Created by Pratim Chowdhary on 03/14/23.
//

#ifndef PROJECT_EULER_PROBLEM117_H
#define PROJECT_EULER_PROBLEM117_H

#include <iostream>

using namespace std;

void problem_117_solution(bool log) {
    int N = 50;
    long long dp[N + 1];
    dp[N] = 1;
    for (int i = N-1; i >= 0; i--) {
        dp[i] = dp[i+1];
        if (i + 2 <= N) dp[i] += dp[i+2];
        if (i + 3 <= N) dp[i] += dp[i+3];
        if (i + 4 <= N) dp[i] += dp[i+4];
    }
    if (log) cout << dp[0] << endl;
}

#endif //PROJECT_EULER_PROBLEM117_H