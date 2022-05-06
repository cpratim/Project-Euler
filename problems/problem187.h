//
// Created by Karun Ram, Pratim Chowdhary on 5/2/22.
//

#ifndef PROJECT_EULER_PROBLEM187_H
#define PROJECT_EULER_PROBLEM187_H

#include <iostream>
#include <vector>
#include <cmath>

std::vector<long> gen_primes(int n) {
    std::vector<long> primes;
    std::vector<bool> is_prime(n+1, true);
    for (long i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

void problem_187_solution(bool log) {
    long n = 100000000;
    std::vector<long> primes = gen_primes(n);
    std::vector<long> primes2 = gen_primes((int)std::sqrt(n));
    long ct = 0;
    for (int i = 0; i < primes2.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            long k = primes2[i]*primes[j];
            if (k < n) {
                ct += 1;
            } else {
                break;
            }
        }
    }
    if (log) std::cout << ct << std::endl;
}

#endif //PROJECT_EULER_PROBLEM187_H
