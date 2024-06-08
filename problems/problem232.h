//
// Created by Pratim Chowdhary and Connor Zhang on 06/07/24.
//

#ifndef PROJECT_EULER_PROBLEM232_H
#define PROJECT_EULER_PROBLEM232_H

#include <iostream>
#include <vector>


using namespace std;
using matrix_3D_D = vector<vector<vector<double>>>;


double F(int i, int j, int k, int R, matrix_3D_D & dp) {

    if (i >= R) 
        return 0.0;
    if (j >= R)
        return 1.0;

    if (dp[i][j][k] != -1) 
        return dp[i][j][k];

    if (k == 0) 
        return dp[i][j][k] = .5 * F(i + 1, j, 1, R, dp) + .5 * F(i, j, 1, R, dp);

    double max_win = 0;
    for (int t = 1; t <= ceil(log2(R - j)) + 1; t++) {
        max_win = max(
            max_win,
            (pow(.5, t) * F(i, j + pow(2, t - 1), 0, R, dp) + .5 * (1 - pow(.5, t)) * F(i + 1, j, 1, R, dp)) / (.5 + pow(.5, t + 1))
        );
    }
    dp[i][j][k] = max_win;
    return max_win;
}


void problem_232_solution(bool log) {

    int R = 100;
    matrix_3D_D dp = matrix_3D_D(R, vector<vector<double>>(R, vector<double>(2, -1)));
    double result = F(0, 0, 0, R, dp);
    if (log) 
        cout << result << endl;
}


#endif //PROJECT_EULER_PROBLEM232_H