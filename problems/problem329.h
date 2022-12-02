//
// Created by Pratim Chowdhary on 12/02/22.
//

#ifndef PROJECT_EULER_PROBLEM329_H
#define PROJECT_EULER_PROBLEM329_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

long cache[15][501] = {0};

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int N(int step, int i, string &pattern) {
    if (is_prime(step))
        return pattern[i] == 'P' ? 2 : 1;
    return pattern[i] == 'P' ? 1 : 2;
}

long get_numerator(int step, int i, string &pattern, int max_depth) {
    int p = N(step, i, pattern);
    if (i == max_depth)
        return p;
    if (cache[i][step] != 0)
        return cache[i][step];
    if (step == 1) {
        p = p * 2 * get_numerator(step + 1, i + 1, pattern, max_depth);
    } else if (step == 500) {
        p = p * 2 * get_numerator(step - 1, i + 1, pattern, max_depth);
    } else {
        p = p * (get_numerator(step - 1, i + 1, pattern, max_depth) + get_numerator(step + 1, i + 1, pattern, max_depth));
    }
    cache[i][step] = p;
    return p;
}

void problem_329_solution(bool log) {
    string pattern = "PPPPNNPPPNPPNPN";
    long numerator = 0;
    long demoninator = pow(2, pattern.length() - 1) * pow(3, pattern.length()) * 500;
    for (int i = 1; i <= 500; i++) {
        numerator += get_numerator(i, 0, pattern, 14);
    }
    long g = gcd(numerator, demoninator);
    numerator /= g;
    demoninator /= g;
    if (log) cout << numerator << "/" << demoninator << endl;
}

#endif //PROJECT_EULER_PROBLEM329_H

