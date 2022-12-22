//
// Created by Jason Guo, Pratim Chowdhary on 12/20/22.
//

#ifndef PROJECT_EULER_PROBLEM188_H
#define PROJECT_EULER_PROBLEM188_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> base_2_convert(int n) {
    vector<int> base2;
    int i = 0;
    while (n > 0) {
        base2.push_back((n % 2) * pow(2, i));
        n /= 2;
        i++;
    }
    return base2;
}

long mod_exp(long base, long exp, long mod, unordered_map<long, long> & cache) {
    if (cache.find(exp) != cache.end()) return cache[exp];
    cache[exp] = 1;
    for (int i = 0; i < exp; i++) {
        cache[exp] = (cache[exp] * base) % mod;
    }
    return cache[exp];
}

long hyperexponentiate(long a, long b, long mod, unordered_map<long, long> & cache) {
    if (b == 1) return a;
    long exp = hyperexponentiate(a, b - 1, mod, cache);
    long power = 1;
    for (int n: base_2_convert(exp)) {
        if (n == 0) continue;
        power *= mod_exp(a, n, mod, cache);
        power %= mod;
    }
    return power;
}

void problem_188_solution(bool log) {
    long mod = 100000000;
    long base = 1777;
    long exp = 1855;
    unordered_map<long, long> cache;
    long long digits = hyperexponentiate(base, exp, mod, cache);
    if (log) cout << digits << endl;
} 

#endif //PROJECT_EULER_PROBLEM188_H