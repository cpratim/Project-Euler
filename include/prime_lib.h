//
// Created by pratim on 4/14/22.
//

#ifndef CEULER_PRIME_LIB_H
#define CEULER_PRIME_LIB_H

#include "cmath"
#include "vector"

using namespace std;

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
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

bool is_prime_long(long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long i = 3; i < floor(sqrt(n)) + 1; i=i+2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_prime_cache(long n, unordered_map<long, bool> &prime_map) {
    if (prime_map.find(n) != prime_map.end()) {
        return prime_map[n];
    }
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            prime_map[n] = false;
            return false;
        }
    }
    prime_map[n] = true;
    return true;
}

vector<int> sieve(int N)
{
    vector<int> primes;
    vector<long> isprime (N, true);
    vector<long> SPF (N);

    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            SPF[i] = i;
        }

        for (long int j = 0;
             j < primes.size() &&
             i*primes[j] < N && primes[j] <= SPF[i];
             j++)
        {
            isprime[i*primes[j]]=false;
            SPF[i*primes[j]] = primes[j] ;
        }
    }
    return primes;
}

#endif //CEULER_PRIME_LIB_H
