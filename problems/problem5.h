//
// Created by Karun Ram, Pratim Chowdhary on 4/27/22.
//

#ifndef PROJECT_EULER_PROBLEM5_H
#define PROJECT_EULER_PROBLEM5_H

#include "iostream"

using namespace std;

long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}


long find_smallest_multiple(int n) {
    long fact = factorial(n);
    int count = n;
    while (count > 2) {
        if (fact % count == 0) {
            bool div = true;
            long temp = fact / count;
            for (int i = n; i > 1; i--) {
                if (temp % i != 0) {
                    div = false;
                    break;
                }
            }
            if (div) {
                fact = temp;
            } else {
                count--;
            }
        }
    }
    return fact;
}

void problem_5_solution(bool log) {
    int n = 20;
    long r = find_smallest_multiple(n);
    if (log) cout << r << endl;
}

#endif //PROJECT_EULER_PROBLEM5_H
