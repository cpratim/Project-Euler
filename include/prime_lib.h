//
// Created by pratim on 4/14/22.
//

#ifndef CEULER_PRIME_LIB_H
#define CEULER_PRIME_LIB_H
#include "cmath"

bool is_prime(int n) {
    if (n == 1 || n == 2) {
        return false;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i < floor(sqrt(n)) + 1; i=i+2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int* generate_primes(int n) {
    static int primes[10];
    return primes;
}

#endif //CEULER_PRIME_LIB_H
