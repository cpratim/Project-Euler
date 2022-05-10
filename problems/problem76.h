//
// Created by Sonia and Pahal on 5/9/22.
//

#ifndef PROJECT_EULER_PROBLEM76_H
#define PROJECT_EULER_PROBLEM76_H

#include "iostream"

using namespace std;

void problem_76_solution(bool log) {
    int N = 100;
    long combs[N];
    combs[0] = 1;
    for (int k = 1; k <= N; k++) {
        combs[k] = 0;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i <= j)
                combs[j] += combs[j-i];
        }
    }
    if (log) cout << combs[N] << endl;
}

#endif //PROJECT_EULER_PROBLEM76_H
