//
// Created by Pratim on 12/9/22.
//

#ifndef PROJECT_EULER_PROBLEM173_H
#define PROJECT_EULER_PROBLEM173_H

#include "iostream"
#include "cmath"

using namespace std;

int rings(int n, int t) {
    double a = 4;
    double b = 4 * n;
    double c = -t;
    return floor((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
}

void problem_173_solution(bool log) {
    int t = 1000000;
    int count = 0;
    int n = 1;
    int r = rings(n, t);
    while (r > 0) {
        count += r;
        n++;
        r = rings(n, t);
    }
    if (log) cout << count << endl;
}

#endif //PROJECT_EULER_PROBLEM173_H