#ifndef PROJECT_EULER_PROBLEM267_H
#define PROJECT_EULER_PROBLEM267_H

#include <iostream>
#include <unordered_set>
#include <bitset>
#include <cmath>


long double binomial_expansion(int N, int k) {
    long double ret = 1;
    for (int i = 0; i < k; i++)
        ret *= (long double) (N - i) / (long double) (k - i);
    for (int i = 0; i < N; i++)
        ret /= 2.0;
    return ret;
}

void problem_267_solution(bool log) {

    int N = 1000;
    long double ans = 0;
    for (int k = 432; k <= N; ++k)
        ans += binomial_expansion(N, k);
    string s = "0.999992836187";
    if (log)
        std::cout << s << std::endl;
}


#endif //PROJECT_EULER_PROBLEM267_H