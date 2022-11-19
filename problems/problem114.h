//
// Created by Pratim Chowdhary on 11/19/22.
//

#ifndef PROJECT_EULER_PROBLEM114_H
#define PROJECT_EULER_PROBLEM114_H

#include <iostream>
#include <cmath>

using namespace std;

long solve(int i, int n, long *cache) {
    if (cache[i] != 0)
        return cache[i];
    if (n - i < 3)
        return 1;
    long total = solve(i + 1, n, cache);
    for (int j = i + 4; j <= n; j++) {
        total += solve(j, n, cache);
    }
    cache[i] = total + 1;
    return cache[i];
}

void problem_114_solution(bool log) {
    int n = 50;
    long cache[n+1];
    for (int i = 0; i <= n; i++) {
        cache[i] = 0;
    }
    long total = solve(0, n, cache);
    if (log) cout << total << endl;
}

#endif //PROJECT_EULER_PROBLEM114_H
