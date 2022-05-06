//
// Created by Allison Zhuang on 5/6/22.
//

#ifndef PROJECT_EULER_PROBLEM73_H
#define PROJECT_EULER_PROBLEM73_H

#include "iostream"
#include "unordered_set"
#include "cmath"

using namespace std;

long find_num_fractions(int d_max, int d_floor, int d_ceil) {
    unordered_set<double> fraction_set;
    long total = 0;
    for (int d = 1; d <= d_max; d++) {
        double f_d = (double) d;
        for (int n = floor(f_d / d_floor); n < floor(f_d / d_ceil); n++) {
            double frac = (double) n / f_d;
            if (not fraction_set.contains(frac)) {
                fraction_set.insert(frac);
                total += 1;
            }
        }
    }
    return total - 1;
}

void problem_73_solution(bool log) {
    int d_max = 12000;
    int d_floor = 3;
    int d_ceil = 2;
    long total = find_num_fractions(d_max, d_floor, d_ceil);
    if (log) cout << total << endl;
}

#endif //PROJECT_EULER_PROBLEM73_H
