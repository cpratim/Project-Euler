//
// Created by pratim on 4/20/22.
//

#ifndef PROJECT_EULER_PROBLEM2_H
#define PROJECT_EULER_PROBLEM2_H

#include "iostream"

using namespace std;

int fibonacci_generator(bool reset) {
    static int f1 = 1;
    static int f2 = 2;
    int temp = f1 + f2;
    f1 = f2;
    f2 = temp;
    if (reset) {
        f1 = 1;
        f2 = 2;
    }
    return temp;
}

void problem_2_solution(bool log) {
    long max = 4000000;
    int sum = 0;
    for (int term = 2; term < max; term = fibonacci_generator(false)) {
        if (term % 2 == 0) {
            sum += term;
        }
    }
    fibonacci_generator(true);
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM2_H
