//
// Created by Pratim on 12/11/22
//

#ifndef PROJECT_EULER_PROBLEM172_H
#define PROJECT_EULER_PROBLEM172_H

#include "iostream"
#include "vector"
#include "unordered_map"
#include "../include/prime_lib.h"

using namespace std;

long number_combinations(int i, long p, int length, int R[10], unordered_map<long, long> &cache, vector<int> &primes) {
    if (i == length)
        return 1;
    if (cache.find(p) != cache.end())
        return cache[p];
    long sum = 0;
    for (int j = 0; j < 10; j++) {
        if (R[j] == 0 || (i == 0 && j == 0))
            continue;
        R[j]--;
        sum += number_combinations(i+1, p * primes[j], length, R, cache, primes);
        R[j]++;
    }
    cache[p] = sum;
    return sum;
}

void problem_172_solution(bool log) {
    int N = 18;
    int R[10] = {0};
    for (int i = 0; i < 10; i++)
        R[i] = 3;
    unordered_map<long, long> cache;
    vector<int> primes = sieve(100);
    long sum = number_combinations(0, 1, N, R, cache, primes);
    if (log) cout << sum << endl;
}


#endif //PROJECT_EULER_PROBLEM172_H