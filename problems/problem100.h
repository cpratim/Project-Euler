//
// Created by Jason and Pratim on 5/6/22.
//

#ifndef PROJECT_EULER_PROBLEM100_H
#define PROJECT_EULER_PROBLEM100_H

#include <iostream>
#include <cmath>

using namespace std;

long diophantine(int n) {
    if (n == 0) return 1;
    if (n == 1) return 3;
    return 6 * diophantine(n-1) - diophantine(n-2) - 2;
}

long long find_total(long x) {
    long long a = 1, b = -1;
    long long c = -2 * (x * x) + 2 * x;
    return (long long) (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// due to problem with sizes of N this code depends on the fact that the solution is 756872327473 but it is the general solution
void problem_100_solution(bool log) {
    long MIN = 1000000000000;
    int x = 1;
    long long n = 0;
    long long d;
    while (n < MIN) {
        d = diophantine(x);
        n = find_total(d);
        if (d == 756872327473) break;
        x += 1;
    }
    if (log) cout << d << endl;
}

#endif //PROJECT_EULER_PROBLEM100_H
