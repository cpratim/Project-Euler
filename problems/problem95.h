//
// Created by Pratim, Sonia, Karun on 5/12/22.
//

#ifndef PROJECT_EULER_PROBLEM95_H
#define PROJECT_EULER_PROBLEM95_H

#include "unordered_set"
#include "unordered_map"
#include "vector"

#include "../include/prime_lib.h"
#include "../include/print_lib.h"

using namespace std;

void generate_factor_map(unordered_map<int, unordered_set<int>>& factor_map,
                         unordered_map<int, int>& factor_sum_map,
                         unordered_set<int>& prime_set,
                         vector<int>& primes,
                         int N) {
    for (int n = 2; n < N; n++) {
        if (prime_set.contains(n)) {
            factor_map[n] = unordered_set<int> {1, n};
            factor_sum_map[n] = 1;
        } else {
            int index = 0;
            while (n % primes[index] != 0) {
                index++;
            }
            int prime_factor = primes[index];
            int last = n / prime_factor;
            if (factor_sum_map[last] == -1) {
                factor_sum_map[n] = -1;
                continue;
            }
            int factor_sum = factor_sum_map[last] + last;
            unordered_set<int> factor_set = factor_map[last];
            for (int factor: factor_map[n / prime_factor]) {
                int new_factor = factor * prime_factor;
                if (not factor_set.contains(new_factor)) {
                    factor_set.insert(new_factor);
                    if (new_factor != n)
                        factor_sum += new_factor;
                    if (factor_sum > N) {
                        factor_sum = -1;
                        break;
                    }
                }
            }
            if (factor_sum > 0) {
                factor_map[n] = factor_set;
            }
            factor_sum_map[n] = factor_sum;
        }
    }
}

int find_chain(int N, unordered_map<int, int>& factor_sum_map, unordered_map<int, int>& chain_map) {
    if (chain_map.contains(N))
        return chain_map[N];
    unordered_map<int, int> index_map;
    int index = 0;
    int n = N;
    index_map[n] = 0;
    n = factor_sum_map[n];
    while (not index_map.contains(n)) {
        if (n == 1 or n == -1) {
            for (auto itr: index_map) {
                chain_map[itr.second] = -1;
                return -1;
            }
        }
        index_map[n] = index;
        n = factor_sum_map[n];
        index ++;
    }
    int chain_length = index - index_map[n];
    for (auto itr: index_map) {
        if (itr.second >= index_map[n])
            chain_map[n] = chain_length;
        else
            chain_map[n] = -1;
    }
    return chain_map[N];
}

void problem_95_solution(bool log) {
    int N = 1000000;
    vector<int> primes = sieve(N);
    unordered_set<int> prime_set (primes.begin(), primes.end());
    unordered_map<int, unordered_set<int>> factor_map;
    unordered_map<int, int> factor_sum_map;
    unordered_map<int, int> chain_map;
    generate_factor_map(factor_map, factor_sum_map, prime_set, primes, N);
    int longest = 0;
    int smallest = 0;
    for (int n = 2; n < N; n++) {
        int chain_length = find_chain(n, factor_sum_map, chain_map);
        if (chain_length > longest) {
            longest = chain_length;
            smallest = n;
        }
    }
    if (log) cout << smallest << endl;
}

#endif //PROJECT_EULER_PROBLEM95_H
