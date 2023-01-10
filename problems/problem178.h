//
// Created by Pratim on 01/10/23
//

#ifndef PROJECT_EULER_PROBLEM178_H
#define PROJECT_EULER_PROBLEM178_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<vector<vector<long>>> matrix_3D;

long recursion_fairy(int i, int last, int mask, int M, matrix_3D & DP) {
    if (i == M - 1) return (int) mask == (1 << 10) - 1;
    if (DP[i][last][mask] != - 1) return DP[i][last][mask];

    long total = 0;
    if (last < 9) total += recursion_fairy(i+1, last + 1, mask | (1 << (last+1)), M, DP);
    if (last > 0) total += recursion_fairy(i+1, last - 1, mask | (1 << (last-1)), M, DP);
    DP[i][last][mask] = total;
    return total;
}

void problem_178_solution(bool log) {
    long solution = 0;
    int M = 40;
    matrix_3D DP(M, vector<vector<long>>(10, vector<long>((1 << 10), -1)));
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < M; j++) {
            solution += recursion_fairy(j, i, (1 << i), M, DP);
        }
    }
    if (log) cout << solution << endl;
}

#endif //PROJECT_EULER_PROBLEM178_H