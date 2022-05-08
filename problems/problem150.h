//
// Created by Pratim and Karun on 5/7/22.
//

#ifndef PROJECT_EULER_PROBLEM150_H
#define PROJECT_EULER_PROBLEM150_H

#include "iostream"

using namespace std;

void problem_150_solution(bool log) {

    int rows = 1000;
    long S[rows][rows];
    long t = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col <= row; col++) {
            t = (615949 * t + 797807) % (1 << 20);
            long partial = t - (1 << 19);
            S[row][col] = partial;
            if (col > 0)
                S[row][col] += S[row][col-1];
        }
    }
    long min_sum = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col <= row; col++) {
            long sub_sum = 0;
            for (int down = 0; down < rows - row; down++) {
                sub_sum += S[row+down][col+down];
                if (col > 0)
                    sub_sum -= S[row+down][col-1];
                if (sub_sum < min_sum)
                    min_sum = sub_sum;
            }
        }
    }
    if (log) cout << min_sum << endl;
}

#endif //PROJECT_EULER_PROBLEM150_H
