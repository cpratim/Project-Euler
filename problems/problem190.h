//
// Created on 5/5/22.
//

#ifndef PROJECT_EULER_PROBLEM190_H
#define PROJECT_EULER_PROBLEM190_H

#include <iostream>
#include <cmath>


void problem_190_solution(bool log) {
    int n_max = 15;
    long sum = 0;
    for (int n = 2; n <= n_max; n++) {
        long double prod = 1;
        for (int i = 1; i <= n; i++) {
            double num = 2*i;
            double den = (n+1);
            double k = num/den;
            prod *= pow(k,i);
        }
        sum += int(prod);
    }
    if (log) std::cout << sum << std::endl;
}
#endif //PROJECT_EULER_PROBLEM190_H
