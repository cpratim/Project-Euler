//
// Pratim Chowdhary on 12/04/22.
//

#ifndef PROJECT_EULER_PROBLEM121_H
#define PROJECT_EULER_PROBLEM121_H

#include <iostream>

using namespace std;

double choose(int i, int n, int k, double p, vector<double> &P) {
    double sum = 0;
    if (k == 0)
        return p;
    for (int j = i; j < n; j++) {
        p /= P[j];
        p *= (1 - P[j]);
        sum += choose(j + 1, n, k - 1, p, P);
        p /= (1 - P[j]);
        p *= P[j];
    }
    return sum;
}


void problem_121_solution(bool log) {
    int n = 15;
    vector<double> P;
    double steady = 1;
    for (int i = 1; i <= n; i++) {
        P.push_back(1.0 / (i + 1));
        steady *= P[i - 1];
    }
    double sum = 0;
    int bound = n / 2;
    if (n % 2 != 0)
        bound++;
    for (int i = 0; i < bound; i++) {
        sum += choose(0, n, i, steady, P);
    }
    int E = floor(1 / sum);
    if (log) cout << E << endl;
}


#endif //PROJECT_EULER_PROBLEM121_H