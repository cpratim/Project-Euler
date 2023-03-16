//
// Created by Pratim Chowdhary on 03/14/23.
//

#ifndef PROJECT_EULER_PROBLEM213_H
#define PROJECT_EULER_PROBLEM213_H

#include <iostream>
#include <vector>

using namespace std;
template<typename T> using matrix = vector<vector<T>>;

void step(matrix<double> & chain, int N) {

    matrix<double> next = matrix<double>(N, vector<double>(N, 0));

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (chain[i][j] == 0) continue;
        int around = (int) (i > 0) + (int) (i < N - 1) + (int) (j > 0) + (int) (j < N - 1);
        if (i > 0)     next[i - 1][j] += chain[i][j] / around;
        if (i < N - 1) next[i + 1][j] += chain[i][j] / around;
        if (j > 0)     next[i][j - 1] += chain[i][j] / around;
        if (j < N - 1) next[i][j + 1] += chain[i][j] / around;
    }
    chain = next;
}

void problem_213_solution(bool log) {
    
    int N = 30;
    int S = 50;
    matrix<double> DP = matrix<double>(N, vector<double>(N, 1));
    
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        matrix<double> chain = matrix<double>(N, vector<double>(N, 0));
        chain[i][j] = 1;
        for (int k = 0; k < S; k++) step(chain, N);
        for (int k = 0; k < N; k++) for (int l = 0; l < N; l++) {
            DP[k][l] *= (1 - chain[k][l]);
        }
    }
    double result = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        result += DP[i][j];
    }
    if (log) cout << "Problem 213 Solution: " << result << endl;
    
}

#endif //PROJECT_EULER_PROBLEM213_H