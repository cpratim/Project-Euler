//
// Created by Pratim Chowdhary on 11/18/22.
//

#ifndef PROJECT_EULER_PROBLEM204_H
#define PROJECT_EULER_PROBLEM204_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

void solve(long n, int k, int i, vector<int> &primes, unordered_set<long> &seen) {
    if (n > k)
        return;
    seen.insert(n);
    for (int j = i; j < primes.size(); j++) {
        if (n * primes[j] > k)
            break;
        if (!seen.contains(n * primes[j]))
            solve(n * primes[j], k, j, primes, seen);
    }
}

void problem_204_solution(bool log) {
    vector<int> primes;
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) primes.push_back(i);
    }
    unordered_set<long> seen;
    long k = pow(10, 9);
    solve(1, k, 0, primes, seen);
    if (log) cout << seen.size() << endl;
}

#endif //PROJECT_EULER_PROBLEM204_H
