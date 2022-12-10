//
// Created by Pratim Chowdhary on 11/19/22.
//

#ifndef PROJECT_EULER_PROBLEM111_H
#define PROJECT_EULER_PROBLEM111_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../include/prime_lib.h"

using namespace std;

void generate_combinations(int i, int n, string c, int l, unordered_map<int, vector<string>> &combination_map) {
    if (i == l) {
        if (combination_map.find(n) == combination_map.end()) {
            combination_map[n] = vector<string>();
        }
        combination_map[n].push_back(c);
        return;
    }
    generate_combinations(i + 1, n, c + "0", l, combination_map);
    generate_combinations(i + 1, n + 1, c + "1", l, combination_map);
}

long S(int i, string s, char d, string pattern, string digits) {
    if (i == pattern.length()) {
        long n = stol(s);
        if (is_prime_long(n))
            return n;
        return 0;
    }
    long sum = 0;
    if (pattern[i] == '0') {
        for (char c : digits) {
            if (i == 0 && c == '0') continue;
            sum += S(i + 1, s + c, d, pattern, digits);
        }
    } else {
        sum += S(i + 1, s + d, d, pattern, digits);
    }
    return sum;
}

void problem_111_solution(bool log) {
    int N = 10;
    unordered_map<int, vector<string>> combination_map;
    generate_combinations(0, 0, "", N, combination_map);
    string digits = "0123456789";
    long total = 0;
    
    for (char d: digits) {
        long sum = 0;
        for (int i = 10; i >= 0; i--) {
            if (sum > 0) break;
            for (string pattern: combination_map[i]) {
                if (pattern[0] == '1' && d == '0') continue;
                sum += S(0, "", d, pattern, digits);
            }
        }
        total += sum;
    }
    if (log) cout << total << endl;
}


#endif //PROJECT_EULER_PROBLEM111_H