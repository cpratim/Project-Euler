//
// Created by Pratim on 12/11/22
//

#ifndef PROJECT_EULER_PROBLEM164_H
#define PROJECT_EULER_PROBLEM164_H

#include "iostream"

using namespace std;


long combinations(int i, int one, int two, int length, long cache[20][10][10]) {
    if (i == length) 
        return 1;
    if (cache[i][one][two] != 0)
        return cache[i][one][two];
    int range = 10 - one - two;
    long sum = 0;
    for (int j = 0; j < range; j++) {
        if (i == 0 && j == 0)
            continue;
        sum += combinations(i+1, two, j, length, cache);
    }
    cache[i][one][two] = sum;
    return sum;
}

void problem_164_solution(bool log) {
    int N = 20;
    long cache[20][10][10] = {0};
    long sum = combinations(0, 0, 0, N, cache);
    if (log) cout << sum << endl;
}


#endif //PROJECT_EULER_PROBLEM164_H