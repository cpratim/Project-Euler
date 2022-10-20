//
// Created by Alice Chen on 8/9/22.
//

#ifndef PROJECT_EULER_PROBLEM6_H
#define PROJECT_EULER_PROBLEM6_H


void problem_6_solution(bool log) {
    long sumsq = 0;
    long sqsum = 0;

    for (int i = 1; i <= 100; i++) {
        sumsq += i*i;
        sqsum += i;
    }
    long result = (sqsum*sqsum) - sumsq;

    if (log) cout << result << endl;
}

#endif //PROJECT_EULER_PROBLEM6_H
