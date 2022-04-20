//
// Created by Karun Ram on 4/20/22.
//

#ifndef PROJECT_EULER_PROBLEM3_H
#define PROJECT_EULER_PROBLEM3_H

#include <iostream>

long largest_prime_factor(long n) {
    int i = 2;
    long lpf = 1;
    long n_orig = n;
    while (i <= n_orig && n > 1) {
        if (n % i == 0) {
            n /= i;
            lpf = i;
        } else {
            i++;
        }
    }
    return lpf;
}

void problem_3_solution(bool log) {
    long n = 600851475143;
    long a = largest_prime_factor(n);
    if (log) std::cout << a << std::endl;
}
#endif //PROJECT_EULER_PROBLEM3_H
