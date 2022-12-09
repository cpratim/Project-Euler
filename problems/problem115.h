//
// Created by Pratim Chowdhary on 12/09/22.
//

#ifndef PROJECT_EULER_PROBLEM115_H
#define PROJECT_EULER_PROBLEM115_H

#include <iostream>
#include <cmath>

using namespace std;

long solve(int i, int n, long cache[][1000]) {
    if (cache[i][n] != 0)
        return cache[i][n];
    if (n - i < 50)
        return 1;
    long total = solve(i + 1, n, cache);
    for (int j = i + 50 + 1; j <= n; j++) {
        total += solve(j, n, cache);
    }
    cache[i][n] = total + 1;
    return cache[i][n];
}

void problem_115_solution(bool log) {
    long cache[1000][1000] = {0};
    int n = 50;
    long total = solve(0, n, cache);
    while (total < 1000000) {
        n++;
        total = solve(0, n, cache);
    }
    if (log) cout << n << endl;
}

#endif //PROJECT_EULER_PROBLEM115_H
