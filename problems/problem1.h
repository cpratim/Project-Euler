//
// Created by pratim on 4/19/22.
//

#ifndef PROJECT_EULER_PROBLEM1_H
#define PROJECT_EULER_PROBLEM1_H

#include <set>
#include "iterator"

using namespace std;

int find_multiples_sum(int n, const set<int>& divisors) {
    set<int>::iterator itr;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (itr = divisors.begin(); itr != divisors.end(); itr++) {
            if (i % *itr == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}

int problem_1_solution(bool log) {
    int n = 1000;
    set<int> divisors = {3, 5};
    int sum = find_multiples_sum(n, divisors);
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM1_H
