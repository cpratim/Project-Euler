//
// Created by Pratim Chowdhary on 12/02/22.
//

#ifndef PROJECT_EULER_PROBLEM469_H
#define PROJECT_EULER_PROBLEM469_H

using namespace std;

double cache469[10000] = {0};

double solve(int n) {
    if (cache469[n] != 0) {
        return cache469[n];
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 1;
    }
    double sum = 0;
    for (int i = 2; i < n - 1; i++) {
        sum += solve(i) + solve(n - i);
    }
    sum = sum / (n - 3);
    cache469[n] = sum;
    return sum;
}

void problem_469_solution(bool log) {
    int n = 100;
    double sum = solve(n);
    double result = 1 - (sum / n);
    if (log) cout << setprecision(14) << result << endl;
}


#endif //PROJECT_EULER_PROBLEM469_H