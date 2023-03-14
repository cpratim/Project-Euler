//
// Created by Pratim Chowdhary on 02/10/23.
//

#ifndef PROJECT_EULER_PROBLEM205_H
#define PROJECT_EULER_PROBLEM205_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

long multinomial_coefficient(int n, std::vector<int> &k) {
    long result = factorial(n);
    for (auto i : k) {
        result /= factorial(i);
    }
    return result;
}

void generate_rolls(int i, int n, int s, int l, vector<int> &roll, unordered_map<int, double> & dist) {
    if (i == n) {
        int sum = 0;
        for (int j = 1; j <= s; j++) {
            sum += j * roll[j];
        }
        dist[sum] += multinomial_coefficient(n, roll) * (1.0 / pow(s, n));
        return;
    }
    for (int j = l; j <= s; j++) {
        roll[j]++;
        generate_rolls(i + 1, n, s, j, roll, dist);
        roll[j]--;
    }
}

void problem_205_solution(bool log) {
    unordered_map<int, double> peter_dist;
    unordered_map<int, double> colin_dist;
    vector<int> roll(7, 0);
    generate_rolls(0, 9, 4, 1, roll, peter_dist);
    roll = vector<int>(7, 0);
    generate_rolls(0, 6, 6, 1, roll, colin_dist);
    double peter_prob = 0;
    for (auto i : peter_dist) {
        for (auto j : colin_dist) {
            if (i.first > j.first) {
                peter_prob += i.second * j.second;
            }
        }
    }
    if (log) cout << "Problem 205 Solution: " << peter_prob << endl;
}

#endif //PROJECT_EULER_PROBLEM205_H
