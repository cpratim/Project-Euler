//
// Created by Pratim Chowdhary on 4/21/22.
//

#ifndef PROJECT_EULER_PROBLEM71_H
#define PROJECT_EULER_PROBLEM71_H

#include "cmath"
#include "../include/print_lib.h"

using namespace std;

void find_closest_fraction(int* frac, int d, double target) {
    double closest = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = frac[0]; j < i; j++) {
            double val = (double) j / i;
            if (val > target) break;
            if (target - val > 0 and target - val < closest) {
                frac[0] = j;
                frac[1] = i;
                closest = target - val;
            }
        }
    }
}

void problem_71_solution(bool log) {
    double target = 3.0 / 7;
    int d = 1000000;
    int fraction[2] = {0, 0};
    find_closest_fraction(fraction, d, target);
    if (log) cout << fraction[0] << endl;
}

#endif //PROJECT_EULER_PROBLEM71_H
