//
// Created on 5/4/22.
//

#ifndef PROJECT_EULER_PROBLEM94_H
#define PROJECT_EULER_PROBLEM94_H

#include <iostream>
#include <cmath>
using namespace std;

long a(int n) {
    // solution to recursive relation a(n) = 3a(n-1) + 3a(n-2) - a(n-3)
    double x =  ceil((pow(-1, n) + pow((2+sqrt(3)),n))/3);
    return (int)x;
}

void problem_94_solution(bool log) {
    long n = 1000000000;
    long sum = 0;
    int b = 1;
    int i = 2;
    while (a(i) <= n / 3 + 1) {
        sum += 3*a(i)+b;
        b *= -1;
        i += 1;
    }
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM94_H
