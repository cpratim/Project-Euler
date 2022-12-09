//
// Created by Pratim Chowdhary on 12/09/22.
//

#ifndef PROJECT_EULER_PROBLEM191_H
#define PROJECT_EULER_PROBLEM191_H

#include <iostream>

using namespace std;

long prize_number(int i, int l, int a, int n, long cache[][10][10]) {
    if (cache[i][l][a] != 0) return cache[i][l][a];
    if (i == n) 
        return 1;
    long sum = prize_number(i+1, l, 0, n, cache);
    if (l < 1)
        sum += prize_number(i+1, l+1, 0, n, cache);
    if (a < 2)
        sum += prize_number(i+1, l, a+1, n, cache);
    cache[i][l][a] = sum;
    return sum;
}

void problem_191_solution(bool log) {
    long cache[50][10][10] = {0};
    long sum = prize_number(0, 0, 0, 30, cache);
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM191_H